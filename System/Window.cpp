#include "window.hpp"

#include <codecvt>
#include <stdexcept>

#include "Util/Size.hpp"

namespace System {

Window::Window(HINSTANCE hInstance)
    : m_isFullScreen(false)
{
    WNDCLASSW wndClass{};
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = reinterpret_cast<WNDPROC>(Window::WndProc);
    wndClass.hInstance = hInstance;
    wndClass.hCursor = LoadCursorW(hInstance, IDC_ARROW);
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

Util::Size Window::getSize() const
{
    RECT r;
    if (GetWindowRect(this->m_hWnd, &r)) {
        throw std::runtime_error("Can't get window rect");
    }

    return Util::Size{ static_cast<float>(r.right - r.left),
        static_cast<float>(r.bottom - r.top) };
}

void Window::setTitle(const std::string& title) noexcept
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
    std::wstring widened = convert.from_bytes(title.data());
    SetWindowText(this->m_hWnd, widened.data());
}

void Window::display() noexcept { ShowWindow(this->m_hWnd, SW_SHOWDEFAULT); }

void Window::makeFullScreen()
{
    if (this->m_isFullScreen) {
        return;
    }

    auto hMonitor = MonitorFromWindow(nullptr, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFO monitorInfo = {};
    monitorInfo.cbSize = sizeof(MONITORINFO);

    if (!GetMonitorInfoW(hMonitor, &monitorInfo)) {
        throw std::runtime_error("Can't get monitor information");
    }

    SetWindowLongPtrW(this->m_hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);

    const RECT& r = monitorInfo.rcMonitor;
    if (!SetWindowPos(
            this->m_hWnd, HWND_TOP, r.left, r.top, r.right, r.bottom, 0)) {
        throw std::runtime_error("Can't set window position");
    }

    this->m_isFullScreen = true;
}

LRESULT CALLBACK Window::WndProc(
    HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) noexcept
{
    // TODO: handle window messages and translate to app-local messages
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

} // namespace System
