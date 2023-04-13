#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <mutex>
#include <algorithm>
#include <random>

std::mutex count_mutex;

const size_t BORDER_SIZE = 1000u;

template <typename Iterator, typename T>
void count_block(Iterator begin, Iterator end, T& result) {
    auto new_result =  *std::min_element(begin, end);
    std::mutex mutex;
    std::lock_guard guard(mutex);
    result = (new_result < result) ? new_result:result;
}

template<typename Iterator>
unsigned parallel_count(Iterator begin, Iterator end) {
	auto result = *begin;

    auto size = std::distance(begin, end);
    if(size <= BORDER_SIZE) return *std::min_element(begin, end);

    auto num_threads = std::thread::hardware_concurrency();
    auto block_size = size / num_threads;

    std::vector<std::thread> threads;
    for (auto i = 0u; i + 1 < num_threads; i++) {
        threads.emplace_back(count_block<Iterator, decltype(result)>, std::next(begin, i * block_size), std::next(begin,(i + 1) * block_size), std::ref(result));
    }
    for (auto& thread : threads) {
        thread.join();
    }

	return result;
}


int main() {
    std::vector<int> vec(100000);

    std::iota(vec.begin(), vec.end(), 0);
    std::shuffle(vec.begin(), vec.end(), std::random_device());
    std::cout << "Min element using parallel count: "<< parallel_count(vec.begin(), vec.end()) << std::endl;
    std::cout << "Min element: " <<*std::min_element(vec.begin(), vec.end()) << std::endl;

    return 0;
}
