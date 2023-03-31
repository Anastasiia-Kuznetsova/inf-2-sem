#include <iostream>
#include <chrono>
#include <cmath>

template <typename Type> class ConstValue{
public:
    ConstValue(Type new_value): value(new_value){
    }
private:
    const int value;
};

class Timer {
public:
    Timer(): start(std::chrono::steady_clock::now()){}
    ~Timer(){
        std::cout << "Elapsed time: " << ((std::chrono::steady_clock::now()) - start).count() << std::endl;
    }
private:
    std::chrono::steady_clock::time_point start;
};


int main() {
    ConstValue<int> value(5);
    auto sum = 0.;
    {
         Timer t;
         for (auto i = 0; i < 1'000'000; i++) sum += std::sin(i) + std::cos(i);
    }
    std::cout << "Sum: " << sum << std::endl;
}
