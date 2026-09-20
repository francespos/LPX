#pragma once

#include <cmath>

namespace lpx {

constexpr float Pi = 3.14159265f;
constexpr float Epsilon = 1e-4f;

constexpr bool AreEqual(float x, float y) {
    return std::abs(x - y) < Epsilon;
}

} // namespace lpx