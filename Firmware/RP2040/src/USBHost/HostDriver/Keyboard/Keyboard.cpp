#include <cstring>
#include <array>
#include <memory>

#include "USBHost/HostDriver/Keyboard/Keyboard.h"
#include "USBHost/HIDParser/HIDKeyboard.h"
#include "Gamepad/Gamepad.h"
#include "Descriptors/Keyboard.h"
//#include "tuh.h"
#include "host/usbh.h"
#include "class/hid/hid_host.h"

static std::array<uint8_t, 0x40> prev_report_in_{0};

static inline void map_keycode_to_gamepad(uint8_t keycode, Gamepad& gamepad, Gamepad::PadIn &gp_in)
{
    // USB HID keyboard usage IDs: 0x04 = 'a', 0x05 = 'b', ... 0x1A = 'w', 0x1B = 'x', 0x1C = 'y', 0x1D = 'z'
    // Arrow key usages commonly: 0x4F=Right, 0x50=Left, 0x51=Down, 0x52=Up (validate for your keyboard if needed)
    switch (keycode)
    {
        // WASD
        case 0x1A: // w
            gp_in.dpad |= gamepad.MAP_DPAD_UP;
            break;
        case 0x16: // s
            gp_in.dpad |= gamepad.MAP_DPAD_DOWN;
            break;
        case 0x04: // a  (note: 0x04 is 'a')
            gp_in.dpad |= gamepad.MAP_DPAD_LEFT;
            break;
        case 0x07: // d  (0x07 is 'd')
            gp_in.dpad |= gamepad.MAP_DPAD_RIGHT;
            break;

        // Arrow keys (common usages)
        case 0x4F: // Right Arrow
            gp_in.dpad |= gamepad.MAP_DPAD_RIGHT;
            break;
        case 0x50: // Left Arrow
            gp_in.dpad |= gamepad.MAP_DPAD_LEFT;
            break;
        case 0x51: // Down Arrow
            gp_in.dpad |= gamepad.MAP_DPAD_DOWN;
            break;
        case 0x52: // Up Arrow
            gp_in.dpad |= gamepad.MAP_DPAD_UP;
            break;

        // Buttons / actions
        case 0x2C: // Space -> A
            gp_in.buttons |= gamepad.MAP_BUTTON_A;
            break;
        case 0x29: // Escape -> BACK
            gp_in.buttons |= gamepad.MAP_BUTTON_BACK;
            break;
        case 0x28: // Enter -> START
            gp_in.buttons |= gamepad.MAP_BUTTON_START;
            break;

        // A few letter mappings for face buttons (tweak to taste)
        case 0x1B: // x
            gp_in.buttons |= gamepad.MAP_BUTTON_B;
            break;
        case 0x1D: // z
            gp_in.buttons |= gamepad.MAP_BUTTON_X;
            break;
        case 0x1C: // y
            gp_in.buttons |= gamepad.MAP_BUTTON_Y;
            break;

        // Modifiers could map to shoulder buttons if you want:
        default:
            break;
    }
}



void KeyboardHost::process_report(Gamepad& gamepad, uint8_t address, uint8_t instance, const uint8_t* report, uint16_t len)
{
    if (!report || len == 0) {
        tuh_hid_receive_report(address, instance);
        return;
    }

    if (std::memcmp(prev_report_in_.data(), report, std::min<size_t>(len, prev_report_in_.size())) == 0) {
        tuh_hid_receive_report(address, instance);
        return;
    }
    std::memset(prev_report_in_.data(), 0, prev_report_in_.size());
    std::memcpy(prev_report_in_.data(), report, std::min<size_t>(len, prev_report_in_.size()));

    // Parse boot keyboard layout into raw usage IDs
    HIDKeyboardData kb;
    HIDKeyboard parser(nullptr);
    if (!parser.parseData(const_cast<uint8_t*>(report), len, &kb)) {
        tuh_hid_receive_report(address, instance);
        return;
    }

    // Prepare ChatpadIn as raw keycodes container (reuse the existing chatpad slot)
    Gamepad::ChatpadIn chatpad = {0, 0, 0};

    // Optionally encode modifiers into chatpad[0] bits (if desired)
    // For now we keep chatpad[0] = 0 and store raw usage IDs in chatpad[1], chatpad[2]
    if (kb.key_count > 0) chatpad[1] = kb.keys[0];
    if (kb.key_count > 1) chatpad[2] = kb.keys[1];

    // If you want to preserve more keys, choose a strategy: rotation, queue, or compact into multiple reports.

    // Store raw usage IDs in gamepad structure
    gamepad.set_chatpad_in(chatpad);

    tuh_hid_receive_report(address, instance);
}