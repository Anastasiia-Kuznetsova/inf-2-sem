#include <iostream>
#include <cmath>

class MathMixin {
public:
    const double pi() const{
        return std::acos(-1);
    }

    double approximate_ellipse_perimeter(double a, double b) const{
        return pi() * std::sqrt(2 * (a * a + b * b));
    }
    double heronsformula(double a, double b, double c) const{
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Figure {
public:
    virtual double perimeter() const = 0;
    virtual double square() const = 0;

};

class Ellipse: public Figure, private MathMixin{
public:
    Ellipse(double a, double b): a(a), b(b){}
    double perimeter() const override {
        return approximate_ellipse_perimeter(a, b);
    }
    double square() const override {
        return pi() * a * b;
    }
private:
    double a,b;
};

class Circle: public Ellipse {
public:
    Circle(double r): Ellipse(r, r){}
};

class Triangle: public Figure, private MathMixin{
public:
    Triangle(double a, double b, double c){
        if (a + b >= c && a + c >= b && b + c >= a) {
            this->a = a;
            this->b = b;
            this->c = c;
        } else {
            throw std::invalid_argument("Bad sides given");
        }
    }
    double perimeter() const override {
        return a + b+ c;
    }
    double square() const override {
        return heronsformula(a, b, c);
    }
private:
    double a,b,c;
};

class IsoscelesTriangle:public Triangle{
public:
    IsoscelesTriangle(double a, double b): Triangle(a, a, b){};
};

class EquilateralTriangle:public Triangle{
public:
    EquilateralTriangle(double a): Triangle(a, a, a){}
};

class Rectangle: public Figure{
public:
    Rectangle(double a, double b): a(a), b(b){}
    double perimeter() const override {
        return (a + b) * 2;
    }
    double square() const override {
        return a * b;
    }
private:
    double a, b;
};

class Square: public Rectangle{
public:
    Square(double a): Rectangle(a, a){};
};

int main(){
    Ellipse ellipse(4,5);
    std::cout <<"Ellipse perimeter: "<< ellipse.perimeter() << ", square: " << ellipse.square() << std::endl;
    Circle circle(3);
    std::cout <<"Circle perimeter: "<< circle.perimeter() << ", square" << circle.square() << std::endl;

    try {
        Triangle triangle(3, 4, 6);
        std::cout << "Triangle perimeter: "<<triangle.perimeter() << ", square: " << triangle.square() << std::endl;
    } catch (std::exception& e){
        std::cout << "Exception happened: " << e.what() << std::endl;
    }

    try {
        IsoscelesTriangle isoscelestriangle(4, 3);;
        std::cout << "Isosceles triangle perimeter: "<<isoscelestriangle.perimeter() <<", square: " << isoscelestriangle.square() <<std::endl;
    } catch (std::exception& e){
        std::cout << "Exception happened: " << e.what() << std::endl;
    }

    EquilateralTriangle equilaterialtriangle(3);
    std::cout << "Equilaterial triangle perimeter: "<<equilaterialtriangle.perimeter() <<", square: " << equilaterialtriangle.square() <<std::endl;

    Rectangle rectangle(3,4);
    std::cout << "Rectangle perimeter: " << rectangle.perimeter() << ", square: " << rectangle.square() << std::endl;
    Square square(3);
    std::cout << "Square perimeter: " << square.perimeter() << ", square: " << square.square() << std::endl;
}
