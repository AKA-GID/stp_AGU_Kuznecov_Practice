#include "rectangle.h"

#include <stdexcept>

Rectangle::Rectangle(double width, double height)
    : width_(width), height_(height) {
    if (width_ <= 0.0 || height_ <= 0.0) {
        throw std::invalid_argument("Rectangle sides must be greater than zero");
    }
}

double Rectangle::area() const {
    return width_ * height_;
}

double Rectangle::perimeter() const {
    return 2.0 * (width_ + height_);
}

std::string Rectangle::name() const {
    return "Rectangle";
}
