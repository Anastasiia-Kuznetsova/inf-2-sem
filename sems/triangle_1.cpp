#include <iostream>
#include <exception>

class Triangle {
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

    ~Triangle(){
        std::cout << "Hello from Destructor" << std::endl;
    }

    double perimeter() {
        return a + b + c;
    }

private:
    double a, b, c;
};

int main(){
    try {
        Triangle triangle(1, 2, 5);
        std::cout << "Perimeter: " << triangle.perimeter() << std::endl;
    } catch (std::exception& e){
        std::cout << "Exception happened: " << e.what() << std::endl;
    }
}
