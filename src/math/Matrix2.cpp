#include "lpx/math/Matrix2.hpp"

namespace lpx {

Matrix2& Matrix2::operator+=(Matrix2 other) {
    col1 += other.col1;
    col2 += other.col2;
    return *this;
}

Matrix2& Matrix2::operator-=(Matrix2 other) {
    col1 -= other.col1;
    col2 -= other.col2;
    return *this;
}

Matrix2& Matrix2::operator*=(float scalar) {
    col1 *= scalar;
    col2 *= scalar;
    return *this;
}

Matrix2& Matrix2::operator/=(float scalar) {
    col1 /= scalar;
    col2 /= scalar;
    return *this;
}

Matrix2& Matrix2::operator*=(Matrix2 other) {
    return *this = *this * other;
}

float Matrix2::Determinant() const {
    return col1.x * col2.y - col2.x * col1.y;
}

Matrix2 Matrix2::Negative() const {
    return Matrix2(col1.Negative(), col2.Negative());
}

Matrix2 Matrix2::Inverse() const {
    auto inv_det = 1.0f / Determinant();

    return Matrix2(col2.y * inv_det, 
        -col2.x * inv_det, 
        -col1.y * inv_det, 
         col1.x * inv_det);
}

Matrix2& Matrix2::Negate() {
    col1.Negate();
    col2.Negate();
    return *this;
}
 
Matrix2& Matrix2::Invert() {
    return *this = Inverse();
}

bool operator==(Matrix2 lhs, Matrix2 rhs) {  
    return lhs.col1 == rhs.col1 && lhs.col2 == rhs.col2;
}

bool operator!=(Matrix2 lhs, Matrix2 rhs) {
    return !(lhs == rhs);
}

Matrix2 operator+(Matrix2 lhs, Matrix2 rhs) {
    return lhs += rhs;
}

Matrix2 operator-(Matrix2 lhs, Matrix2 rhs) {
    return lhs -= rhs;
}

Matrix2 operator*(Matrix2 matrix, float scalar) {
    return matrix *= scalar;
}

Matrix2 operator*(float scalar, Matrix2 matrix) {
    return matrix *= scalar;
}

Matrix2 operator/(Matrix2 matrix, float scalar) {
    return matrix /= scalar;
}

Matrix2 operator*(Matrix2 lhs, Matrix2 rhs) {
    return Matrix2(lhs * rhs.col1, lhs * rhs.col2);
}

Vector2 operator*(Matrix2 matrix, Vector2 vector) {
    return matrix.col1 * vector.x + matrix.col2 * vector.y;
}

} // namespace lpx