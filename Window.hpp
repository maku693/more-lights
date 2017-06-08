#pragma once

#include <windows.h>

class Size;

class Window {
public:
    Window(HINSTANCE);

    HWND getHWnd() const noexcept;
    Size getSize() const;

    void display() const noexcept;

private:
    HWND m_hWnd;

    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM) noexcept;
};
