// Author: Ishrat Arshad
// CSCI 355: Data Structures and Algorithms (Morning Section)
// Project 3: Priority Queue Simulation
// Date: 07/09/2025
// File: MaxHeap.h
// Description: header file for MaxHeap class template

#pragma once
#include <stdexcept>

template <typename Comparable>
class MaxHeap {
public:

// default constructor initializes an empty heap with a maximum size
// this is O(1) time complexity because it only initializes variables
    MaxHeap() : current_size_(0), max_size_(100) {}

// insert an item into the heap
// this is O(log n) time complexity because it may require percolating up the item
    void insert(const Comparable& item) {
        if (current_size_ >= max_size_)
            throw std::overflow_error("Heap is full");

        int hole = ++current_size_;
        while (hole > 1 && item > array_[hole / 2]) {
            array_[hole] = array_[hole / 2];
            hole /= 2;
        }
        array_[hole] = item;
    }

// delet the maximum item from the heap n returns it
// this is O(log n) time complexity because it may require percolating down the item
    Comparable deleteMax() {
        if (current_size_ == 0)
            throw std::underflow_error("Heap is empty");

        Comparable maxItem = array_[1];
        array_[1] = array_[current_size_--]; 
        percolateDown(1);
        return maxItem;
    }

// gets size
// this is O(1) time complexity because it only returns the current size
    int getSize() const {
        return current_size_;
    }

private:
    Comparable array_[101]; 
    int current_size_;
    int max_size_;

// percolates down the item at the specfic hole to maintain the max-heap property
// this is O(log n) time complexity because it may traverse down the height of the heap
    void percolateDown(int hole) {
        Comparable tmp = array_[hole];
        int child;
        while (hole * 2 <= current_size_) {
            child = hole * 2;
            if (child != current_size_ && array_[child + 1] > array_[child])
                child++;
            if (array_[child] > tmp)
                array_[hole] = array_[child];
            else
                break;
            hole = child;
        }
        array_[hole] = tmp;
    }
};
