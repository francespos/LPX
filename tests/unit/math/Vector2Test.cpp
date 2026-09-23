#include <gtest/gtest.h>
#include <lpx/math/Vector2.hpp>
#include <cmath>
#include <limits>

using namespace lpx;

TEST(Vector2Test, Constructor) {
    float x = 1.3221f;
    float y = -432.02f;
    Vector2 vector(x, y);

    EXPECT_EQ(vector.x, x);
    EXPECT_EQ(vector.y, y);
}

TEST(Vector2Test, EqualTrue) {
    float x = 1.3221f;
    float y = -432.02f;  

    Vector2 lhs(x, y);  
    auto rhs = lhs;

    EXPECT_TRUE(lhs == rhs);
}

TEST(Vector2Test, EqualFalse) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    EXPECT_FALSE(lhs == rhs);
}

TEST(Vector2Test, NotEqualTrue) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    EXPECT_TRUE(lhs != rhs);
}

TEST(Vector2Test, NotEqualFalse) {
    float x = 1.3221f;
    float y = -432.02f;  

    Vector2 lhs(x, y);  
    auto rhs = lhs;

    EXPECT_FALSE(lhs != rhs);
}

TEST(Vector2Test, AddOperator) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    Vector2 expected = Vector2(x1 + x2, y1 + y2);
    Vector2 actual = lhs + rhs;

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, SubtractOperator) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 lhs(x1, y1);
    Vector2 rhs(x2, y2);

    Vector2 expected = Vector2(x1 - x2, y1 - y2);
    Vector2 actual = lhs - rhs;

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, MultiplyVectorScalar) {
    float x = 1.3221f;
    float y = -432.02f; 
    float scalar = -6532.04f;

    Vector2 expexted(x * scalar, y * scalar);
    auto actual = Vector2(x, y) * scalar;

    EXPECT_EQ(expexted, actual);
}

TEST(Vector2Test, MultiplyScalarVector) {
    float x = 1.3221f;
    float y = -432.02f; 
    float scalar = -6532.04f;

    Vector2 expexted(x * scalar, y * scalar);
    auto actual = scalar * Vector2(x, y);

    EXPECT_EQ(expexted, actual);
}

TEST(Vector2Test, DivideOperator) {
    float x = 1.3221f;
    float y = -432.02f; 
    float scalar = -6532.04f;

    Vector2 expexted(x / scalar, y / scalar);
    auto actual = Vector2(x, y) / scalar;

    EXPECT_EQ(expexted, actual);
}

TEST(Vector2Test, DivideNotZeroForPositiveZero) {
    float x = 1.3221f;
    float y = -432.02f; 

    float scalar = 0.0f;
    auto actual = Vector2(x, y) / scalar;

    EXPECT_EQ(actual.x, std::numeric_limits<float>::infinity());   
    EXPECT_EQ(actual.y, -std::numeric_limits<float>::infinity());
}

TEST(Vector2Test, DivideNotZeroForNegativeZero) {
    float x = 1.3221f;
    float y = -432.02f; 

    float scalar = -0.0f;
    auto actual = Vector2(x, y) / scalar;

    EXPECT_EQ(actual.x, -std::numeric_limits<float>::infinity());   
    EXPECT_EQ(actual.y, std::numeric_limits<float>::infinity());
}

TEST(Vector2Test, DivideZeroForZero) {
    float x = 0.0f;
    float y = -0.0f; 

    float scalar = 0.0f;
    auto actual = Vector2(x, y) / scalar;

    EXPECT_TRUE(std::isnan(actual.x));   
    EXPECT_TRUE(std::isnan(actual.y));    
}

TEST(Vector2Test, Dot) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    auto expected = x1 * x2 + y1 * y2;
    auto actual = Dot(Vector2(x1, y1), Vector2(x2, y2));

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, Cross) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;
    
    auto expected = x1 * y2 - y1 * x2;
    auto actual = Cross(Vector2(x1, y1), Vector2(x2, y2));

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, Distance) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;
    
    auto expected = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    auto actual = Distance(Vector2(x1, y1), Vector2(x2, y2));

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, DistanceSquared) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;
    
    auto expected = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    auto actual = DistanceSquared(Vector2(x1, y1), Vector2(x2, y2));

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, AddEqualOperator) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 other(x2, y2);       
    Vector2 expected(x1 + x2, y1 + y2);

    Vector2 actual(x1, y1);
    actual += other;

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, SubtractEqualOperator) {
    float x1 = 532.49583f;
    float y1 = -2e-4;

    float x2 = 483.04f;
    float y2 = 5002.85f;

    Vector2 other(x2, y2);
    Vector2 expected(x1 - x2, y1 - y2);

    Vector2 actual(x1, y1);
    actual -= other;

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, MultiplyEqualOperator) {
    float x = 3534.34f;
    float y = -53.00584f;

    float scalar = 43.5f;
    Vector2 expected(x * scalar, y * scalar);

    Vector2 actual(x, y);
    actual *= scalar;

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, DivideEqualOperator) {
    float x = 3534.34f;
    float y = -53.00584f;

    float scalar = 43.5f;
    Vector2 expected(x / scalar, y / scalar);

    Vector2 actual(x, y);
    actual /= scalar;

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, DivideEqualNotZeroForPositiveZero) {
    float x = 3534.34f;
    float y = -53.00584f;

    float scalar = 0.0f;
    Vector2 actual(x, y);
    actual /= scalar;

    EXPECT_EQ(actual.x, std::numeric_limits<float>::infinity()); 
    EXPECT_EQ(actual.y, -std::numeric_limits<float>::infinity());    
}

TEST(Vector2Test, DivideEqualNotZeroForNegativeZero) {
    float x = 3534.34f;
    float y = -53.00584f;

    float scalar = -0.0f;
    Vector2 actual(x, y);
    actual /= scalar;

    EXPECT_EQ(actual.x, -std::numeric_limits<float>::infinity()); 
    EXPECT_EQ(actual.y, std::numeric_limits<float>::infinity());    
}

TEST(Vector2Test, DivideEqualZeroForZero) {
    float x = 0.0f;
    float y = -0.0f;

    float scalar = 0.0f;
    Vector2 actual(x, y);
    actual /= scalar;

    EXPECT_TRUE(std::isnan(actual.x)); 
    EXPECT_TRUE(std::isnan(actual.y));    
}

TEST(Vector2Test, Length) {
    float x = 394.43f;
    float y = 5003.593f;

    auto expected = std::sqrt(x * x + y * y);

    Vector2 vector(x, y);
    auto actual = vector.Length();

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, LengthSquared) {
    float x = 394.43f;
    float y = 5003.593f;

    auto expected = x * x + y * y;

    Vector2 vector(x, y);
    auto actual = vector.LengthSquared();

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, Negative) {
    float x = 394.43f;
    float y = 5003.593f;

    Vector2 expected(-x, -y);
    auto actual = Vector2(x, y).Negative();

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, Normalized) {
    float x = 394.43f;
    float y = 5003.593f;

    auto inv_len = 1.0f / Vector2(x, y).Length();

    auto expected = Vector2(x * inv_len, y * inv_len);
    auto actual = Vector2(x, y).Normalized();

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, ZeroNormalized) {
    float x = 0.0f;
    float y = -0.0f;

    auto actual = Vector2(x, y).Normalized();

    EXPECT_TRUE(std::isnan(actual.x));
    EXPECT_TRUE(std::isnan(actual.y));
}

TEST(Vector2Test, Negate) {
    float x = 394.43f;
    float y = 5003.593f;

    auto expected = Vector2(-x, -y);

    Vector2 actual(x, y);
    actual.Negate();

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, Normalize) {
    float x = 394.43f;
    float y = 5003.593f;

    auto inv_len = 1.0f / Vector2(x, y).Length();
    Vector2 expected(x * inv_len, y * inv_len);

    Vector2 actual(x, y);
    actual.Normalize();

    EXPECT_EQ(expected, actual);
}

TEST(Vector2Test, ZeroNormalize) {
    float x = 0.0f;
    float y = -0.0f;

    Vector2 actual(x, y);
    actual.Normalize();

    EXPECT_TRUE(std::isnan(actual.x));    
    EXPECT_TRUE(std::isnan(actual.y));
}