#include "window.hpp"

#include <stdexcept>

#include "Size.hpp"

Window::Window(HINSTANCE hInstance)
{
    WNDCLASSW wndClass{};
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = reinterpret_cast<WNDPROC>(Window::WndProc);
    wndClass.hInstance = hInstance;
    wndClass.hCursor = LoadCursor(hInstance, IDC_ARROW);
    wndClass.hbrBackground
        = reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
    wndClass.lpszClassName = L"Window";

    const auto atom = RegisterClassW(&wndClass);
    if (!atom) {
        throw std::runtime_error("Window class registration failed");
    }

    this->m_hWnd = CreateWindowW(MAKEINTATOM(atom), L"", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 360, nullptr, nullptr, hInstance,
        nullptr);
    if (!this->m_hWnd) {
        throw std::runtime_error("Window creation failed");
    }
}

HWND Window::getHWnd() const noexcept { return this->m_hWnd; }

Size Window::getSize() const
{
    RECT r;
    if (GetWindowRect(this->m_hWnd, &r)) {
        throw std::runtime_error("Can't get window rect");
    }

    return Size{ static_cast<float>(r.right - r.left),
        static_cast<float>(r.bottom - r.top) };
}

void Window::display() noexcept { ShowWindow(this->m_hWnd, SW_SHOWDEFAULT); }

LRESULT CALLBACK Window::WndProc(
    HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) noexcept
{
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
