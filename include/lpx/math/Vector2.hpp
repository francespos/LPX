#pragma once

namespace lpx {

struct Vector2 { 
    float x, y; 

    Vector2(float x, float y) : x(x), y(y) {}

    Vector2& operator+=(Vector2 other);
    Vector2& operator-=(Vector2 other);

    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);

    float Length() const;
    float LengthSquared() const;

    Vector2 Negative() const;
    Vector2 Normalized() const;

    Vector2& Negate();
    Vector2& Normalize();
};

bool operator==(Vector2 lhs, Vector2 rhs);
bool operator!=(Vector2 lhs, Vector2 rhs);

Vector2 operator+(Vector2 lhs, Vector2 rhs);
Vector2 operator-(Vector2 lhs, Vector2 rhs);

Vector2 operator*(Vector2 vector, float scalar);
Vector2 operator*(float scalar, Vector2 vector);
Vector2 operator/(Vector2 vector, float scalar);

float Dot(Vector2 lhs, Vector2 rhs);
float Cross(Vector2 lhs, Vector2 rhs);

float Distance(Vector2 lhs, Vector2 rhs);
float DistanceSquared(Vector2 lhs, Vector2 rhs);

} // namespace lpx