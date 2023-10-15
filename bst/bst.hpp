#pragma once

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node *prev;
        Node(int data);
};

class BST {
    private:
        int currentLength;
        Node* root;
        void compareNodes(Node* currentNode, Node* newNode);
    public:
        BST();
        void insertNode(int data);
        int searchNode(int data);
        void deleteNode(int data);
        int top(); 
        bool empty();
        bool full();
        int size();
};