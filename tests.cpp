#include <cmath>
#include <iostream>
#include <stdexcept>

#include "vector2d.h"

namespace {
int failures = 0;
void check(bool condition, const char* name) {
    std::cout << (condition ? "[PASS] " : "[FAIL] ") << name << '\n';
    if (!condition) ++failures;
}
bool hasCoordinates(const Vector2D& value, double x, double y) {
    constexpr double epsilon = 1e-9;
    return std::abs(value.x() - x) < epsilon && std::abs(value.y() - y) < epsilon;
}
}

int main() {
    const Vector2D vector(3.0, 4.0);
    check(std::abs(vector.length() - 5.0) < 1e-9, "Euclidean length");

    Vector2D scaled(2.0, 3.0);
    const Vector2D& const_scaled = scaled;
    check(hasCoordinates(const_scaled.scale(2.0), 4.0, 6.0), "const scale returns a new vector");
    check(hasCoordinates(scaled.scale(2.0, 4.0), 4.0, 12.0), "axis scale returns a new vector");
    scaled.scale(3.0);
    check(hasCoordinates(scaled, 6.0, 9.0), "non-const scale changes the current vector");

    const Vector2D equal_length(0.0, 5.0);
    const Vector2D longer(6.0, 8.0);
    check(vector == equal_length, "operator== compares lengths");
    check(vector != longer, "operator!= compares lengths");
    check(vector < longer, "operator< compares lengths");
    check(longer > vector, "operator> compares lengths");
    check(vector <= equal_length, "operator<= compares lengths");
    check(longer >= vector, "operator>= compares lengths");

    const Vector2D other(1.0, 2.0);
    check(hasCoordinates(vector + other, 4.0, 6.0), "operator+");
    check(hasCoordinates(vector - other, 2.0, 2.0), "operator-");
    check(hasCoordinates(vector * 2.0, 6.0, 8.0), "member operator*");
    check(hasCoordinates(2.0 * vector, 6.0, 8.0), "friend operator* supports scalar on the left");
    check(hasCoordinates(vector / 2.0, 1.5, 2.0), "operator/");
    check(hasCoordinates(-vector, -3.0, -4.0), "unary operator-");

    Vector2D accumulated = vector;
    Vector2D& plus_result = (accumulated += other);
    check(&plus_result == &accumulated && hasCoordinates(accumulated, 4.0, 6.0),
          "operator+= mutates and returns a reference");
    Vector2D& minus_result = (accumulated -= other);
    check(&minus_result == &accumulated && hasCoordinates(accumulated, 3.0, 4.0),
          "operator-= mutates and returns a reference");

    bool division_threw = false;
    try { (void)(vector / 0.0); } catch (const std::invalid_argument&) { division_threw = true; }
    check(division_threw, "division by zero throws invalid_argument");

    if (failures == 0) std::cout << "All tests passed.\n";
    else std::cout << failures << " test(s) failed.\n";
    return failures == 0 ? 0 : 1;
}
