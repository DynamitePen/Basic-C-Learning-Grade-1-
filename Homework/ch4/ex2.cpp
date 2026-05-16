#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = 3.141592653589793;

class Shape {
public:
    Shape(const string& name) : name(name) {}
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual bool is3D() const = 0;
    virtual double getVolume() const { return 0.0; }
    virtual void print() const {
        cout << name;
    }

protected:
    string name;
};
class TwoDimensionalShape : public Shape {
public:
    TwoDimensionalShape(const string& name) : Shape(name) {}
    virtual ~TwoDimensionalShape() {}

    bool is3D() const override { return false; }
};
class ThreeDimensionalShape : public Shape {
public:
    ThreeDimensionalShape(const string& name) : Shape(name) {}
    virtual ~ThreeDimensionalShape() {}

    bool is3D() const override { return true; }
    virtual double getVolume() const override = 0;
};
class Rectangle : public TwoDimensionalShape {
public:
    Rectangle(double width, double height)
        : TwoDimensionalShape("Rectangle"), width(width), height(height) {}

    double getArea() const override {
        return width * height;
    }
    void print() const override {
        Shape::print();
        cout << " (" << width << " x " << height << ")";
    }
private:
    double width;
    double height;
};
class Circle : public TwoDimensionalShape {
public:
    Circle(double radius)
        : TwoDimensionalShape("Circle"), radius(radius) {}

    double getArea() const override {
        return PI * radius * radius;
    }

    void print() const override {
        Shape::print();
        cout << " (r=" << radius << ")";
    }
private:
    double radius;
};
class Triangle : public TwoDimensionalShape {
public:
    Triangle(double base, double height)
        : TwoDimensionalShape("Triangle"), base(base), height(height) {}

    double getArea() const override {
        return base * height / 2.0;
    }

    void print() const override {
        Shape::print();
        cout << " (base=" << base << ", height=" << height << ")";
    }

private:
    double base;
    double height;
};
class Sphere : public ThreeDimensionalShape {
public:
    Sphere(double radius)
        : ThreeDimensionalShape("Sphere"), radius(radius) {}

    double getArea() const override {
        return 4.0 * PI * radius * radius;
    }

    double getVolume() const override {
        return 4.0 / 3.0 * PI * radius * radius * radius;
    }

    void print() const override {
        Shape::print();
        cout << " (r=" << radius << ")";
    }

private:
    double radius;
};
class Cuboid : public ThreeDimensionalShape {
public:
    Cuboid(double width, double height, double depth)
        : ThreeDimensionalShape("Cuboid"), width(width), height(height), depth(depth) {}

    double getArea() const override {
        return 2.0 * (width * height + width * depth + height * depth);
    }

    double getVolume() const override {
        return width * height * depth;
    }

    void print() const override {
        Shape::print();
        cout << " (" << width << " x " << height << " x " << depth << ")";
    }

private:
    double width;
    double height;
    double depth;
};
int main() {
    Shape* shapes[] = {
        new Rectangle(4.0, 3.0),
        new Circle(2.5),
        new Triangle(5.0, 3.0),
        new Sphere(1.5),
        new Cuboid(2.0, 3.0, 4.0)
    };
    int n = sizeof(shapes) / sizeof(shapes[0]);

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; ++i) {
        Shape* shape = shapes[i];
        shape->print();
        cout << "\n";
        cout << "  area = " << shape->getArea() << "\n";

        if (shape->is3D()) {
            cout << "  volume = " << shape->getVolume() << "\n";
        }

        cout << "\n";
    }
    for (int i = 0; i < n; ++i) {
        delete shapes[i];
    }
    return 0;
}
