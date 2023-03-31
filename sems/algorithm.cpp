#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
std::ostream& operator<<(std::ostream& os, std::vector<int>& v){
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(os, " "));
    return os;
}

int main() {
    //Возвращаем произведение
    std::vector<int> array;
    for (auto i = 0; i < 10; array.push_back(i++));
    std::cout << "Product of elements is " << std::accumulate(std::next(array.begin()), array.end(), 1ll, [](auto lhs, auto rhs){return lhs * rhs;}) << std::endl;
    std::cout << array << std::endl;
    //Переворачиваем массив
    std::vector<int> other;
    other.resize(array.size());
    std::reverse_copy(array.begin(), array.end(), other.begin());
    std::cout << other << std::endl;
    //Ищем максимум
    std::cout << *std::max_element(other.begin(), other.end()) << std::endl;
    //Удаляем нечётные
    auto remove_iter = std::remove_if(other.begin(), other.end(), [](auto item){return item % 2;});
    other.erase(remove_iter, other.end());
    std::cout << other << std::endl;
    //Возводим элементы в квадрат
    auto squares = std::vector<int>(array.size());
    std::transform(array.begin(), array.end(), squares.begin(), [](auto item){return item * item;});
    std::cout << squares << std::endl;
    //Скалярное произведение (массив сумм)
    auto element_sums = std::vector<int>();
    std::transform(array.begin(), array.end(), squares.begin(), std::back_inserter(element_sums), [](auto lhs, auto rhs){return lhs * rhs;});
    std::cout << "Cubes " << element_sums << std::endl;
    std::cout << "Scalar product is " << std::accumulate(element_sums.begin(), element_sums.end(), 0) << std::endl;
}
