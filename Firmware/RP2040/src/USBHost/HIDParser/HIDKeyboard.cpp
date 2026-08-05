// Firmware/RP2040/src/USBHost/HIDParser/HIDKeyboard.cpp
#include "HIDKeyboard.h"
#include <cstring>

HIDKeyboard::HIDKeyboard(const std::shared_ptr<HIDReportDescriptor>& descriptor)
    : supports_keyboard_(false)
{
    if (descriptor) {
        // store descriptor reports locally so they outlive the temporary returned vector
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

// Boot keyboard format (8 bytes): [0]=modifiers, [1]=reserved, [2..7]=6 key usage IDs
bool HIDKeyboard::parse_boot_report(uint8_t* report, uint16_t len, HIDKeyboardData* out_data)
{
    if (!report || !out_data) return false;
    if (len < 8) return false;

    out_data->modifiers = report[0];
    out_data->key_count = 0;
    std::memset(out_data->keys, 0, sizeof(out_data->keys));
    for (uint8_t i = 2; i < 8 && out_data->key_count < 6; ++i) {
        uint8_t kc = report[i];
        if (kc != 0) out_data->keys[out_data->key_count++] = kc;
    }
    return true;
}

// Descriptor-driven parsing is currently not implemented. Return false to indicate unsupported.
bool HIDKeyboard::parse_descriptor_report(uint8_t* /*report*/, uint16_t /*len*/, HIDKeyboardData* /*out_data*/)
{
    // TODO: implement descriptor-driven (NKRO, usage arrays, bitfields) parsing using m_reports
    return false;
}

bool HIDKeyboard::parseData(uint8_t* report, uint16_t len, HIDKeyboardData* out_data)
{
    if (!report || !out_data) return false;

    // Try boot report parsing first
    if (parse_boot_report(report, len, out_data)) return true;

    // Fallback to descriptor-driven parsing (not implemented yet)
    if (parse_descriptor_report(report, len, out_data)) return true;

    return false;
}
