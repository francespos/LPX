#include <gtest/gtest.h>
#include "lpx/math/Matrix2.hpp"
#include <cmath>
#include <limits>

using namespace lpx;

TEST(Matrix2Test, ColsConstructor) {
    Vector2 col1(-323.04f, 8574.111f);
    Vector2 col2(777.0f, 0.0044f);

    Matrix2 matrix(col1, col2);

    EXPECT_EQ(matrix.col1, col1);
    EXPECT_EQ(matrix.col2, col2);
}

TEST(Matrix2Test, EntriesConstructor) {
    float m00 = -323.04f;
    float m01 = 777.0f;
    float m10 = 8574.111f;
    float m11 = 0.0044f;

    Matrix2 matrix(m00, m01, m10, m11);
    Vector2 col1(m00, m10);
    Vector2 col2(m01, m11);
    
    EXPECT_EQ(matrix.col1, col1);
    EXPECT_EQ(matrix.col2, col2);
}