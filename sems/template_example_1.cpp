#include <iostream>
#include <vector>
//������ ����
template<typename T>
using matrix = std::vector<std::vector<T>>;

//������ ����������
template<typename T>
const T pi = 3.1415;

//������ �������
template<typename T1, typename T2>
auto mul(T1 lhs, T2 rhs){
    return lhs * rhs;
}

template<typename T>
void _print(T first){
    std::cout << first << std::endl;
}

template<typename T, typename ...Types>
void _print(T first, Types ...others){
    std::cout << first << ' ';
    _print(others...);
}

template<typename ...Types>
void print(Types ...args){
    _print(args...);
}

int main(){
    print(1, 1.5, "dasr", false);
    return 0;
}
