// Author: Ishrat Arshad
// Project 2: Hash Table with AVL Tree Chaining
// Date: 06/27/2025
// File: HashTable.h
// Description: header file for the Hash Table implementation using AVL Tree chainin

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "AVLTree.h"
#include <string>
#include <vector>

class HashTable {
private:
    static const int TABLE_SIZE = 10; 
    AVLTree* table[TABLE_SIZE];
    int hash(const std::string& key);
public:
    HashTable();
    ~HashTable();
    void insert(const std::string& key, const std::string& value);
    std::string* search(const std::string& key);
    void remove(const std::string& key);
    void display();
};
#endif
