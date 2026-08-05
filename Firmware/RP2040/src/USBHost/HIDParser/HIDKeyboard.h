// Firmware/RP2040/src/USBHost/HIDParser/HIDKeyboard.h
#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "USBHost/HIDParser/HIDReportDescriptor.h"

class HIDKeyboardData {
public:
    uint8_t modifiers = 0;     // modifier bitmap (shift/ctrl/alt/gui) following boot bit mapping
    uint8_t key_count = 0;     // number of non-zero keycodes
    uint8_t keys[6] = {0};     // up to 6 boot keycodes or truncated set from descriptor-driven parsing
};

class HIDKeyboard {
public:
    HIDKeyboard(const std::shared_ptr<HIDReportDescriptor>& descriptor);
    ~HIDKeyboard();

    // True if descriptor suggests keyboard usage (best-effort)
    bool isValid() const;

    // Parse a report into HIDKeyboardData
    // - Supports boot reports (8-byte boot protocol)
    // - Supports descriptor-driven parsing using HIDReportDescriptor (NKRO bitfields, report-id prefixed reports, usage arrays)
    bool parseData(uint8_t* report, uint16_t len, HIDKeyboardData* out_data);

private:
    bool supports_keyboard_;

    // store descriptor reports so they outlive temporary returns from GetReports()
    std::vector<HIDIOReport> m_reports;

    // helper implementations used by parseData
    bool parse_boot_report(uint8_t* report, uint16_t len, HIDKeyboardData* out_data);
    bool parse_descriptor_report(uint8_t* report, uint16_t len, HIDKeyboardData* out_data);
};
