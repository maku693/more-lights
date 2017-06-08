#include "window.hpp"

#include <stdexcept>

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
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr,
        nullptr, hInstance, nullptr);
}

constexpr HWND Window::getHWnd() const noexcept { return this->m_hWnd; }

void Window::display() const noexcept
{
    ShowWindow(this->m_hWnd, SW_SHOWDEFAULT);
}

LRESULT CALLBACK Window::WndProc(
    HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) noexcept
{
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
