#include <windows.h>

#include "System/Application.hpp"
#include "System/Window.hpp"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int)
{
    System::Application app;
    auto window = std::make_shared<System::Window>(hInstance);

    app.setWindow(window);
    window->setOnClose([&app] {
        app.terminate();
    });

    window->display();
    return app.run();
}
