// Author: Ishrat Arshad
// CSCI 355: Data Structures and Algorithms (Morning Section)
// Project 3: Priority Queue Simulation
// Date: 07/09/2025
// File: Customer.h
// Description: header file for Customer class

#pragma once
#include <string>
#include <cstdlib>

class Customer {
public:
    std::string name;
    int serviceTime;
    int priorityLevel;
// default constructor initializes an empty customer
// this is O(1) time complexity because it only initializes variables
    Customer() : name(""), serviceTime(0), priorityLevel(0) {}

// constructor that initializes a customer with a name and sets priority level
// this is O(1) time complexity because it only initializes variables
    Customer(const std::string& name_in) : name(name_in), serviceTime(0) {
        SetPriorityLevel();
    }
// sets a random priority level between 0 and 100 
// this is O(1) time complexity because it only assigns a random value
    void SetPriorityLevel() {
        priorityLevel = rand() % 101;
    }

// sets a random service time between 0 and 60 seconds
// this is O(1) time complexity because it only assigns a random value
    void SetServiceTime() {
        serviceTime = rand() % 61;
    }
// overloads the > operator to compare customers based on priority level
// this is O(1) time complexity because it only compares two integers
    bool operator>(const Customer& other) const {
        return priorityLevel > other.priorityLevel;
    }
};
