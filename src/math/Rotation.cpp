#include "lpx/math/Rotation.hpp"
#include <cmath>

namespace lpx {

Rotation::Rotation(float angle) : m_cos_angle(std::cos(angle)), m_sin_angle(std::sin(angle)) {}

Rotation& Rotation::operator*=(Rotation other) {
    return *this = *this * other;
}

float Rotation::Angle() const {
    return std::atan2(m_sin_angle, m_cos_angle);
}

Rotation Rotation::Inverse() const {
    return Rotation(m_cos_angle, -m_sin_angle);
}

Rotation& Rotation::SetAngle(float angle) {
    m_cos_angle = std::cos(angle);
    m_sin_angle = std::sin(angle);
    return *this;
}

Rotation& Rotation::Invert() {
    m_sin_angle = -m_sin_angle;
    return *this;
}

bool operator==(Rotation lhs, Rotation rhs) {
    return lhs.m_cos_angle == rhs.m_cos_angle && lhs.m_sin_angle == rhs.m_sin_angle;
}

bool operator!=(Rotation lhs, Rotation rhs) {
    return !(lhs == rhs);
}

Rotation operator*(Rotation lhs, Rotation rhs) {
    return Rotation(lhs.m_cos_angle * rhs.m_cos_angle - lhs.m_sin_angle * lhs.m_sin_angle, 
        lhs.m_sin_angle * rhs.m_cos_angle + lhs.m_cos_angle * rhs.m_sin_angle);
}

} // namespace lpx
