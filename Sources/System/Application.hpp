#pragma once

#include <memory>

namespace System {

class Window;

class Application final {
public:
    void setWindow(std::shared_ptr<Window>) noexcept;

    int run() const;
    void terminate() const noexcept;

private:
    std::shared_ptr<Window> m_window;
};

} // namespace System
