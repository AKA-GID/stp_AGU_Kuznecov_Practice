#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "vector2d.h"

class Vector3D : public Vector2D {
public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

    double z() const;
    double length() const override;
    std::string describe() const override;

private:
    double z_;
};

#endif // VECTOR3D_H
