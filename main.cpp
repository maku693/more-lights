#include <windows.h>

#include "Application.hpp"
#include "Window.hpp"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int)
{
    const Application app{};
    Window window{ hInstance };

    window.display();

    return app.run([] {
    });
}
