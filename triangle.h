#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
public:
    Triangle(double a, double b, double c);

    double area() const override;
    double perimeter() const override;
    std::string name() const override;

private:
    double a_;
    double b_;
    double c_;
};

#endif // TRIANGLE_H
