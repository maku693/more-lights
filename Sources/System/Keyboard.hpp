#pragma once

#include <windows.h>

namespace System {

enum class KeyCode {
    Esc,
    Space,
    A, D, S, W,
    Undefined,
};

enum class KeyState {
    Down, Up,
    Undefined,
};

KeyCode translateVKeyToKeyCode(USHORT);

KeyState translateMessageToKeyState(UINT);

} // namespace System
