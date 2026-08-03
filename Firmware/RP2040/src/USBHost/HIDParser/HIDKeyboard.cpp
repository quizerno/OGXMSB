// Firmware/RP2040/src/USBHost/HIDParser/HIDKeyboard.cpp
#include "HIDKeyboard.h"
#include <cstring>

HIDKeyboard::HIDKeyboard(const std::shared_ptr<HIDReportDescriptor>& descriptor)
    : supports_keyboard_(false)
{
    if (descriptor) {
        for (const auto &r : descriptor->GetReports()) {
            if (r.report_type == HIDIOReportType::Keyboard) {
                supports_keyboard_ = true;
                break;
            }
        }
    }
}

HIDKeyboard::~HIDKeyboard() {}

bool HIDKeyboard::isValid() const { return supports_keyboard_; }

bool HIDKeyboard::parseData(uint8_t* report, uint16_t len, HIDKeyboardData* out_data)
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