#pragma once

class Node {
    public:
        int data;
        int level;
        Node *left;
        Node *right;
        Node *prev;
        Node(int data);
};

class BST {
    private:
        int currentLength;
        int currentHeight;
        void compareNodes(Node* currentNode, Node* newNode);
        Node* searchNode(int data, Node* currentNode, bool isLevel);
        void deleteLeaftNode(Node* currentNode);
        void deleteNodeWithLeftChild(Node* currentNode);
        void deleteNodeWithRightChild(Node* currentNode);
        void deleteNodeWithTwoChildren(Node* currentNode);
        Node* minRight(Node* currentNode);
        void updateDecrementedHeight(Node* currentNode);
    public:
        BST();
        Node* root;
        void insertNode(int data);
        void deleteNode(int data);
        int top(); 
        bool empty();
        int size();
        void visit(int key);
        int height();
        void ancestors(int data);
        int whatlevelamI(int data);
};