#include "application.hpp"

#include <windows.h>

#include "System/Window.hpp"

namespace System {

void Application::setWindow(std::shared_ptr<Window> window) noexcept
{
    this->m_window = window;
}

int Application::run() const
{
    MSG message{};
    while (true) {
        if (!PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE)) {
            this->m_window->update();
            continue;
        }

        if (message.message == WM_QUIT) {
            break;
        }

        TranslateMessage(&message);
        DispatchMessageW(&message);
    }

    return static_cast<int>(message.wParam);
}

void Application::terminate() const noexcept { PostQuitMessage(0); }

} // namespace System
