#pragma once

#include <windows.h>

#include <string>

namespace Util {

class Size;

} // namespace Util

namespace System {

class Window {
public:
    Window(HINSTANCE);

    HWND getHWnd() const noexcept;
    Util::Size getSize() const;

    void setTitle(const std::string&) noexcept;

    void display() noexcept;
    void makeFullScreen();

private:
    HWND m_hWnd;
    bool m_isFullScreen;

    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM) noexcept;
};

} // namespace System
