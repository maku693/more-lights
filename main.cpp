#include <windows.h>

#include "System/Application.hpp"
#include "System/Window.hpp"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int)
{
    const System::Application app{};
    System::Window window{ hInstance };

    window.display();

    return app.run([] {
    });
}
