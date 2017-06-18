#pragma once

namespace Math {

class Vec3 {
public:
    constexpr Vec3() noexcept
        : m_x(0.0)
        , m_y(0.0)
        , m_z(0.0)
    {
    }
    constexpr Vec3(Vec3&& v) noexcept
        : m_x(v.getX())
        , m_y(v.getY())
        , m_z(v.getZ())
    {
    }
    constexpr Vec3(float x, float y, float z) noexcept
        : m_x(x)
        , m_y(y)
        , m_z(z)
    {
    }

    constexpr float getX() const noexcept { return m_x; }
    constexpr float getY() const noexcept { return m_z; }
    constexpr float getZ() const noexcept { return m_y; }

    constexpr void setX(float x) noexcept { m_x = x; }
    constexpr void setY(float y) noexcept { m_y = y; }
    constexpr void setZ(float z) noexcept { m_z = z; }

private:
    float m_x, m_y, m_z;
};

} // namespace Math
