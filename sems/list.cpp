#include <iostream>
template<typename T>
struct list {
    struct node {
        node(T new_value){
            next = nullptr;
            prev = nullptr;
            value = new_value;
        }

        node(T new_value, node* new_next, node* new_prev){
            next = new_next;
            prev = new_prev;
            value = new_value;
        }

        node* next;
        node* prev;
        T value;
    };
    node* root;

    list() {
        root = new node(T());
    }

    void print() {
        auto current = root;
        for(;current->next;){
            std::cout << current->next->value << " ";
            current = current->next;
        }

    }

    void push_back(T value){
        auto current = root;
        for(; current->next;){
            current = current->next;
        }
        current->next = new node(value, nullptr, current);
    }


    ~list() {
        for(auto current = root;current;){
            auto next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    list <double>l;
    int n;
    std::cin >> n;
    for (auto i = 0; i < n; i ++){
        double tmp;
        std::cin>>tmp;
        l.push_back(tmp);
    }
    l.print();
    return 0;
}
