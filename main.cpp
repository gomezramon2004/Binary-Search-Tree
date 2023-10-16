#include "./bst/bst.hpp"
#include <iostream>
#include <string>

// In this version of the priority queue, I'll use nodes as a container for the dat

int main() {
    try {
        BST bst;
        bst.insertNode(21);
        bst.insertNode(13);
        bst.insertNode(33);
        bst.insertNode(10);
        bst.insertNode(18);
        bst.insertNode(25);
        bst.insertNode(40);
        bst.insertNode(1);

        std::cout << "Top: " << bst.root->data << std::endl;
        std::cout << bst.root->left->data << std::endl;
        std::cout << bst.root->right->data << std::endl;
        std::cout << bst.root->left->left->data << std::endl;
        std::cout << bst.root->left->right->data << std::endl;
        std::cout << bst.root->right->left->data << std::endl;
        std::cout << bst.root->right->right->data << std::endl;

        std::cout << bst.height() << std::endl;
        std::cout << bst.whatlevelamI() << std::endl;

    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}