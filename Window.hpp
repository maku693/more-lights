#pragma once

#include <windows.h>

class Window {
public:
    Window(HINSTANCE);

    constexpr HWND getHWnd() const noexcept;

    void display() const noexcept;

private:
    HWND m_hWnd;

    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM) noexcept;
};
