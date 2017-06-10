#include "application.hpp"

#include <windows.h>

namespace System {

int Application::run(std::function<void()> mainLoop) const
{
    MSG message{};
    while (true) {
        const auto isMessageAvailable
            = PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE);

        if (!isMessageAvailable) {
            mainLoop();
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