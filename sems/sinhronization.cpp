#include <iostream>
#include <vector>
#include <thread>
#include<numeric>
#include<mutex>
#include <atomic>
std::mutex mutex;

template<typename T>
class Stack{
public:
    void push(T value){
        std::lock_guard guard(mutex);
        data.push_back(value);
    }

    template <typename ...Types>
	void emplace(Types ...args){
        std::lock_guard guard(mutex);
		data.emplace_back(args...);
	}


    size_t size() const{
        return data.size();
    }

    T top() const{
        std::lock_guard guard(mutex);
        return data.back();
    }

    void pop(){
        std::lock_guard guard(mutex);
        data.pop_back();
    }

    ~Stack() = default;

private:
    std::vector<T> data;
};



const unsigned N = 10'000u;

template<typename T>
void do_actions(Stack<T>& stack){
    for (auto i = 0u; i < N; i++){
        stack.push(T());
    }
    for (auto i = 0u; i < N; i++){
        stack.pop();
    }
}

template<typename Iterator, typename T>
void count_block(Iterator begin, Iterator end, T value, std::atomic<unsigned>& result){
    for(auto it = begin; it != end; it++){
        if (*it == value){
            result ++;
        }
    }
}
template<typename Iterator, typename T>
unsigned parallel_count(Iterator begin, Iterator end, T value){
    auto result = std::atomic<unsigned>(0u);
    auto middle = std::next(begin, std::distance(begin, end) / 2);
    std::thread other (count_block<Iterator, T>, begin, middle, value, std::ref(result));
    count_block<Iterator, T>(middle, end, value, result);
    other.join();
    return result;
}

int main(){
    Stack<int> stack; // overload (2)
    std::vector<std::thread> threads;

    for(auto i = 0u; i < 10 * N; i++){
        stack.push(0);
    }

    for(auto i = 0u; i < std::thread::hardware_concurrency(); i++){
        threads.emplace_back(do_actions<int>, std::ref(stack));
    }

    for(auto& thread: threads){
        thread.join();
    }

    std::cout << stack.size() << "==" << 10 * N << std::endl;

    std::vector<int> values(100 * N);
    std::iota(values.begin(), values.end(), 0);
    for(auto& value: values){
        value%=2;
    }
    std::cout << "Amount of zeros is " << parallel_count(values.begin(), values.end(), 0);
    return 0;
}
