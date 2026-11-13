#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "vector2d.h"
#include "vector3d.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "=== Vector output ===\n";
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << "v1 = " << v1 << ", v2 = " << v2 << std::endl;
    std::cout << "via to_string: " << to_string(v1) << std::endl;
    std::cout << "via operator<<: " << v1 << std::endl;

    std::cout << "\n=== Vector polymorphism ===\n";
    Vector3D v3(1.0, 2.0, 2.0);
    Vector2D* vector_objects[] = {&v1, &v3};
    for (const Vector2D* vector : vector_objects) {
        std::cout << vector->describe() << "; length = "
                  << vector->length() << '\n';
    }

    std::cout << "\n=== Shape polymorphism ===\n";
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0);
    Shape* shapes[] = {&circle, &rectangle, &triangle};
    for (const Shape* shape : shapes) {
        std::cout << *shape << '\n';
    }

    std::cout << "\n=== Virtual destructor ===\n";
    try {
        Shape* dynamic_circle = new Circle(2.0);
        delete dynamic_circle;
    } catch (const std::invalid_argument& error) {
        std::cerr << "Could not create shape: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
