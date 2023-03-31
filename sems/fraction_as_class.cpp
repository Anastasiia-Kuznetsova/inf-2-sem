#include <iostream>

struct Fraction {
    int numerator;
    unsigned denominator;
public:
    Fraction(int numerator, unsigned denominator){
        if(denominator == 0) denominator = 1;
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    Fraction(int number){
        numerator = number;
        denominator = 1u;
    }

    Fraction operator+(Fraction other){
        return Fraction{int(numerator * (int)other.denominator + other.numerator * (int)denominator),
                    other.denominator * denominator};
    }
    void print(){
        std::cout << numerator << "/" << denominator << "\n";
    }
};


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
    Fraction fraction(-1,3);
    Fraction sum = fraction.add({3, 5});
    sum.print();
    return 0;
}
