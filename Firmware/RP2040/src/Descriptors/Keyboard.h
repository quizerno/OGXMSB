// Firmware/RP2040/src/Descriptors/Keyboard.h
#ifndef _KEYBOARD_DESCRIPTORS_H_
#define _KEYBOARD_DESCRIPTORS_H_

#include <cstdint>

namespace Keyboard
{
    // HID Usage IDs (USB HID Usage Table: 0x04='a' ... 0x1D='z', 0x1E..0x27 digits)
    static constexpr uint8_t KEY_A = 0x04;
    static constexpr uint8_t KEY_B = 0x05;
    static constexpr uint8_t KEY_C = 0x06;
    static constexpr uint8_t KEY_D = 0x07;
    static constexpr uint8_t KEY_E = 0x08;
    static constexpr uint8_t KEY_F = 0x09;
    static constexpr uint8_t KEY_G = 0x0A;
    static constexpr uint8_t KEY_H = 0x0B;
    static constexpr uint8_t KEY_I = 0x0C;
    static constexpr uint8_t KEY_J = 0x0D;
    static constexpr uint8_t KEY_K = 0x0E;
    static constexpr uint8_t KEY_L = 0x0F;
    static constexpr uint8_t KEY_M = 0x10;
    static constexpr uint8_t KEY_N = 0x11;
    static constexpr uint8_t KEY_O = 0x12;
    static constexpr uint8_t KEY_P = 0x13;
    static constexpr uint8_t KEY_Q = 0x14;
    static constexpr uint8_t KEY_R = 0x15;
    static constexpr uint8_t KEY_S = 0x16;
    static constexpr uint8_t KEY_T = 0x17;
    static constexpr uint8_t KEY_U = 0x18;
    static constexpr uint8_t KEY_V = 0x19;
    static constexpr uint8_t KEY_W = 0x1A;
    static constexpr uint8_t KEY_X = 0x1B;
    static constexpr uint8_t KEY_Y = 0x1C;
    static constexpr uint8_t KEY_Z = 0x1D;

    static constexpr uint8_t KEY_1 = 0x1E;
    static constexpr uint8_t KEY_2 = 0x1F;
    static constexpr uint8_t KEY_3 = 0x20;
    static constexpr uint8_t KEY_4 = 0x21;
    static constexpr uint8_t KEY_5 = 0x22;
    static constexpr uint8_t KEY_6 = 0x23;
    static constexpr uint8_t KEY_7 = 0x24;
    static constexpr uint8_t KEY_8 = 0x25;
    static constexpr uint8_t KEY_9 = 0x26;
    static constexpr uint8_t KEY_0 = 0x27;

    static constexpr uint8_t KEY_ENTER = 0x28;
    static constexpr uint8_t KEY_ESC = 0x29;
    static constexpr uint8_t KEY_BACKSPACE = 0x2A;
    static constexpr uint8_t KEY_TAB = 0x2B;
    static constexpr uint8_t KEY_SPACE = 0x2C;
    static constexpr uint8_t KEY_MINUS = 0x2D;
    static constexpr uint8_t KEY_EQUAL = 0x2E;
    static constexpr uint8_t KEY_LEFTBRACE = 0x2F;
    static constexpr uint8_t KEY_RIGHTBRACE = 0x30;
    static constexpr uint8_t KEY_BACKSLASH = 0x31;
    static constexpr uint8_t KEY_SEMICOLON = 0x33;
    static constexpr uint8_t KEY_APOSTROPHE = 0x34;
    static constexpr uint8_t KEY_GRAVE = 0x35;
    static constexpr uint8_t KEY_COMMA = 0x36;
    static constexpr uint8_t KEY_DOT = 0x37;
    static constexpr uint8_t KEY_SLASH = 0x38;

    static constexpr uint8_t KEY_CAPSLOCK = 0x39;
    static constexpr uint8_t KEY_F1 = 0x3A;
    static constexpr uint8_t KEY_F2 = 0x3B;
    // ... add more usages as needed
};

#endif // _KEYBOARD_DESCRIPTORS_H_