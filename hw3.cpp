#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <future>
#include <typeinfo>

const size_t BORDER_SIZE = 1000u;


using steady_clock = std::chrono::steady_clock;

class Timer {
public:
	Timer(): start(steady_clock::now()) {}

	~Timer() {
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(steady_clock::now() - start).count() << std::endl;
	}
private:
	steady_clock::time_point start;
};

template<typename Iter, typename T>
T parallel_accumulate(Iter begin, Iter end, T init, int num_threads){
    auto size = std::distance(begin, end);
    if(size <= BORDER_SIZE) return std::accumulate(begin, end, init);

    auto block_size = size / num_threads;
    std::vector<std::future<T>> results;

    for (auto i = 0u; i + 1 < num_threads; i++){
        results.push_back(std::async(std::launch::async, std::accumulate<Iter, T>, std::next(begin, i*block_size), std::next(begin, (i+1)*block_size), 0));
    }
    unsigned long long int result = std::accumulate(std::next(begin, (num_threads - 1) * block_size), end, init);
    for(auto i = 0; i + 1< num_threads; i ++){
        result += results[i].get();
    }

    return result;

}

int main(){
    std::vector<unsigned long long int> numbers(65'000u);

    std::iota(numbers.begin(), numbers.end(), 1);
    for(auto i = 1; i <  25; i++){
        {
            Timer t;
            parallel_accumulate(numbers.begin(), numbers.end(), 0, i);
        }
    }
}
