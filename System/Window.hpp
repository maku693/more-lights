#pragma once

#include <windows.h>

namespace Util {

class Size;

} // namespace Util

namespace System {

class Window {
public:
    Window(HINSTANCE);

    HWND getHWnd() const noexcept;
    Util::Size getSize() const;

    void display() noexcept;
    void makeFullScreen();

private:
    HWND m_hWnd;
    bool m_isFullScreen;

    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM) noexcept;
};

} // namespace System
