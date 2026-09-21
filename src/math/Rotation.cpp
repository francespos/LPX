#include "lpx/math/Rotation.hpp"
#include <cmath>

namespace lpx {

Rotation::Rotation(float radiants) : m_gx(std::cos(radiants)), m_gy(std::sin(radiants)) {}

Rotation& Rotation::operator*=(Rotation other) {
    return *this = *this * other;
}

float Rotation::Radiants() const {
    return std::atan2(m_gy, m_gx);
}

Rotation Rotation::Inverse() const {
    return Rotation(m_gx, -m_gy);
}

Rotation& Rotation::SetRadiants(float radiants) {
    m_gx = std::cos(radiants);
    m_gy = std::sin(radiants);
    return *this;
}

Rotation& Rotation::Invert() {
    m_gy = -m_gy;
    return *this;
}

bool operator==(Rotation lhs, Rotation rhs) {
    return lhs.m_gx == rhs.m_gx && lhs.m_gy == rhs.m_gy;
}

bool operator!=(Rotation lhs, Rotation rhs) {
    return !(lhs == rhs);
}

Rotation operator*(Rotation lhs, Rotation rhs) {
    return Rotation(lhs.m_gx * rhs.m_gx - lhs.m_gy * lhs.m_gy, 
        lhs.m_gy * rhs.m_gx + lhs.m_gx * rhs.m_gy);
}

} // namespace lpx
