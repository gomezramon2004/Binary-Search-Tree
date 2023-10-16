#include "./bst/bst.hpp"
#include "./testcase/testcase.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        // Binary Search Tree Basic Structure - For the testcases

        BST bst;
        addNodes(bst);

        // Visit Testcases

        bst.visit(1);   // First Case
        bst.visit(2);   // Second Case
        bst.visit(3);   // Third Case
        bst.visit(4);   // Four Case

        // Height Testcases

        std::cout << bst.height() << std::endl;     // First Case
        bst.insertNode(1);                          // Second Case
        std::cout << bst.height() << std::endl;
        bst.deleteNode(1), bst.deleteNode(10), bst.deleteNode(18), bst.deleteNode(25), bst.deleteNode(40);      // Third Case
        std::cout << bst.height() << std::endl;
        bst.deleteNode(13), bst.deleteNode(33);     // Fourth Case
        std::cout << bst.height() << std::endl;

        // Ancestors Testcases
        bst.deleteNode(21);
        addNodes(bst);
        bst.ancestors(10);      // First Case
        bst.ancestors(18);      // Second Case
        bst.ancestors(25);      // Third Case
        bst.ancestors(40);      // Fourth Case

        // What level am I Testcases
        bst.insertNode(1); 
        std::cout << bst.whatlevelamI(21) << std::endl; // First Case
        std::cout << bst.whatlevelamI(13) << std::endl;  // Second Case
        std::cout << bst.whatlevelamI(10) << std::endl;  // Third Case
        std::cout << bst.whatlevelamI(1) << std::endl;  // Fourth Case

    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}