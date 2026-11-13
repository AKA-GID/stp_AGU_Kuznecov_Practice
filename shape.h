#ifndef SHAPE_H
#define SHAPE_H

#include <iosfwd>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string name() const = 0;
    virtual std::string describe() const;
};

std::ostream& operator<<(std::ostream& os, const Shape& shape);

#endif // SHAPE_H
