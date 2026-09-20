#pragma once

#include "lpx/math/Vector2.hpp"

namespace lpx {

struct Matrix2 { 
    Vector2 col1, col2; 

    Matrix2(Vector2 col1, Vector2 col2) : col1(col1), col2(col2) {}
    Matrix2(float m00, float m01, float m10, float m11) : col1(m00, m10), col2(m01, m11) {}

    Matrix2& operator+=(Matrix2 other);
    Matrix2& operator-=(Matrix2 other);

    Matrix2& operator*=(float scalar);
    Matrix2& operator/=(float scalar);

    Matrix2& operator*=(Matrix2 other);

    float Determinant() const;

    Matrix2 Negative() const;
    Matrix2 Inverse() const;

    Matrix2& Negate();
    Matrix2& Invert();
};

bool operator==(Matrix2 lhs, Matrix2 rhs);
bool operator!=(Matrix2 lhs, Matrix2 rhs);

Matrix2 operator+(Matrix2 lhs, Matrix2 rhs);
Matrix2 operator-(Matrix2 lhs, Matrix2 rhs);

Matrix2 operator*(Matrix2 matrix, float scalar);
Matrix2 operator*(float scalar, Matrix2 matrix);
Matrix2 operator/(Matrix2 matrix, float scalar);

Matrix2 operator*(Matrix2 lhs, Matrix2 rhs);
Vector2 operator*(Matrix2 matrix, Vector2 vector);

} // namespace lpx