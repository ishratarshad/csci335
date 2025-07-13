// Author: Ishrat Arshad
// Project 2: Hash Table with AVL Tree Chaining
// Date: 06/27/2025
// File: HashTable.cpp
// Description: implementation of the Hash Table using AVL Tree chaining

// HashTable.cpp
#include "HashTable.h"
#include <iostream>

// this is the constructor for the HashTable which initializes the table with AVL Trees
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = new AVLTree();
    }
}

// the destructor for the HashTable which deletes all AVL Trees in the table
HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        delete table[i];
    }
}

// this function computes the hash value for a given key
int HashTable::hash(const std::string& key) {
    std::hash<std::string> hasher;
    return hasher(key) % TABLE_SIZE;
}

//this function inserts a key val pair into the hash table
void HashTable::insert(const std::string& key, const std::string& value) {
    int index = hash(key);
    table[index]->insert(key, value);
}

// this function searches for a key in the hash table and returns a pointer to its value
std::string* HashTable::search(const std::string& key) {
    int index = hash(key);
    return table[index]->search(key);
}

// this function removes a key val pair from the hash table
void HashTable::remove(const std::string& key) {
    int index = hash(key);
    table[index]->remove(key);
}

// this function displays the contents of the hash table
void HashTable::display() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        std::cout << "Bucket " << i << ":\n";
        table[i]->display();
        std::cout << std::endl;
    }
}
