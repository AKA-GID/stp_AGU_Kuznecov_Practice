#include "vector2d.h"

#include <cmath>
#include <stdexcept>

Vector2D::Vector2D(double x, double y) : x_(x), y_(y) {}

double Vector2D::x() const { return x_; }
double Vector2D::y() const { return y_; }

double Vector2D::length() const {
    return std::sqrt(x_ * x_ + y_ * y_);
}

Vector2D Vector2D::scale(double factor) const {
    return Vector2D(x_ * factor, y_ * factor);
}

Vector2D Vector2D::scale(double fx, double fy) const {
    return Vector2D(x_ * fx, y_ * fy);
}

void Vector2D::scale(double factor) {
    x_ *= factor;
    y_ *= factor;
}

bool Vector2D::operator==(const Vector2D& other) const {
    return length() == other.length();
}

bool Vector2D::operator!=(const Vector2D& other) const {
    return !(*this == other);
}

bool Vector2D::operator<(const Vector2D& other) const {
    return length() < other.length();
}

bool Vector2D::operator>(const Vector2D& other) const {
    return other < *this;
}

bool Vector2D::operator<=(const Vector2D& other) const {
    return !(other < *this);
}

bool Vector2D::operator>=(const Vector2D& other) const {
    return !(*this < other);
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x_ + other.x_, y_ + other.y_);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x_ - other.x_, y_ - other.y_);
}

Vector2D Vector2D::operator*(double factor) const {
    return Vector2D(x_ * factor, y_ * factor);
}

Vector2D Vector2D::operator/(double factor) const {
    if (factor == 0.0) {
        throw std::invalid_argument("Cannot divide a vector by zero");
    }
    return Vector2D(x_ / factor, y_ / factor);
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
}

Vector2D Vector2D::operator-() const {
    return Vector2D(-x_, -y_);
}

Vector2D operator*(double factor, const Vector2D& v) {
    return Vector2D(v.x_ * factor, v.y_ * factor);
}
