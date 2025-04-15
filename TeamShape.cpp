#include <iostream>
#include <cmath>
using namespace std;

// Эх класс: Shape
class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}  // ":" Инициализ бол тухайн хувьсагчийг анх үүсэхэд нь шууд утга өгөх.
    virtual double getArea() = 0; 
    virtual void display() = 0;
};


class TwoDShape : public Shape {
protected:
    double x, y;

public:
    TwoDShape(string n, double xPos, double yPos) : Shape(n), x(xPos), y(yPos) {} // ":" Инициализ бол тухайн хувьсагчийг анх үүсэхэд нь шууд утга өгөх.
};

// Circle class
class Circle : public TwoDShape {
private:
    double radius;

public:
    Circle(double x, double y, double r) : TwoDShape("Circle", x, y), radius(r) {} // ":" Инициализ бол тухайн хувьсагчийг анх үүсэхэд нь шууд утга өгөх.

    double getArea() override {
        return 3.14159 * radius * radius;
    }

    double getCircumference() {
        return 2 * 3.14159 * radius;
    }

    void display() override {
        cout << name << " at (" << x << ", " << y << ") with radius " << radius << endl;
        cout << "Area: " << getArea() << ", Circumference: " << getCircumference() << endl;
    }
};

// Square class
class Square : public TwoDShape {
private:
    double side;

public:
    Square(double x, double y, double s) : TwoDShape("Square", x, y), side(s) {} // Хувьсагчийг анхдагч (эхний) утгаар тохируулах үйлдэл.

    double getArea() override {
        return side * side;
    }

    double getPerimeter() {
        return 4 * side;
    }

    void display() override {
        cout << name << " at (" << x << ", " << y << ") with side " << side << endl;
        cout << "Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

// Triangle class
class Triangle : public TwoDShape {
private:
    double side;

public:
    Triangle(double x, double y, double s) : TwoDShape("Triangle", x, y), side(s) {} // Хувьсагчийг анхдагч (эхний) утгаар тохируулах үйлдэл.

    double getArea() override {
        return (sqrt(3) / 4) * side * side;
    }

    double getPerimeter() {
        return 3 * side;
    }

    void display() override {
        cout << name << " at (" << x << ", " << y << ") with side " << side << endl;
        cout << "Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

// Main function
int main() {
    Circle c(0, 0, 5);
    Square s(1, 1, 4);
    Triangle t(2, 2, 3);
    
    // TwoDShape* d[3]; // TwoDShape классын заагч массив 
    TwoDShape* d[3];
    d[0] = &c;
    d[1] = &s;
    d[2] = &t;

    // area-р эрэмбэлэх Bubble Sort
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (d[i]->getArea() > d[j]->getArea()) {
                TwoDShape* temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }

    // эрэмбэлсэн хэлбэрүүдийг хэвлэх
        for (int i = 0; i < 3; i++) {
        d[i]->display();
        cout << "-----------------" << endl;
    }

    return 0;
}
