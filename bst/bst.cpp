#include "bst.hpp"
#include <algorithm> 
#include <iostream>

// Implementation of queue Methods
Node::Node(int data) : data(data), left(nullptr), right(nullptr), prev(nullptr) {}


// Implementation of BST Methods

// Helper function for compare nodes
void BST::compareNodes(Node* currentNode, Node* newNode) {
    if (root->data == newNode->data) {
        throw std::runtime_error("ERROR: Node already exists");
    }

    if (newNode->data > currentNode->data) {
        if (currentNode->right) {
            compareNodes(currentNode->right, newNode);
        } else {
            currentNode->right = newNode;
            newNode->prev = currentNode;
        }
    } else {
        if (currentNode->left) {
            compareNodes(currentNode->left, newNode);
        } else {
            currentNode->left = newNode;
            newNode->prev = currentNode;
        }
    }
}

// Constructor
BST::BST() : currentLength(0), root(nullptr) {}

// Pushing to BST
void BST::insertNode(int data) {  
    Node* newNode = new Node(data);                   
    if (empty()) {
        root = newNode;
    } else {
        compareNodes(root, newNode);
    }
    currentLength++;
}

// Popping from BST
void BST::pop() {                                                                  

}

// Peeking at top of BST
int BST::top() {                                                          
    if (empty()) { 
        throw std::runtime_error("ERROR: Priority Queue is empty");
    }
    return root->data;
}

// Check if BST is empty 
bool BST::empty() {                                                                  
    return !root;
}

// Get size of BST
int BST::size() {                                                                     
    return currentLength;
}