// Author: Ishrat Arshad
// Project 2: Hash Table with AVL Tree Chaining
// Date: 06/27/2025
// File: AVLTree.cpp    
// Description: implementation of the AVL Tree with basic operations

#include "AVLTree.h"
#include <iostream>
#include <algorithm>

// this is the constructor for the AVL Tree which initializes the root to nullptr
AVLTree::AVLTree() : root(nullptr) {}

// this is the destructor for the AVL Tree which clears the tree
AVLTree::~AVLTree() {
    clear(root);
} 

// this is a helper function to clear the tree recursively
void AVLTree::clear(Node* node) {
    if (node) {
        clear(node->left); 
        clear(node->right);
        delete node;
    }
}

// this function returns the height of a node
int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}

// this function calculates the balance factor of a node
int AVLTree::getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// this function performs a right rotation on the given node
AVLTree::Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;
// perform rotation
    x->right = y;
    y->left = temp;
// update heights
    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));
    return x;
}

// this function performs a left rotation on the given node
AVLTree::Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;
// perform rotation
    y->left = x;
    x->right = temp;
// update heights
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));
    return y;
}

// this function inserts a new key-value pair into the AVL Tree
AVLTree::Node* AVLTree::insert(Node* node, const std::string& key, const std::string& value) {
    if (!node)
        return new Node(key, value);
// if the tree is empty, create a new node
    if (key < node->key)
        node->left = insert(node->left, key, value);
// if the key is less than the current node's key we then insert in the left subtree
    else if (key > node->key)
        node->right = insert(node->right, key, value);
// if the key is greater than the current node's key we then insert in the right subtree
    else {
        node->value = value; // update value if key already exists
        return node;
    }
    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

// LL
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);
// RR
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);
// LR
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
// RL
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// this function inserts a new keyval pair into the AVL Tree
void AVLTree::insert(const std::string& key, const std::string& value) {
    root = insert(root, key, value);
}

// this function finds the node with the min value in the subtree rooted at the given node
AVLTree::Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

// deletes a node with the given key from the AVL Tree
AVLTree::Node* AVLTree::deleteNode(Node* node, const std::string& key) {
    if (!node)
        return node;
    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->key);
        }
    }
    if (!node)
        return node;
    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

// LL
    if (balance > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);
// LR
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
// RR
    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);
    // RL
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// this function removes a keyval pair from the AVL Tree
void AVLTree::remove(const std::string& key) {
    root = deleteNode(root, key);
}

// this function searches for a node with the given key in the AVL Tree
AVLTree::Node* AVLTree::search(Node* node, const std::string& key) {
    if (!node)
        return nullptr;
    if (key == node->key)
        return node;
    if (key < node->key)
        return search(node->left, key);
    return search(node->right, key);
}

// this function searches for a key in the AVL Tree and returns a pointer to its value
std::string* AVLTree::search(const std::string& key) {
    Node* result = search(root, key);
    if (result)
        return &result->value;
    return nullptr;
}
// this function performs an inorder traversal of the AVL Tree and displays the keyval pairs
void AVLTree::inorderDisplay(Node* node) {
    if (node) {
        inorderDisplay(node->left);
        std::cout << "    [" << node->key << " : " << node->value << "]\n";
        inorderDisplay(node->right);
    }
}

// this function displays the AVL Tree in an inorder 
void AVLTree::display() {
    if (!root)
        std::cout << "    (empty)\n";
    else
        inorderDisplay(root);
}
