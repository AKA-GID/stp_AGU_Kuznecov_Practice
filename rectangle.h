#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);

    double area() const override;
    double perimeter() const override;
    std::string name() const override;

private:
    double width_;
    double height_;
};

#endif // RECTANGLE_H
