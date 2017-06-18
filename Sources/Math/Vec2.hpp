#pragma once

namespace Math {

class Vec2 {
public:
    constexpr Vec2() noexcept
        : m_x(0.0)
        , m_y(0.0)
    {
    }
    constexpr Vec2(Vec2&& v) noexcept
        : m_x(v.getX())
        , m_y(v.getY())
    {
    }
    constexpr Vec2(float x, float y) noexcept
        : m_x(x)
        , m_y(y)
    {
    }

    constexpr float getX() const noexcept { return m_x; }
    constexpr float getY() const noexcept { return m_y; }

    constexpr void setX(float x) noexcept { m_x = x; }
    constexpr void setY(float y) noexcept { m_y = y; }

private:
    float m_x, m_y;
};

} // namespace Math
