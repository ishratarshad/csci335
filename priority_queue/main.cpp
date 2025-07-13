// Author: Ishrat Arshad
// CSCI 355: Data Structures and Algorithms (Morning Section)
// Project 3: Priority Queue Simulation
// Date: 07/09/2025
// File: main.cpp
// Description: Main simulation of a problem-solving store using MaxHeap and Customer records
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Customer.h"
#include "MaxHeap.h"

int main() {

    srand(time(0)); // helps generates random numbers
    MaxHeap<Customer> heap;
    std::vector<Customer> history;
// insert 5 customers with random priority levels
    for (int i = 1; i <= 5; i++) {
        Customer c("customer" + std::to_string(i));
        heap.insert(c);
        std::cout << "inserted: " << c.name << ", priority: " << c.priorityLevel << "\n";
    }
//serve customers based on priority
    while (heap.getSize() > 0) { 
        Customer c = heap.deleteMax();
        c.SetServiceTime();
        std::cout << "serving: " << c.name << ", service time: " << c.serviceTime << "\n";
        history.push_back(c);
    }
// sort service history by service time
    std::sort(history.begin(), history.end(), [](const Customer& a, const Customer& b) {
        return a.serviceTime < b.serviceTime;
    });

// print sorted service history
    std::cout << "sorted service history:\n";
    for (const Customer& c : history) {
        std::cout << c.name << " | priority: " << c.priorityLevel
                  << " | service time: " << c.serviceTime << "\n";
    }
    return 0;
}
