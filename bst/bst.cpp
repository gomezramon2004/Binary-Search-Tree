#include "bst.hpp"
#include <algorithm> 
#include <iostream>
#include <queue>

// Constructor of Node
Node::Node(int data) : data(data), level(0), left(nullptr), right(nullptr), prev(nullptr) {}

// Compare nodes in BST
void BST::compareNodes(Node* currentNode, Node* newNode) {
    if (root->data == newNode->data) throw std::runtime_error("ERROR: Node already exists");

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

// Search node in BST
Node* BST::searchNode(int data, Node* currentNode, bool isLevel) {
    if (!currentNode) {
        if (!isLevel) throw std::runtime_error("ERROR: Node not found");
        Node* temp = new Node(data);
        temp->level = -1;
        return temp;
    }
    
    if (currentNode->data == data) { 
        return currentNode; 
    } else if (data > currentNode->data) { 
        return searchNode(data, currentNode->right, isLevel); 
    } else {
        return searchNode(data, currentNode->left, isLevel); 
    }
}

// Delete leaf node
void BST::deleteLeaftNode(Node* currentNode) {
    if (currentNode == root) {
        root = nullptr;
    } else if (currentNode->prev->left == currentNode) {
        currentNode->prev->left = nullptr;
    } else {
        currentNode->prev->right = nullptr;
    }
    delete currentNode;
}

// Delete node with left child
void BST::deleteNodeWithLeftChild(Node* currentNode) {
    currentNode->left->prev = currentNode->prev;
    currentNode->prev->left == currentNode ? currentNode->prev->left = currentNode->left : currentNode->prev->right = currentNode->left;
    delete currentNode;
}

// Delete node with right child
void BST::deleteNodeWithRightChild(Node* currentNode) {
    currentNode->right->prev = currentNode->prev;
    currentNode->prev->left == currentNode ? currentNode->prev->left = currentNode->right : currentNode->prev->right = currentNode->right;
    delete currentNode;
}

// Delete node with two children
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

// Calculate min right node
Node* BST::minRight(Node* currentNode) {
    Node* temp = currentNode->right;
    while (temp->left) {
        temp = temp->left;
    }
    return temp;
}

// Calculate height of BST
int BST::calculateHeight(Node* currentNode) {
    if (!currentNode) return 0;
    int leftHeight = calculateHeight(currentNode->left);
    int rightHeight = calculateHeight(currentNode->right);
    return 1 + std::max(leftHeight, rightHeight);
}

// Helper function for preorder
void BST::preorder(Node* currentNode) {
    if (!currentNode) return;
    std::cout << currentNode->data << " ";
    preorder(currentNode->left);
    preorder(currentNode->right);
}

// Helper function for inorder
void BST::inorder(Node* currentNode) {
    if (!currentNode) return;
    inorder(currentNode->left);
    std::cout << currentNode->data << " ";
    inorder(currentNode->right);
}

// Helper function for postorder
void BST::postorder(Node* currentNode) {
    if (!currentNode) return;
    postorder(currentNode->left);
    postorder(currentNode->right);
    std::cout << currentNode->data << " ";
}

// Helper function for level by level
void BST::levelByLevel(Node* currentNode) {
    if (!currentNode) return;
    std::queue<Node*> q;
    q.push(currentNode);
    while (!q.empty()) {
        int n = q.size();
        for (size_t i = 0; i < n; ++i) {
            Node* temp = q.front();
            q.pop();
            std::cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    std::cout << std::endl;
}

// Constructor of BST
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
        throw std::runtime_error("ERROR: BST is empty");
    }

    Node* currentNode = searchNode(data, root, false);

    if (!currentNode->left && !currentNode->right) {                // Delete a leaf node           
        deleteLeaftNode(currentNode);
    } else if (currentNode->left && currentNode->right) {           // Delete a node with two children
        deleteNodeWithTwoChildren(currentNode);
    } else {                                                        // Delete a node with one children
        !currentNode->right ? deleteNodeWithLeftChild(currentNode) : deleteNodeWithRightChild(currentNode); 
    }
    currentHeight = calculateHeight(root);
    currentLength--;
}

// Search node to BST
bool BST::search(int data) {                                                    
    return searchNode(data, root, false);
}

// Peeking at top of BST
int BST::top() {                                                          
    if (empty()) throw std::runtime_error("ERROR: BST is empty");
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

// Visit a node by certain mode
void BST::visit(int key) {
    switch (key) {
        case 1:
            preorder(root);
            std::cout << std::endl;
            return;
        case 2:
            inorder(root);
            std::cout << std::endl;
            return;
        case 3:
            postorder(root);
            std::cout << std::endl;
            return;
        case 4:
            return levelByLevel(root);
        default:
            throw std::runtime_error("ERROR: Key is not valid");
    };
}

// Get height of BST
int BST::height() {
    return currentHeight;
}

// Get ancestors of a node
void BST::ancestors(int data) {
    Node* currentNode = searchNode(data, root, false);
    std::cout << currentNode->data;
    while (currentNode->prev) {
        std::cout << " <- " << currentNode->prev->data;
        currentNode = currentNode->prev;
    }
    std::cout << std::endl;
}

// Get the level of a node
int BST::whatlevelamI(int data) {
    Node* currentNode = searchNode(data, root, true);
    return currentNode->level;
}