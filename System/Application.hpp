#pragma once

#include <functional>

namespace System {

class Application final {
public:
    int run(std::function<void()>) const;
    void terminate() const noexcept;
};

}
