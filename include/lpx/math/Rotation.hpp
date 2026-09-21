#pragma once

namespace lpx {

class Rotation {
public:
    explicit Rotation(float angle);

    friend bool operator==(Rotation lhs, Rotation rhs);
    friend Rotation operator*(Rotation lhs, Rotation rhs);

    Rotation& operator*=(Rotation other);

    float Angle() const;
    Rotation Inverse() const;

    Rotation& SetAngle(float angle);
    Rotation& Invert();

private:
    Rotation(float cos_angle, float sin_angle) : m_cos_angle(cos_angle), m_sin_angle(sin_angle) {}
    float m_cos_angle, m_sin_angle;
};

bool operator==(Rotation lhs, Rotation rhs);
bool operator!=(Rotation lhs, Rotation rhs);
Rotation operator*(Rotation lhs, Rotation rhs);

} // namespace lpx