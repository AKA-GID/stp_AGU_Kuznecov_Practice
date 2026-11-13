#include "triangle.h"

#include <cmath>
#include <stdexcept>

Triangle::Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {
    if (a_ <= 0.0 || b_ <= 0.0 || c_ <= 0.0 ||
        a_ + b_ <= c_ || a_ + c_ <= b_ || b_ + c_ <= a_) {
        throw std::invalid_argument("Triangle sides must satisfy the triangle inequality");
    }
}

double Triangle::area() const {
    const double semi_perimeter = perimeter() / 2.0;
    return std::sqrt(semi_perimeter * (semi_perimeter - a_) *
                     (semi_perimeter - b_) * (semi_perimeter - c_));
}

double Triangle::perimeter() const {
    return a_ + b_ + c_;
}

std::string Triangle::name() const {
    return "Triangle";
}
