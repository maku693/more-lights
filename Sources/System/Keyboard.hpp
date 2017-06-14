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

KeyCode translateVKeyToKeyCode(USHORT vKey)
{
    switch (vKey) {
    case VK_ESCAPE:
        return KeyCode::Esc;
    case VK_SPACE:
        return KeyCode::Space;
    case 0x41:
        return KeyCode::A;
    case 0x44:
        return KeyCode::D;
    case 0x53:
        return KeyCode::S;
    case 0x57:
        return KeyCode::W;
    default:
        return KeyCode::Undefined;
    }
}

KeyState translateMessageToKeyState(UINT message)
{
    switch (message) {
    case WM_KEYDOWN:
        return KeyState::Down;
    case WM_KEYUP:
        return KeyState::Up;
    default:
        return KeyState::Undefined;
    }
}

} // namespace System
