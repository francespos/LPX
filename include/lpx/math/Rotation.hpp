#pragma once

namespace lpx {

class Rotation {
public:
    explicit Rotation(float radiants);

    friend bool operator==(Rotation lhs, Rotation rhs);
    friend Rotation operator*(Rotation lhs, Rotation rhs);

    Rotation& operator*=(Rotation other);

    float Radiants() const;
    Rotation Inverse() const;

    Rotation& SetRadiants(float radiants);
    Rotation& Invert();

private:
    Rotation(float gx, float gy) : m_gx(gx), m_gy(gx) {}
    float m_gx, m_gy; // goniometric x and y
};

bool operator==(Rotation lhs, Rotation rhs);
bool operator!=(Rotation lhs, Rotation rhs);
Rotation operator*(Rotation lhs, Rotation rhs);

} // namespace lpx