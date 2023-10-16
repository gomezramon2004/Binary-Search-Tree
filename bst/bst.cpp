#include "bst.hpp"
#include <algorithm> 
#include <iostream>

// Implementation of queue Methods
Node::Node(int data) : data(data), level(0), left(nullptr), right(nullptr), prev(nullptr) {}


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
            newNode->level = currentNode->level + 1;
        }
    } else {
        if (currentNode->left) {
            compareNodes(currentNode->left, newNode);
        } else {
            currentNode->left = newNode;
            newNode->prev = currentNode;
            newNode->level = currentNode->level + 1;
        }
    }
}

// Helper function for search node
Node* BST::searchNode(int data, Node* currentNode) {
    if (currentNode->data == data) {
        return currentNode;
    } else if (data > currentNode->data) {
        return searchNode(data, currentNode->right);
    } else if (data < currentNode->data) {
        return searchNode(data, currentNode->left);
    } else {
        throw std::runtime_error("ERROR: Node not found");
    }
}

// Helper function for delete node

void BST::deleteLeaftNode(Node* currentNode) {
   if (currentNode->prev->left == currentNode) {
        currentNode->prev->left = nullptr;
    } else {
        currentNode->prev->right = nullptr;
    }
    delete currentNode;
}

void BST::deleteNodeWithLeftChild(Node* currentNode) {
    currentNode->left->prev = currentNode->prev;
    if (currentNode->prev->left == currentNode) {
        currentNode->prev->left = currentNode->left;
    } else {
        currentNode->prev->right = currentNode->left;
    }
    delete currentNode;
}

void BST::deleteNodeWithRightChild(Node* currentNode) {
    currentNode->right->prev = currentNode->prev;
    if (currentNode->prev->left == currentNode) {
        currentNode->prev->left = currentNode->right;
    } else {
        currentNode->prev->right = currentNode->right;
    }
    delete currentNode;
}

void BST::deleteNodeWithTwoChildren(Node* currentNode) {
    Node* minRightNode = minRight(currentNode);
    currentNode->data = minRightNode->data;
    if (minRightNode->prev->left == minRightNode) {
        minRightNode->prev->left = minRightNode->right;
    } else {
        minRightNode->prev->right = minRightNode->right;
    }
    if (minRightNode->right) {
        minRightNode->right->prev = minRightNode->prev;
    }
    delete minRightNode;
}

Node* BST::minRight(Node* currentNode) {
    Node* temp = currentNode->right;
    while (temp->left) {
        temp = temp->left;
    }
    return temp;
}

void BST::updateDecrementedHeight(Node* currentNode) {
    if (!currentNode) {
        return;
    }
    int leftHeight = currentNode->left ? currentNode->left->level : 0;
    int rightHeight = currentNode->right ? currentNode->right->level : 0;
    currentNode->level = std::max(leftHeight, rightHeight) + 1;
    currentHeight = std::max(currentHeight, currentNode->level);
    updateDecrementedHeight(currentNode->prev);
}

// Constructor
BST::BST() : currentLength(0), root(nullptr) {}

// Insert node to BST
void BST::insertNode(int data) {  
    Node* newNode = new Node(data);                   
    if (empty()) {
        root = newNode;
    } else {
        compareNodes(root, newNode);
        currentHeight = std::max(currentHeight, newNode->level);
    }
    currentLength++;
}

// Delete node to BST
void BST::deleteNode(int data) {      
    if (empty()) {
        throw std::runtime_error("ERROR: Priority Queue is empty");
    }

    Node* currentNode = root;                                        // Find the node to delete
    while (currentNode && currentNode->data != data) {
        if (data > currentNode->data) {
            currentNode = currentNode->right;
        } else {
            currentNode = currentNode->left;
        }
    }

    if (!currentNode->left && !currentNode->right) {                // Delete a leaf node           
        deleteLeaftNode(currentNode);
    } else if (currentNode->left && currentNode->right) {           // Delete a node with two children
        deleteNodeWithTwoChildren(currentNode);
    } else {                                                        // Delete a node with one children
        if (!currentNode->right) {
            deleteNodeWithLeftChild(currentNode);
        } else {
            deleteNodeWithRightChild(currentNode);
        }        
    }
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

// Get height of BST
int BST::height() {
    return currentHeight;
}

// Get the level of a node
int BST::whatlevelamI(int data) {
    Node* currentNode = searchNode(data, root);
    return currentNode->level;
}