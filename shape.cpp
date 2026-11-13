#include "shape.h"

#include <ostream>

std::string Shape::describe() const {
    return name() + ": area = " + std::to_string(area()) +
           ", perimeter = " + std::to_string(perimeter());
}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    return os << shape.describe();
}
