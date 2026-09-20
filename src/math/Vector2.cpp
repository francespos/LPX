#include "lpx/math/Vector2.hpp"
#include "lpx/math/Float.hpp"

namespace lpx {

Vector2& Vector2::operator+=(Vector2 other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(Vector2 other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(float scalar) {
    return *this *= 1.0f / scalar;
}

float Vector2::Length() const {
    return std::sqrt(LengthSquared());
}

float Vector2::LengthSquared() const {
    return x * x + y * y;
}

Vector2 Vector2::Negative() const {
    return Vector2(-x, -y);
}

Vector2 Vector2::Normalized() const {
    return *this / Length();
}

Vector2& Vector2::Negate() {
    x = -x;
    y = -y;
    return *this;
}

Vector2& Vector2::Normalize() {
    return *this /= Length();
}

bool operator==(Vector2 lhs, Vector2 rhs) {
    return AreEqual(lhs.x, rhs.x) && AreEqual(lhs.y, rhs.y);
}

bool operator!=(Vector2 lhs, Vector2 rhs) {
    return !(lhs == rhs);
}

Vector2 operator+(Vector2 lhs, Vector2 rhs) {
    return lhs += rhs;
}

Vector2 operator-(Vector2 lhs, Vector2 rhs) {
    return lhs -= rhs;
}

Vector2 operator*(Vector2 vector, float scalar) {
    return vector *= scalar;
}

Vector2 operator*(float scalar, Vector2 vector) {
    return vector *= scalar;
}

Vector2 operator/(Vector2 vector, float scalar) {
    return vector /= scalar;
}

float Dot(Vector2 lhs, Vector2 rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

float Cross(Vector2 lhs, Vector2 rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

float Distance(Vector2 lhs, Vector2 rhs) {
    return (lhs - rhs).Length();
}

float DistanceSquared(Vector2 lhs, Vector2 rhs) {
    return (lhs - rhs).LengthSquared();
}

} // namespace lpx