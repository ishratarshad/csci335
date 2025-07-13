//Author: Ishrat Arshad
// Project 2: Hash Table with AVL Tree Chaining
//Date: 06/27/2025
//File: AVLTree.h
// Description: Header file for the AVL Tree implementation

#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
class AVLTree {
private:
// this is the node structure for the AVL Tree
    struct Node {
        std::string key;
        std::string value;
        int height;
        Node* left;
        Node* right;
        Node(const std::string& k, const std::string& v)
            : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
    };
    Node* root;
    int height(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, const std::string& key, const std::string& value);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* node, const std::string& key);
    Node* search(Node* node, const std::string& key);
    void inorderDisplay(Node* node);
    void clear(Node* node); 
public:
    AVLTree();
    ~AVLTree();
    void insert(const std::string& key, const std::string& value);
    std::string* search(const std::string& key);
    void remove(const std::string& key);
    void display();
};
#endif
