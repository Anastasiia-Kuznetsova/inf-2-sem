#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Rational {
public:
    // ����������� �����, ����� a - ���������, b - �����������
    Rational(int a, int b): a(a), b(b){}


    // ���������� ���������:
    // - �������� ���� ������
    auto operator+(Rational other){
        return Rational(a * other.b+ b * other.a, b * other.b);
    }
    // - ��������� ���� ������
    Rational operator-(Rational other){
        return {a*other.b - b * other.a, b * other.b};
    }
    // - ��������� ���� ������
    auto operator*(Rational other){
        return Rational(a* other.a, b * other.b);
    }
    auto operator/(Rational other){
        return Rational(a * other.b, b * other.a);
    }
    // - ������� ���� ������
    // - ��������� ����� �� ����� ����� (������ �������� ��� ����� ������� ���������)
    auto operator*(int number){
        return Rational(a*number, b);
    }
    friend std::ostream& operator<<(std::ostream&, Rational r);
private:
    int a, b;
};

auto operator*(int number, Rational rational){
    return rational * number;
}

std::ostream& operator<<(std::ostream& os, Rational r){
    return os << r.a << '/' << r.b;
}

int main(){
    Rational a(1, 2);
    Rational b(2, 3);

    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;

    return 0;
}
