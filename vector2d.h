#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iosfwd>
#include <string>

class Vector2D {
public:
    Vector2D(double x = 0.0, double y = 0.0);

    double x() const;
    double y() const;
    virtual double length() const;
    virtual std::string describe() const;

    virtual ~Vector2D() = default;

private:
    double x_;
    double y_;
};

std::ostream& operator<<(std::ostream& os, const Vector2D& vector);
std::string to_string(const Vector2D& vector);

#endif // VECTOR2D_H
