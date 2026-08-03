// Firmware/RP2040/src/Descriptors/Keyboard.h
#ifndef _KEYBOARD_DESCRIPTORS_H_
#define _KEYBOARD_DESCRIPTORS_H_

//https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2#file-usb_hid_keys-h

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
	static constexpr uint8_t KEY_F3 = 0x3c // Keyboard F3
	static constexpr uint8_t KEY_F4 = 0x3d // Keyboard F4
	static constexpr uint8_t KEY_F5 = 0x3e // Keyboard F5
	static constexpr uint8_t KEY_F6 = 0x3f // Keyboard F6
	static constexpr uint8_t KEY_F7 = 0x40 // Keyboard F7
	static constexpr uint8_t KEY_F8 = 0x41 // Keyboard F8
	static constexpr uint8_t KEY_F9 = 0x42 // Keyboard F9
	static constexpr uint8_t KEY_F10 = 0x43 // Keyboard F10
	static constexpr uint8_t KEY_F11 = 0x44 // Keyboard F11
	static constexpr uint8_t KEY_F12 = 0x45 // Keyboard F12

	static constexpr uint8_t KEY_SYSRQ = 0x46 // Keyboard Print Screen
	static constexpr uint8_t KEY_SCROLLLOCK = 0x47 // Keyboard Scroll Lock
	static constexpr uint8_t KEY_PAUSE = 0x48 // Keyboard Pause
	static constexpr uint8_t KEY_INSERT = 0x49 // Keyboard Insert
	static constexpr uint8_t KEY_HOME = 0x4a // Keyboard Home
	static constexpr uint8_t KEY_PAGEUP = 0x4b // Keyboard Page Up
	static constexpr uint8_t KEY_DELETE = 0x4c // Keyboard Delete Forward
	static constexpr uint8_t KEY_END = 0x4d // Keyboard End
	static constexpr uint8_t KEY_PAGEDOWN = 0x4e // Keyboard Page Down
	static constexpr uint8_t KEY_RIGHT = 0x4f // Keyboard Right Arrow
	static constexpr uint8_t KEY_LEFT = 0x50 // Keyboard Left Arrow
	static constexpr uint8_t KEY_DOWN = 0x51 // Keyboard Down Arrow
	static constexpr uint8_t KEY_UP = 0x52 // Keyboard Up Arrow

	static constexpr uint8_t KEY_NUMLOCK = 0x53 // Keyboard Num Lock and Clear
	static constexpr uint8_t KEY_KPSLASH = 0x54 // Keypad /
	static constexpr uint8_t KEY_KPASTERISK = 0x55 // Keypad *
	static constexpr uint8_t KEY_KPMINUS = 0x56 // Keypad -
	static constexpr uint8_t KEY_KPPLUS = 0x57 // Keypad +
	static constexpr uint8_t KEY_KPENTER = 0x58 // Keypad ENTER
	static constexpr uint8_t KEY_KP1 = 0x59 // Keypad 1 and End
	static constexpr uint8_t KEY_KP2 = 0x5a // Keypad 2 and Down Arrow
	static constexpr uint8_t KEY_KP3 = 0x5b // Keypad 3 and PageDn
	static constexpr uint8_t KEY_KP4 = 0x5c // Keypad 4 and Left Arrow
	static constexpr uint8_t KEY_KP5 = 0x5d // Keypad 5
	static constexpr uint8_t KEY_KP6 = 0x5e // Keypad 6 and Right Arrow
	static constexpr uint8_t KEY_KP7 = 0x5f // Keypad 7 and Home
	static constexpr uint8_t KEY_KP8 = 0x60 // Keypad 8 and Up Arrow
	static constexpr uint8_t KEY_KP9 = 0x61 // Keypad 9 and Page Up
	static constexpr uint8_t KEY_KP0 = 0x62 // Keypad 0 and Insert
	static constexpr uint8_t KEY_KPDOT = 0x63 // Keypad . and Delete

	static constexpr uint8_t KEY_102ND = 0x64 // Keyboard Non-US \ and |
	static constexpr uint8_t KEY_COMPOSE = 0x65 // Keyboard Application
	static constexpr uint8_t KEY_POWER = 0x66 // Keyboard Power
	static constexpr uint8_t KEY_KPEQUAL = 0x67 // Keypad =

	static constexpr uint8_t KEY_F13 = 0x68 // Keyboard F13
	static constexpr uint8_t KEY_F14 = 0x69 // Keyboard F14
	static constexpr uint8_t KEY_F15 = 0x6a // Keyboard F15
	static constexpr uint8_t KEY_F16 = 0x6b // Keyboard F16
	static constexpr uint8_t KEY_F17 = 0x6c // Keyboard F17
	static constexpr uint8_t KEY_F18 = 0x6d // Keyboard F18
	static constexpr uint8_t KEY_F19 = 0x6e // Keyboard F19
	static constexpr uint8_t KEY_F20 = 0x6f // Keyboard F20
	static constexpr uint8_t KEY_F21 = 0x70 // Keyboard F21
	static constexpr uint8_t KEY_F22 = 0x71 // Keyboard F22
	static constexpr uint8_t KEY_F23 = 0x72 // Keyboard F23
	static constexpr uint8_t KEY_F24 = 0x73 // Keyboard F24

	static constexpr uint8_t KEY_OPEN = 0x74 // Keyboard Execute
	static constexpr uint8_t KEY_HELP = 0x75 // Keyboard Help
	static constexpr uint8_t KEY_PROPS = 0x76 // Keyboard Menu
	static constexpr uint8_t KEY_FRONT = 0x77 // Keyboard Select
	static constexpr uint8_t KEY_STOP = 0x78 // Keyboard Stop
	static constexpr uint8_t KEY_AGAIN = 0x79 // Keyboard Again
	static constexpr uint8_t KEY_UNDO = 0x7a // Keyboard Undo
	static constexpr uint8_t KEY_CUT = 0x7b // Keyboard Cut
	static constexpr uint8_t KEY_COPY = 0x7c // Keyboard Copy
	static constexpr uint8_t KEY_PASTE = 0x7d // Keyboard Paste
	static constexpr uint8_t KEY_FIND = 0x7e // Keyboard Find
	static constexpr uint8_t KEY_MUTE = 0x7f // Keyboard Mute
	static constexpr uint8_t KEY_VOLUMEUP = 0x80 // Keyboard Volume Up
	static constexpr uint8_t KEY_VOLUMEDOWN = 0x81 // Keyboard Volume Down
    


    // ... add more usages as needed
};

#endif // _KEYBOARD_DESCRIPTORS_H_
