#pragma once

namespace Util {

class Size {
public:
    constexpr Size() noexcept
        : m_width(0)
        , m_height(0)
    {
    }

    constexpr Size(float width, float height) noexcept
        : m_width(width)
        , m_height(height)
    {
    }

    constexpr void setWidth(float width) noexcept { this->m_width = width; }
    constexpr void setHeight(float height) noexcept { this->m_height = height; }

    constexpr float getWidth() const noexcept { return this->m_width; }
    constexpr float getHeight() const noexcept { return this->m_height; }

private:
    float m_width;
    float m_height;
};

} // namespace Util
