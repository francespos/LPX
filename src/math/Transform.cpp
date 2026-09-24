#include "lpx/math/Transform.hpp"

namespace lpx {

Transform& Transform::operator*=(Transform other) {
    translation += other.translation;
    rotation *= other.rotation;
    return *this;
}

Transform& Transform::operator*=(Vector2 translation) {
    this->translation += translation;
    return *this;
}

Transform& Transform::operator*=(Rotation rotation) {
    this->rotation *= rotation;
    return *this;
}

Transform Transform::Inverse() const {
    return Transform(translation.Negative(), rotation.Inverse());
}

Transform& Transform::Invert() {
    translation.Negate();
    rotation.Invert();
    return *this;
}

bool operator==(Transform lhs, Transform rhs) {
    return lhs.translation == rhs.translation && lhs.rotation == rhs.rotation;
}

bool operator!=(Transform lhs, Transform rhs) {
    return !(lhs == rhs);
}

Transform operator*(Transform lhs, Transform rhs) {
    return Transform(lhs.translation + rhs.translation, lhs.rotation * rhs.rotation);
}

Transform operator*(Transform transform, Vector2 translation) {
    return Transform(transform.translation + translation, transform.rotation);
}

Transform operator*(Transform transform, Rotation rotation) {
    return Transform(transform.translation, transform.rotation * rotation);
}

} // namespace lpx