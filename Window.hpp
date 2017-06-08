#pragma once

#include <windows.h>

class Size;

class Window {
public:
    Window(HINSTANCE);

    HWND getHWnd() const noexcept;
    Size getSize() const;

    void display() noexcept;
    void makeFullScreen();

private:
    HWND m_hWnd;
    bool m_isFullScreen;

    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM) noexcept;
};
