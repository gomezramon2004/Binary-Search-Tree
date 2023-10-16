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
        Node* root;
        void compareNodes(Node* currentNode, Node* newNode);
        Node* searchNode(int data, Node* currentNode, bool isLevel);
        void deleteLeaftNode(Node* currentNode);
        void deleteNodeWithLeftChild(Node* currentNode);
        void deleteNodeWithRightChild(Node* currentNode);
        void deleteNodeWithTwoChildren(Node* currentNode);
        Node* minRight(Node* currentNode);
        int calculateHeight(Node* currentNode);
        void preorder(Node* currentNode);
        void inorder(Node* currentNode);
        void postorder(Node* currentNode);
        void levelByLevel(Node* currentNode);
    public:
        BST();
        void insertNode(int data);
        void deleteNode(int data);
        bool search(int data);
        int top(); 
        bool empty();
        int size();
        void visit(int key);
        int height();
        void ancestors(int data);
        int whatlevelamI(int data);
};