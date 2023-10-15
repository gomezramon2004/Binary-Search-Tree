#include "bst.hpp"
#include <algorithm> 
#include <iostream>

// Implementation of queue Methods

Node::Node(int data) : data(data), left(nullptr), right(nullptr), prev(nullptr) {}


// Implementation of BST Methods

// Constructor
BST::BST() : currentLength(0), front(nullptr), rear(nullptr) {}

// Pushing to BST
void BST::push(int data) {                     

}

// Popping from BST
void BST::pop() {                                                                  

}

// Peeking at top of BST
int BST::top() {                                                          
    if (empty()) { 
        throw std::runtime_error("ERROR: Priority Queue is empty");
    }
    return front->data;
}

// Check if BST is empty 
bool BST::empty() {                                                                  
    return !front;
}

// Get size of BST
int BST::size() {                                                                     
    return currentLength;
}