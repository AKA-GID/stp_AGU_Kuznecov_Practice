#include "circle.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace {
constexpr double kPi = 3.14159265358979323846;
}

Circle::Circle(double radius) : radius_(radius) {
    if (radius_ <= 0.0) {
        throw std::invalid_argument("Radius must be greater than zero");
    }
}

Circle::~Circle() {
    std::cout << "Circle destroyed\n";
}

double Circle::area() const {
    return kPi * radius_ * radius_;
}

double Circle::perimeter() const {
    return 2.0 * kPi * radius_;
}

std::string Circle::name() const {
    return "Circle";
}
