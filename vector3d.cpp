#include "vector3d.h"

#include <cmath>
#include <string>

Vector3D::Vector3D(double x, double y, double z)
    : Vector2D(x, y), z_(z) {}

double Vector3D::z() const {
    return z_;
}

double Vector3D::length() const {
    return std::sqrt(x() * x() + y() * y() + z_ * z_);
}

std::string Vector3D::describe() const {
    return "3D vector (" + std::to_string(x()) + ", " +
           std::to_string(y()) + ", " + std::to_string(z_) + ")";
}
