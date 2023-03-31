#include <iostream>

struct Fraction {
    int numerator;
    unsigned denominator;
};

void print_fraction(Fraction fraction) {
    std::cout << fraction.numerator << " / " << fraction.denominator << std::endl;
}

Fraction operator+(Fraction left, Fraction right){
    return Fraction{int(left.numerator * right.denominator + right.numerator * left.denominator),
                    right.denominator * left.denominator};
}

Fraction operator+(Fraction left, int right){
    return Fraction{int(left.numerator + right * left.denominator),
                    left.denominator};
}

Fraction operator+(int left, Fraction right){
    return right + left;
}

Fraction operator-(Fraction left, Fraction right){
    return Fraction{int(left.numerator * right.denominator - right.numerator * left.denominator),
                    right.denominator * left.denominator};
}

Fraction operator*(Fraction left, Fraction right){
    return Fraction{left.numerator * right.numerator, right.denominator * left.denominator};
}

Fraction operator/(Fraction left, Fraction right){
    return Fraction{int(left.numerator * right.denominator), (right.numerator * left.denominator)};
}

std::istream& operator>>(std::istream& in, Fraction& fraction){
    char trash;
    in >> fraction.numerator >> trash >> fraction.denominator;
    return in;
}

std::ostream& operator<<(std::ostream& out, Fraction fraction){
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

int main(){
    Fraction first, second;
    std::cin >> first >> second;
    std::cout << second << std::endl;
    std::cout << 1 + first + 3 << std::endl;
    return 0;
}

