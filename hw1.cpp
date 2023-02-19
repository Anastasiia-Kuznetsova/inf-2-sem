#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(os, " "));
	return os;
}

bool isPrime(int a){
    if(a < 2) return false;
    for (auto i = 2; i < sqrt(a + 1); i++) {
        if(a % i == 0) return false;
    }
    return true;
}

int main(){
    std::vector<int> a(10);
    std::iota(a.begin(), a.end(), 1);
    std::cout << "Elements are: " << a << std::endl;
    int x = 0;
    for(auto i = 0; i < 5; i++){
        std::cin >> x;
        a.push_back(x);
    }
    std::cout << "New elements are: " << a << std::endl;
    std::random_shuffle(a.begin(), a.end());
    std::cout << "Shuffle elements are: " << a << std::endl;
    std::cout << "Number of odd numbers: " << std::count_if(a.begin(), a.end(), [](int i){return i % 2 == 1;}) << std::endl;
    std::cout << "Max element is: " << *minmax_element(a.begin(), a.end()).second << " Min element is: " << *minmax_element(a.begin(), a.end()).first<< std::endl;
    std::cout << "Prime number: " << *std::find_if(a.begin(), a.end(), isPrime) << std::endl;
    auto squares = std::vector<int>(a.size());
    std::transform(a.begin(), a.end(), a.begin(), [](auto i){return i * i;});
    std::cout << "Squares elements are: " << a << std::endl;
    std::cout << "Sum of elements is " << std::accumulate(a.begin(), a.end(), 0) << std::endl;
    std::replace_if(a.begin(), a.begin() + 3, [](auto i){return i != 1;}, 1);
    std::cout << "Replace elements: " << a << std::endl;
    a.erase(std::remove_if (a.begin(), a.end(),[](auto i){return i == 0;}), a.end());
    std::cout << "Erase: " << a << std::endl;
    std::reverse(a.begin(), a.end());
    std::cout << "Reverse: " << a << std::endl;
    std::partial_sort(a.begin(), a.begin() + 3, a.end(), std::greater<int>());
    std::cout << "3 largest elements: " << a[0] << " " << a[1] << " " << a[2] << std::endl;
    std::sort(a.begin(), a.end());
    std::cout << "Sorted: " << a << std::endl;
    auto p = std::equal_range(a.begin(), a.end(), 3);
    std::cout << "Index of first element: " << p.first - a.begin() << " Index of last element: " << p.second - a.begin();
    return 0;
}
