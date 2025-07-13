// Author: Ishrat Arshad
// Project 2: Hash Table with AVL Tree Chaining
// Date: 06/27/2025
// File: main.cpp
// Description: main file to test the Hash Table with AVL Tree chaining

#include <iostream>
#include <fstream>
#include <sstream>
#include "HashTable.h"

// helper function to trim leading and trailing spaces
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

// this function loads books from a file into the hash table
void loadBooks(HashTable& catalog, const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Failed to open " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string title, author, genre;
// assumes the file format is "Title,Author,Genre"
        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, genre, ',');

// trim spaces from each field
        title = trim(title);
        author = trim(author);
        genre = trim(genre);

        std::string value = author + " - " + genre;
        catalog.insert(title, value);
    }

    std::cout << "books loaded successfully!\n";
}

int main() {
    HashTable catalog;
    int choice;

    std::string input;
// display the menu and handle user input
    do {
        std::cout << "\n--- library book catalog menu: ---\n";
        std::cout << "1. first, load books from file\n";
        std::cout << "2. secound, search for a book by title\n";
        std::cout << "3. thrird, display hash table\n";
        std::cout << "4. exit\n";
        std::cout << "enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                loadBooks(catalog, "books.txt");
                break;
            case 2:
// search for a book by title
                std::cout << "enter book title to search: ";
                std::getline(std::cin, input);
                input = trim(input); 
                {
                    std::string* result = catalog.search(input);
                    if (result)
                        std::cout << "found: " << *result << "\n";
                    else
                        std::cout << "book not found.\n";
                }
                break;
            case 3:
                catalog.display();
                break;
            case 4:
                std::cout << "now exiting...\n";
                break;
            default:
                std::cout << "invalid choice: try again.\n";
        }

    } while (choice != 4);

    return 0;
}
