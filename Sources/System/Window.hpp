#pragma once

#include <windows.h>

#include <functional>
#include <string>

namespace Util {

class Size;

} // namespace Util

namespace System {

class Window final {
public:
    Window(HINSTANCE);

    HWND getHWnd() const noexcept;
    Util::Size getSize() const;
    bool isVisible() const noexcept;

    void setOnClose(std::function<void()>) noexcept;
    void setTitle(const std::string&) noexcept;

    void display() noexcept;
    void makeFullScreen();

private:
    HWND m_hWnd;
    bool m_isFullScreen;
    std::function<void()> m_onClose;

    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM) noexcept;
};

} // namespace System
