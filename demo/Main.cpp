#include <iostream>
#include <lpx/math/Vector2.hpp>
#include <lpx/math/Matrix2.hpp>
#include <lpx/math/Rotation.hpp>
#include <lpx/math/Transform.hpp>

int main() {
    lpx::Vector2 vector(2.0f, -3.0f);
    lpx::Matrix2 matrix(3.2f, -66.32434f, 32.15f, 1e-5f);

    lpx::Rotation rotation(3.0f);
    lpx::Transform transform(vector, rotation);

    std::cout << "Hello world!\n";
}