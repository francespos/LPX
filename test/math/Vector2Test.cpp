#include <gtest/gtest.h>
#include <lpx/math/Vector2.hpp>
#include <cmath>

using namespace lpx;

TEST(Vector2Test, Constructor) {
    float x = 1.3221f;
    float y = -432.02f;
    Vector2 vector(x, y);

    EXPECT_EQ(vector.x, x);
    EXPECT_EQ(vector.y, y);
}

TEST(Vector2Test, Equal) {
    float x = 1.3221f;
    float y = -432.02f;  

    Vector2 lhs(x, y);  
    Vector2 rhs(x, y);

    EXPECT_EQ(lhs, rhs);
}

TEST(Vector2Test, NotEqual) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    EXPECT_NE(lhs, rhs);
}

TEST(Vector2Test, AddOperator) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    Vector2 expected_sum = Vector2(x1 + x2, y1 + y2);
    Vector2 actual_sum = lhs + rhs;

    EXPECT_EQ(expected_sum, actual_sum);
}

TEST(Vector2Test, SubtractOperator) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    Vector2 expected_difference = Vector2(x1 - x2, y1 - y2);
    Vector2 actual_difference = lhs - rhs;

    EXPECT_EQ(expected_difference, actual_difference);
}

TEST(Vector2Test, MultiplyVectorScalar) {
    float x = 1.3221f;
    float y = -432.02f; 
    float scalar = -6532.04f;

    Vector2 expexted_product(x * scalar, y * scalar);
    auto actual_product = Vector2(x, y) * scalar;

    EXPECT_EQ(expexted_product, actual_product);
}

TEST(Vector2Test, MultiplyScalarVector) {
    float x = 1.3221f;
    float y = -432.02f; 
    float scalar = -6532.04f;

    Vector2 expexted_product(x * scalar, y * scalar);
    auto actual_product = scalar * Vector2(x, y);

    EXPECT_EQ(expexted_product, actual_product);
}

TEST(Vector2Test, DivideOperator) {
    float x = 1.3221f;
    float y = -432.02f; 
    float scalar = -6532.04f;

    Vector2 expexted_quotient(x / scalar, y / scalar);
    auto actual_quotient = Vector2(x, y) / scalar;

    EXPECT_EQ(expexted_quotient, actual_quotient);
}

TEST(Vector2Test, Dot) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    auto expected_dot = x1 * x2 + y1 * y2;
    auto actual_dot = Dot(Vector2(x1, y1), Vector2(x2, y2));

    EXPECT_EQ(expected_dot, actual_dot);
}

TEST(Vector2Test, Cross) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;
    
    auto expected_cross = x1 * y2 - y1 * x2;
    auto actual_cross = Cross(Vector2(x1, y1), Vector2(x2, y2));

    EXPECT_EQ(expected_cross, actual_cross);
}

TEST(Vector2Test, Distance) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;
    
    auto expected_distance = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    auto actual_distance = Distance(Vector2(x1, y1), Vector2(x2, y2));

    EXPECT_EQ(expected_distance, actual_distance);
}

TEST(Vector2Test, DistanceSquared) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;
    
    auto expected_distance_squared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    auto actual_distance_squared = DistanceSquared(Vector2(x1, y1), Vector2(x2, y2));

    EXPECT_EQ(expected_distance_squared, actual_distance_squared);
}

TEST(Vector2Test, AddEqualOperator) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    lhs += rhs;
    
    EXPECT_EQ(lhs.x, x1 + x2);
    EXPECT_EQ(lhs.y, y1 + y2);
}

TEST(Vector2Test, SubtractEqualOperator) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    lhs -= rhs;
    
    EXPECT_EQ(lhs.x, x1 - x2);
    EXPECT_EQ(lhs.y, y1 - y2);    
}

TEST(Vector2Test, MultiplyEqualOperator) {
    float x = 3534.34f;
    float y = -53.00584f;

    Vector2 vector(x, y);
    float scalar = 43.5f;

    vector.x *= scalar;
    vector.y *= scalar;

    EXPECT_EQ(vector.x, x * scalar);
    EXPECT_EQ(vector.y, y * scalar);
}

TEST(Vector2Test, DivideEqualOperator) {
    float x = 3534.34f;
    float y = -53.00584f;

    Vector2 vector(x, y);
    float scalar = 43.5f;

    vector.x /= scalar;
    vector.y /= scalar;

    EXPECT_EQ(vector.x, x / scalar);
    EXPECT_EQ(vector.y, y / scalar);
}

TEST(Vector2Test, Length) {
    float x = 394.43f;
    float y = 5003.593f;

    auto expected_length = std::sqrt(x * x + y * y);

    Vector2 vector(x, y);
    auto actual_length = vector.Length();

    EXPECT_EQ(expected_length, actual_length);
}

TEST(Vector2Test, LengthSquared) {
    float x = 394.43f;
    float y = 5003.593f;

    auto expected_length_squared = x * x + y * y;

    Vector2 vector(x, y);
    auto actual_length_squared = vector.LengthSquared();

    EXPECT_EQ(expected_length_squared, actual_length_squared);
}

TEST(Vector2Test, Negative) {
    float x = 394.43f;
    float y = 5003.593f;

    Vector2 expected_negative(-x, -y);
    auto actual_negative = Vector2(x, y).Negative();

    EXPECT_EQ(expected_negative.x, actual_negative.x);
    EXPECT_EQ(expected_negative.y, actual_negative.y);
}

TEST(Vector2Test, Normalized) {
    float x = 394.43f;
    float y = 5003.593f;

    auto inv_len = 1.0f / Vector2(x, y).Length();

    auto expected_normalized = Vector2(x * inv_len, y * inv_len);
    auto actual_normalized = Vector2(x, y).Normalized();

    EXPECT_EQ(expected_normalized, actual_normalized);
}

TEST(Vector2Test, Negate) {
    float x = 394.43f;
    float y = 5003.593f;

    auto expected_negative = Vector2(-x, -y);

    Vector2 actual_negative(x, y);
    actual_negative.Negate();

    EXPECT_EQ(expected_negative, actual_negative);
}

TEST(Vector2Test, Normalize) {
    float x = 394.43f;
    float y = 5003.593f;

    auto inv_len = 1.0f / Vector2(x, y).Length();
    Vector2 expected_normalized(x * inv_len, y * inv_len);

    Vector2 actual_normalized(x, y);
    actual_normalized.Normalize();

    EXPECT_EQ(expected_normalized, actual_normalized);
}

