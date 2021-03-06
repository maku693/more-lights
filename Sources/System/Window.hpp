#pragma once

#include <windows.h>

#include <functional>
#include <string>

namespace Util {

class Size;

} // namespace Util

namespace System {

enum class KeyCode;
enum class KeyState;

class Window final {
public:
    using OnCloseHandlerType = typename std::function<void()>;
    using OnKeyboardHandlerType = std::function<void(KeyCode, KeyState)>;
    using OnUpdateHandlerType = typename std::function<void()>;

    Window(HINSTANCE);

    HWND getHWnd() const noexcept;
    Util::Size getSize() const;

    void setOnClose(OnCloseHandlerType) noexcept;
    void setOnKeyboard(OnKeyboardHandlerType) noexcept;
    void setOnUpdate(OnUpdateHandlerType) noexcept;
    void setTitle(const std::string&) noexcept;

    void display() noexcept;
    void makeFullScreen();
    void update();

private:
    HWND m_hWnd;
    bool m_isFullScreen;
    OnCloseHandlerType m_onClose;
    OnKeyboardHandlerType m_onKeyboard;
    OnUpdateHandlerType m_onUpdate;

    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM) noexcept;
};

} // namespace System
