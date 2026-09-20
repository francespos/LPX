#pragma once

#include "lpx/math/Vector2.hpp"
#include "lpx/math/Rotation.hpp"

namespace lpx {

struct Transform {
    Vector2 translation;
    Rotation rotation;

    Transform(Vector2 translation, Rotation rotation) 
        : translation(translation), rotation(rotation) {}

    Transform& operator*=(Transform other);
    Transform& operator*=(Rotation rotation);

    Transform Inverse() const;
    Transform& Invert();
};

bool operator==(Transform lhs, Transform rhs);
bool operator!=(Transform lhs, Transform rhs);

Transform operator*(Transform lhs, Transform rhs);
Transform operator*(Transform transform, Rotation rotation);

} // namespace lpx