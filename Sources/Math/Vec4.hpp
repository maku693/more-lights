#pragma once

namespace Math {

class Vec4 {
public:
    constexpr Vec4() noexcept
        : m_x(0.0)
        , m_y(0.0)
        , m_z(0.0)
        , m_w(0.0)
    {
    }
    constexpr Vec4(Vec3&& v) noexcept
        : m_x(v.getX())
        , m_y(v.getY())
        , m_z(v.getZ())
        , m_w(v.getW())
    {
    }
    constexpr Vec4(float x, float y, float z, float w) noexcept
        : m_x(x)
        , m_y(y)
        , m_z(z)
        , m_w(w)
    {
    }

    constexpr float getX() const noexcept { return m_x; }
    constexpr float getY() const noexcept { return m_y; }
    constexpr float getZ() const noexcept { return m_z; }
    constexpr float getW() const noexcept { return m_w; }

    constexpr void setX(float x) noexcept { m_x = x; }
    constexpr void setY(float y) noexcept { m_y = y; }
    constexpr void setZ(float z) noexcept { m_z = z; }
    constexpr void setW(float w) noexcept { m_w = w; }

private:
    float m_x, m_y, m_z, m_w;
};

} // namespace Math
