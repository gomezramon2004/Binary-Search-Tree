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
        Node* front;
        Node* rear;
    public:
        BST();
        void push(int data);
        void pop();
        int top(); 
        bool empty();
        bool full();
        int size();
};