#include "vector2d.h"

#include <cmath>
#include <iomanip>
#include <sstream>
#include <ostream>

Vector2D::Vector2D(double x, double y) : x_(x), y_(y) {}

double Vector2D::x() const {
    return x_;
}

double Vector2D::y() const {
    return y_;
}

double Vector2D::length() const {
    return std::sqrt(x_ * x_ + y_ * y_);
}

std::string Vector2D::describe() const {
    return "2D vector " + to_string(*this);
}

std::ostream& operator<<(std::ostream& os, const Vector2D& vector) {
    return os << '(' << vector.x() << ", " << vector.y() << ')';
}

std::string to_string(const Vector2D& vector) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2)
           << '(' << vector.x() << ", " << vector.y() << ')';
    return stream.str();
}
