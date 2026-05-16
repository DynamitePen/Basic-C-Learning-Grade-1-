#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.14159265358979323846
class Point {
public:
double x, y;
Point(double x = 0, double y = 0) : x(x), y(y) {}
};
class Shape {
private:
    string id;
public:
    Shape(const string& id) : id(id) {}
    
    ~Shape() {
        cout << "Shape destructor id: " << id << endl;
    }
    
    string getId() const { return id; }
    
    double area() const {
        return 0.0;
    }
    
    void print() const {
        cout << "ID: " << id << endl;
    }
};
// Circle 类
class Circle : public Shape {
private:
    Point centerOfCircle;
    double radius;
public:
    Circle(const string& id, double cx, double cy, double r) 
        : Shape(id), centerOfCircle(cx, cy), radius(r) {}
    
    ~Circle() {
        cout << "Circle destructor id: " << getId() << endl;
    }
    
    double area() const {
        return PI * radius * radius;
    }
    
    void print() const {
        Shape::print();
        cout << "Type: Circle" << endl;
        cout << "Center: (" << centerOfCircle.x << ", " << centerOfCircle.y << ")" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << fixed << setprecision(2) << area() << endl;
    }
    
    Point getCenter() const { return centerOfCircle; }
    double getRadius() const { return radius; }
};

// Rectangle 类
class Rectangle : public Shape {
private:
    Point leftTop;
    Point rightBottom;
public:
    Rectangle(const string& id, double x1, double y1, double x2, double y2)
        : Shape(id), leftTop(x1, y1), rightBottom(x2, y2) {}
    
    ~Rectangle() {
        cout << "Rectangle destructor id: " << getId() << endl;
    }
    
    double area() const {
        double width = abs(rightBottom.x - leftTop.x);
        double height = abs(rightBottom.y - leftTop.y);
        return width * height;
    }
    
    void print() const {
        Shape::print();
        cout << "Type: Rectangle" << endl;
        cout << "Top-Left: (" << leftTop.x << ", " << leftTop.y << ")" << endl;
        cout << "Bottom-Right: (" << rightBottom.x << ", " << rightBottom.y << ")" << endl;
        cout << "Width: " << abs(rightBottom.x - leftTop.x) << endl;
        cout << "Height: " << abs(rightBottom.y - leftTop.y) << endl;
        cout << "Area: " << fixed << setprecision(2) << area() << endl;
    }
    
    double getWidth() const { return abs(rightBottom.x - leftTop.x); }
    double getHeight() const { return abs(rightBottom.y - leftTop.y); }
    Point getLeftTop() const { return leftTop; }
    Point getRightBottom() const { return rightBottom; }
};

// Triangle 类
class Triangle : public Shape {
private:
    Point leftTop;
    Point rightBottom;
    Point thirdPoint;
public:
    Triangle(const string& id, double x1, double y1, double x2, double y2, double x3, double y3)
        : Shape(id), leftTop(x1, y1), rightBottom(x2, y2), thirdPoint(x3, y3) {}
    
    ~Triangle() {
        cout << "Triangle destructor id: " << getId() << endl;
    }
    
    double area() const {
        double a = sqrt((leftTop.x - rightBottom.x) * (leftTop.x - rightBottom.x) + (leftTop.y - rightBottom.y) * (leftTop.y - rightBottom.y));
        double b = sqrt((rightBottom.x - thirdPoint.x) * (rightBottom.x - thirdPoint.x) + (rightBottom.y - thirdPoint.y) * (rightBottom.y - thirdPoint.y));
        double c = sqrt((thirdPoint.x - leftTop.x) * (thirdPoint.x - leftTop.x) + (thirdPoint.y - leftTop.y) * (thirdPoint.y - leftTop.y));
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    void print() const {
        Shape::print();
        cout << "Type: Triangle" << endl;
        cout << "Point 1: (" << leftTop.x << ", " << leftTop.y << ")" << endl;
        cout << "Point 2: (" << rightBottom.x << ", " << rightBottom.y << ")" << endl;
        cout << "Point 3: (" << thirdPoint.x << ", " << thirdPoint.y << ")" << endl;
        cout << "Area: " << fixed << setprecision(2) << area() << endl;
    }
};

// Square 类
class Square : public Rectangle {
public:
    Square(const string& id, double x1, double y1, double sideLength)
        : Rectangle(id, x1, y1, x1 + sideLength, y1 + sideLength) {}
    
    ~Square() {
        cout << "Square destructor id: " << getId() << endl;
    }
    
    // 创建并返回内切圆对象
    Circle incircle() const {
        double sideLength = getWidth();
        Point topLeft = getLeftTop();
        double cx = topLeft.x + sideLength / 2;
        double cy = topLeft.y + sideLength / 2;
        double radius = sideLength / 2;
        return Circle(getId() + "_incircle", cx, cy, radius);
    }
    
    void print() const {
        Shape::print();
        cout << "Type: Square" << endl;
        cout << "Top-Left: (" << getLeftTop().x << ", " << getLeftTop().y << ")" << endl;
        cout << "Bottom-Right: (" << getRightBottom().x << ", " << getRightBottom().y << ")" << endl;
        cout << "Side Length: " << getWidth() << endl;
        cout << "Area: " << fixed << setprecision(2) << area() << endl;
    }
};

// 测试程序
int main() {
    cout << "===== Shape Hierarchy Test =====" << endl << endl;
    
    // 创建 Circle 对象
    cout << "--- Creating Circle ---" << endl;
    Circle c1("circle1", 5.0, 5.0, 3.0);
    c1.print();
    cout << endl;
    
    // 创建 Rectangle 对象
    cout << "--- Creating Rectangle ---" << endl;
    Rectangle r1("rect1", 0.0, 0.0, 10.0, 5.0);
    r1.print();
    cout << endl;
    
    // 创建 Triangle 对象
    cout << "--- Creating Triangle ---" << endl;
    Triangle t1("triangle1", 0.0, 0.0, 4.0, 0.0, 2.0, 3.0);
    t1.print();
    cout << endl;
    
    // 创建 Square 对象
    cout << "--- Creating Square ---" << endl;
    Square s1("square1", 0.0, 0.0, 6.0);
    s1.print();
    cout << endl;
    
    // Square 的内切圆
    cout << "--- Square's Incircle ---" << endl;
    Circle incircle = s1.incircle();
    incircle.print();
    cout << endl;
    
    // 使用具体对象调用各自的方法
    cout << "--- Calling area() for each shape ---" << endl;
    cout << "Circle area: " << fixed << setprecision(2) << c1.area() << endl;
    cout << "Rectangle area: " << fixed << setprecision(2) << r1.area() << endl;
    cout << "Triangle area: " << fixed << setprecision(2) << t1.area() << endl;
    cout << "Square area: " << fixed << setprecision(2) << s1.area() << endl;
    cout << endl;
    
    cout << "===== End of Test =====" << endl;
    
    return 0;
}
