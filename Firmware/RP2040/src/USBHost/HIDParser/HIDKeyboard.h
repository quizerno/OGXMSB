//added

// Firmware/RP2040/src/USBHost/HIDParser/HIDKeyboard.h
#pragma once
#include <cstdint>
#include <memory>
#include "USBHost/HIDParser/HIDReportDescriptor.h"

class HIDKeyboardData {
public:
    uint8_t modifiers = 0;     // modifier bitmap (shift/ctrl/alt/gui)
    uint8_t key_count = 0;     // number of non-zero keycodes
    uint8_t keys[6] = {0};     // up to 6 boot keycodes (HID usage IDs)
};

class HIDKeyboard {
public:
    HIDKeyboard(const std::shared_ptr<HIDReportDescriptor>& descriptor);
    ~HIDKeyboard();

    // True if descriptor suggests keyboard usage (best-effort)
    bool isValid() const;

    // Parse a report into HIDKeyboardData (returns true for boot-like reports)
    bool parseData(uint8_t* report, uint16_t len, HIDKeyboardData* out_data);

private:
    bool supports_keyboard_;
};