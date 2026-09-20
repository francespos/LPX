#include "lpx/math/Rotation.hpp"
#include "lpx/math/Float.hpp"

namespace lpx {

Rotation::Rotation(float angle) : m_cosine(std::cos(angle)), m_sine(std::sin(angle)) {}

Rotation& Rotation::operator*=(Rotation other) {
    return *this = *this * other;
}

float Rotation::Angle() const {
    return std::atan2(m_sine, m_cosine);
}

Rotation Rotation::Inverse() const {
    return Rotation(m_cosine, -m_sine);
}

Rotation& Rotation::SetAngle(float angle) {
    m_cosine = std::cos(angle);
    m_sine = std::sin(angle);
    return *this;
}

Rotation& Rotation::Invert() {
    m_sine = -m_sine;
    return *this;
}

bool operator==(Rotation lhs, Rotation rhs) {
    return AreEqual(lhs.m_cosine, rhs.m_cosine) && AreEqual(lhs.m_sine, rhs.m_sine);
}

bool operator!=(Rotation lhs, Rotation rhs) {
    return !(lhs == rhs);
}

Rotation operator*(Rotation lhs, Rotation rhs) {
    return Rotation(lhs.m_cosine * rhs.m_cosine - lhs.m_sine * lhs.m_sine, 
        lhs.m_sine * rhs.m_cosine + lhs.m_cosine * rhs.m_sine);
}

} // namespace lpx
