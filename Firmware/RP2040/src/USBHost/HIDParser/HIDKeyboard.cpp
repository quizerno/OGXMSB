// Firmware/RP2040/src/USBHost/HIDParser/HIDKeyboard.cpp
#include "HIDKeyboard.h"
#include "USBHost/HIDParser/HIDUtils.h"
#include <cstring>
#include <algorithm>

HIDKeyboard::HIDKeyboard(const std::shared_ptr<HIDReportDescriptor>& descriptor)
    : supports_keyboard_(false)
{
    if (descriptor) {
        m_reports = descriptor->GetReports();
        for (const auto &r : m_reports) {
            if (r.report_type == HIDIOReportType::Keyboard) {
                supports_keyboard_ = true;
                break;
            }
        }
    }
}

HIDKeyboard::~HIDKeyboard() {}

bool HIDKeyboard::isValid() const { return supports_keyboard_; }

bool HIDKeyboard::parse_boot_report(uint8_t* report, uint16_t len, HIDKeyboardData* out_data)
{
    if (!report || !out_data) return false;
    // Boot keyboard format (8 bytes): [0]=modifiers, [1]=reserved, [2..7]=6 key usage IDs
    if (len >= 8) {
        out_data->modifiers = report[0];
        out_data->key_count = 0;
        std::memset(out_data->keys, 0, sizeof(out_data->keys));
        for (uint8_t i = 2; i < 8 && out_data->key_count < 6; ++i) {
            uint8_t kc = report[i];
            if (kc != 0) out_data->keys[out_data->key_count++] = kc;
        }
        return true;
    }
    return false;
}

static inline bool bit_get(const uint8_t* buf, size_t bit_index, size_t buf_len_bytes)
{
    size_t byte_index = bit_index >> 3;
    if (byte_index >= buf_len_bytes) return false;
    uint8_t bit_in_byte = bit_index & 7;
    return (buf[byte_index] >> bit_in_byte) & 1;
}

bool HIDKeyboard::parse_descriptor_report(uint8_t* report, uint16_t len, HIDKeyboardData* out_data)
{
    if (!report || !out_data) return false;

    // For every parsed HIDIOReport that is Keyboard
    for (const auto &rep : m_reports) {
        if (rep.report_type != HIDIOReportType::Keyboard) continue;

        // Each HIDIOReport can contain multiple input blocks (we examine each)
        for (const auto &ioblock : rep.inputs) {
            uint32_t bitOffset = 0;
            bool report_id_ok = true;
            // reset output
            out_data->modifiers = 0;
            out_data->key_count = 0;
            std::memset(out_data->keys, 0, sizeof(out_data->keys));

            // Walk each HIDInputOutput entry in the block sequentially
            for (const auto &input : ioblock.data) {
                if (bitOffset + input.size > (uint32_t)len * 8) {
                    report_id_ok = false; // out of bounds for this report shape
                    break;
                }

                uint32_t value = HIDUtils::readBitsLE(report, bitOffset, input.size);
                bitOffset += input.size;

                if (input.type == HIDIOType::ReportId) {
                    // If report ID is present it must match the incoming data
                    if (value != input.id) {
                        report_id_ok = false;
                        break;
                    }
                    continue;
                }

                if (input.type == HIDIOType::Button) {
                    // Distinguish bitfield (size == 1) vs usage-value fields (size >= 8)
                    if (input.size == 1) {
                        // A single bit representing a single usage (value is 0/1)
                        if (value) {
                            uint32_t usage = input.id;
                            // modifiers typically usages 0xE0..0xE7
                            if (usage >= 0xE0 && usage <= 0xE7) {
                                out_data->modifiers |= (1u << (usage - 0xE0));
                            } else if (out_data->key_count < 6 && usage >= 0x04 && usage <= 0xFF) {
                                out_data->keys[out_data->key_count++] = (uint8_t)usage;
                            }
                        }
                    } else {
                        // This input represents a usage value (or repeated usage element).
                        // input.id is already computed as usage_min + idx
                        // value is not the usage id itself in some descriptors; many descriptors
                        // will use separate usage items, and our parsing transforms usages into inputs
                        // with id = usage value. So treat non-zero value as presence of that usage.
                        if (value != 0) {
                            uint32_t usage = input.id;
                            if (usage >= 0xE0 && usage <= 0xE7) {
                                out_data->modifiers |= (1u << (usage - 0xE0));
                            } else if (out_data->key_count < 6 && usage >= 0x04 && usage <= 0xFF) {
                                out_data->keys[out_data->key_count++] = (uint8_t)usage;
                            }
                        }
                    }
                }
                // padding/other types ignored for keyboard extraction
            } // end for inputs

            if (!report_id_ok) continue;

            // success if we found keys/modifiers
            if (out_data->key_count > 0 || out_data->modifiers != 0) {
                return true;
            }
            // otherwise try next ioblock or report
        }
    }

    return false;
}

bool HIDKeyboard::parseData(uint8_t* report, uint16_t len, HIDKeyboardData* out_data)
{
    if (!report || !out_data) return false;

    // 1) Preferred: descriptor-driven parse
    if (!m_reports.empty()) {
        if (parse_descriptor_report(report, len, out_data)) return true;

        // 1a) Common variant: report ID prefix + boot payload (report[0] = id).
        if (len >= 9 && parse_boot_report(report + 1, len - 1, out_data)) return true;
    }

    // 2) Boot fallback
    if (parse_boot_report(report, len, out_data)) return true;

    // 3) NKRO heuristic: modifiers in byte 0, then contiguous key-bitmask.
    if (len >= 2) {
        out_data->modifiers = report[0];
        out_data->key_count = 0;
        std::memset(out_data->keys, 0, sizeof(out_data->keys));
        size_t bit_start = 8; // after modifiers byte
        size_t total_bits = (size_t)len * 8 - bit_start;
        for (size_t i = 0; i < total_bits && out_data->key_count < 6; ++i) {
            if (bit_get(report, bit_start + i, len)) {
                uint8_t usage = (uint8_t)(0x04 + i);
                out_data->keys[out_data->key_count++] = usage;
            }
        }
        if (out_data->key_count > 0 || out_data->modifiers != 0) return true;
    }

    return false;
}
