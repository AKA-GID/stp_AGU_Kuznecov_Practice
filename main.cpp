#include <cmath>
#include <iostream>
#include <stdexcept>

#include "vector2d.h"

namespace {
bool check(bool condition, const char* message) {
    std::cout << (condition ? "[PASS] " : "[FAIL] ") << message << '\n';
    return condition;
}

bool hasCoordinates(const Vector2D& v, double expected_x, double expected_y) {
    constexpr double epsilon = 1e-9;
    return std::abs(v.x() - expected_x) < epsilon &&
           std::abs(v.y() - expected_y) < epsilon;
}

void printVector(const char* label, const Vector2D& v) {
    std::cout << label << " = (" << v.x() << ", " << v.y() << ")\n";
}
} // namespace

int main() {
    bool all_passed = true;

    const Vector2D basic(3.0, 4.0);
    printVector("v", basic);
    std::cout << "length = " << basic.length() << "\n\n";
    all_passed &= check(std::abs(basic.length() - 5.0) < 1e-9,
                        "length uses the Euclidean norm");

    Vector2D scaled(2.0, 3.0);
    const Vector2D& const_scaled = scaled;
    const Vector2D returned_scale = const_scaled.scale(2.0);
    const Vector2D axis_scale = scaled.scale(2.0, 4.0);
    scaled.scale(2.0);
    printVector("scale(factor), returns", returned_scale);
    printVector("scale(fx, fy)", axis_scale);
    printVector("scale(factor), in place", scaled);
    all_passed &= check(hasCoordinates(returned_scale, 4.0, 6.0),
                        "non-mutating scale(factor)");
    all_passed &= check(hasCoordinates(axis_scale, 4.0, 12.0),
                        "non-mutating scale(fx, fy)");
    all_passed &= check(hasCoordinates(scaled, 4.0, 6.0),
                        "in-place scale(factor)");

    const Vector2D short_vector(3.0, 4.0);
    const Vector2D same_length(0.0, 5.0);
    const Vector2D long_vector(6.0, 8.0);
    std::cout << std::boolalpha << "\nComparisons by length:\n"
              << "short == same: " << (short_vector == same_length) << '\n'
              << "short != long: " << (short_vector != long_vector) << '\n'
              << "short < long: " << (short_vector < long_vector) << '\n'
              << "long > short: " << (long_vector > short_vector) << '\n'
              << "short <= same: " << (short_vector <= same_length) << '\n'
              << "long >= short: " << (long_vector >= short_vector) << '\n';
    all_passed &= check(short_vector == same_length, "operator== compares lengths");
    all_passed &= check(short_vector != long_vector, "operator!= compares lengths");
    all_passed &= check(short_vector < long_vector, "operator< compares lengths");
    all_passed &= check(long_vector > short_vector, "operator> compares lengths");
    all_passed &= check(short_vector <= same_length, "operator<= compares lengths");
    all_passed &= check(long_vector >= short_vector, "operator>= compares lengths");

    const Vector2D left(3.0, 4.0);
    const Vector2D right(1.0, 2.0);
    printVector("left + right", left + right);
    printVector("left - right", left - right);
    printVector("left * 2", left * 2.0);
    printVector("left / 2", left / 2.0);
    printVector("-left", -left);
    all_passed &= check(hasCoordinates(left + right, 4.0, 6.0), "operator+");
    all_passed &= check(hasCoordinates(left - right, 2.0, 2.0), "operator-");
    all_passed &= check(hasCoordinates(left * 2.0, 6.0, 8.0), "operator*");
    all_passed &= check(hasCoordinates(left / 2.0, 1.5, 2.0), "operator/");
    all_passed &= check(hasCoordinates(-left, -3.0, -4.0), "unary operator-");

    Vector2D accumulated = left;
    accumulated += right;
    printVector("left after += right", accumulated);
    all_passed &= check(hasCoordinates(accumulated, 4.0, 6.0), "operator+=");
    accumulated -= right;
    printVector("then after -= right", accumulated);
    all_passed &= check(hasCoordinates(accumulated, 3.0, 4.0), "operator-=");

    const Vector2D member_product = left * 2.0;
    const Vector2D symmetric_product = 2.0 * left;
    printVector("left * 2", member_product);
    printVector("2 * left", symmetric_product);
    all_passed &= check(hasCoordinates(member_product, symmetric_product.x(),
                                       symmetric_product.y()),
                        "scalar multiplication works in both operand orders");

    try {
        (void)(left / 0.0);
        all_passed &= check(false, "division by zero throws invalid_argument");
    } catch (const std::invalid_argument& error) {
        std::cout << "Division by zero rejected: " << error.what() << '\n';
        all_passed &= check(true, "division by zero throws invalid_argument");
    }

    std::cout << (all_passed ? "\nAll checks passed.\n" : "\nSome checks failed.\n");
    return all_passed ? 0 : 1;
}
