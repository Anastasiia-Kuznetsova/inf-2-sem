#include <iostream>
#include <vector>
#include <initializer_list>
#include <stack>

struct Test{
    int number;
    float float_number;

    Test(){}

    Test(int n, float f): number(n), float_number(f){
        std::cout << "number: " << number << ", float number: " << float_number << std::endl;
    }

    ~Test(){}
};

template<typename T>
class Stack{
public:
    Stack(): stack(std::vector<T> (0)){}

    void push(const T& value){
        stack.push_back(value);
    }

    template <typename ...Types>
	void emplace(Types&&... args){
		stack.push_back(T(args...));
	}


    unsigned int size() const{
        return stack.size();
    }

    T top() const{
        return stack.back();
    }

    void pop(){
        stack.pop_back();
    }

    ~Stack() = default;

private:
    std::vector<T> stack;
};

std::ostream& operator<<(std::ostream& out, Test test){
    out << "number: " << test.number << ", float number: " << test.float_number;
    return out;
}


int main(){
    Stack<Test> stack;
    std::cout << "stack size: " << stack.size() << "\n";

    std::cout << "pushed struct - ";
    Test test = {71, 2.71};
    stack.push(test);
    std::cout << "stack size: " << stack.size() << "\n";

    std::cout << "emplaced struct - ";
    stack.emplace(42, 3.14);
    std::cout << "emplaced struct - ";
    stack.emplace(28, 1.41);
    std::cout << "stack size: " << stack.size() << "\n";

    std::cout << "top element - " << stack.top() << "\n";

    stack.pop();
    std::cout << "top element after pop - " << stack.top() << "\n";
    std::cout << "stack size: " << stack.size() << "\n";


    return 0;
}
