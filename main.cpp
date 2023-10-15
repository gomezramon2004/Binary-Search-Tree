#include "./bst/bst.hpp"
#include <iostream>
#include <string>

// In this version of the priority queue, I'll use nodes as a container for the dat

int main() {
    try {
        BST bst;
        bst.push(5);
        std::cout << bst.top() << std::endl;
        bst.push(10);
        std::cout << bst.top() << std::endl;
        bst.push(15);
        std::cout << bst.top() << std::endl;
        bst.push(20);
        std::cout << bst.top() << std::endl;
        bst.push(4);
        std::cout << bst.top() << std::endl;

    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}