#pragma once

namespace lpx {

class Rotation {
public:
    Rotation(float angle);

    friend bool operator==(Rotation lhs, Rotation rhs);
    friend Rotation operator*(Rotation lhs, Rotation rhs);

    Rotation& operator*=(Rotation other);

    float Angle() const;
    Rotation Inverse() const;

    Rotation& SetAngle(float angle);
    Rotation& Invert();

private:
    Rotation(float cosine, float sine) : m_cosine(cosine), m_sine(sine) {}
    float m_cosine, m_sine;
};

bool operator==(Rotation lhs, Rotation rhs);
bool operator!=(Rotation lhs, Rotation rhs);
Rotation operator*(Rotation lhs, Rotation rhs);

} // namespace lpx