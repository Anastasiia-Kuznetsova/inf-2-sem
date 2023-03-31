#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>

std::vector<int> merge(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    std::vector<int> merged;
    auto i = 0, j = 0;
    for (; i < lhs.size() && j < rhs.size();){
        if (lhs[i] < rhs[j]) merged.push_back(lhs[i++]);
        else merged.push_back(rhs[j++]);
    }
    for(; i < lhs.size(); merged.push_back(lhs[i++]));
    for(; j < rhs.size(); merged.push_back(rhs[j++]));
    return merged;
}

std::vector<int> merge_sort(const std::vector<int>& array){
    if (array.size() > 1){
        auto middle = array.size() / 2;
        std::vector<int> left, right;
        for (auto i =0 ; i < middle; i++) left.push_back(array[i]);
        for (auto i = middle; i < array.size(); i++) right.push_back(array[i]);
        auto sorted_left = merge_sort(left);
        auto sorted_right = merge_sort(right);
        return merge(sorted_left, sorted_right);
     }
    return array;
}

std::vector<int> merger(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    std::vector<int> merged;
    auto i = 0, j = 0;
    for (; i < lhs.size() && j < rhs.size();){
        if (lhs[i] > rhs[j]) merged.push_back(lhs[i++]);
        else merged.push_back(rhs[j++]);
    }
    for(; i < lhs.size(); merged.push_back(lhs[i++]));
    for(; j < rhs.size(); merged.push_back(rhs[j++]));
    return merged;
}

std::vector<int> merge_sortr(const std::vector<int>& array){
    if (array.size() > 1){
        auto middle = array.size() / 2;
        std::vector<int> left, right;
        for (auto i =0 ; i < middle; i++) left.push_back(array[i]);
        for (auto i = middle; i < array.size(); i++) right.push_back(array[i]);
        auto sorted_left = merge_sortr(left);
        auto sorted_right = merge_sortr(right);
        return merger(sorted_left, sorted_right);
     }
    return array;
}

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}


std::ofstream f("1.csv", std::ios::out);
struct Timer {

    std::chrono::high_resolution_clock::time_point start;

    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer(){
        auto end = std::chrono::high_resolution_clock::now();
        f << (end - start).count() << std::endl;
    }

};


int main(){
    std::vector<int> a;
    std::vector<int> result;
    for (int i = 1; i < 1e3; i++){
        int x = rand_uns(0, 1e6);
        a.push_back(x);
        {
        Timer t;
        merge_sort(a);
        }
    }
}
