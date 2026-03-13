#include <iostream>
#include "include/sstl.hpp"
int main() {
    sstl::vec<int> v;
    v.reserve(10);
    v.resize(5);

    for (int i = 0; i < v.size(); i++) {
        v[i] = i*2;
    }
    for (int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }

    for (int i = 5; i < 20; ++i) {
        v.push_back(i);
    }

    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Cap: " << v.capacity() << std::endl;
    return 0;
}