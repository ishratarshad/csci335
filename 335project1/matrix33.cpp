// Author: Ishrat Arshad
// CSCI 335: Project 1
// File name: matrix33.cpp
// Description: this file implements the Matrix33 class which represents a 3x3 matrix.
// Date: 06/05/2024

#include <iostream>
#include "matrix33.h"

using namespace std;

// problem 1 number 2: default constructor
// time complexity: O(1) because it initializes a 3x3 matrix with all elements set to 0
Matrix33::Matrix33() {
    data = new double*[3];
    for (int i = 0; i < 3; ++i)
        data[i] = new double[3]{0}; // Initialize to zero
}

// problem 1 number 4: constructor that accepts a 2D array
// time complexity: O(1) because it initializes a 3x3 matrix with the provided values
Matrix33::Matrix33(double input[3][3]) {
    data = new double*[3];
    for (int i = 0; i < 3; ++i) {
        data[i] = new double[3];
        for (int j = 0; j < 3; ++j) {
            data[i][j] = input[i][j];
        }
    }
}

// problem 1 number 5: copy constructor
// time complexity: O(1) because it initializes a new 3x3 matrix with the values from another matrix33 object
Matrix33::Matrix33(const Matrix33& other) {
    data = new double*[3];
    for (int i = 0; i < 3; ++i) {
        data[i] = new double[3];
        for (int j = 0; j < 3; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}


// problem 1 number 6: move constructor
// time complexity: O(1) because it transfers ownership of the data pointer from one Matrix33 object to another without copying the data
Matrix33::Matrix33(Matrix33&& other) {
    data = other.data;
    other.data = nullptr;
}

// problem 1 number 7: copy assignment
// time complexity: O(1) because it copies the data from one Matrix33 object to another to make sure that the old data is deleted before copying the new data
Matrix33& Matrix33::operator=(const Matrix33& other) {
// if it doesnt already equal to the new object, we need to copy the data and delete the old data
    if (this != &other) { 
        if (data != nullptr) {
            for (int i = 0; i < 3; ++i) {
                delete[] data[i]; // deletes old data
            }
            delete[] data;
        }
// copies new data
        data = new double*[3]; 
        for (int i = 0; i < 3; ++i) {
            data[i] = new double[3];
            for (int j = 0; j < 3; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

// destructor
// time complexity: O(1) because it deletes the dynamically allocated memory for a 3x3 matrix
Matrix33::~Matrix33() {
    if (data != nullptr) {
        for (int i = 0; i < 3; ++i) {
            delete[] data[i]; 
        }
        delete[] data; 
    }
}

// problem 1 number 8: move assignment
// time complexity: O(1) because it transfers ownership of the data pointer from one Matrix33 object to another without copying the data
Matrix33& Matrix33::operator=(Matrix33&& other) {
// if it doesnt already equal to the new object, we need to copy the data and delete the old data
    if (this != &other) {
        if (data != nullptr) {
            for (int i = 0; i < 3; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

// problem 1 number 9: operator for matrix multiplication
// time complexity: O(1) because it multiplies two 3x3 matrices which is a constant number of operations regardless of input size
Matrix33 Matrix33::operator*(const Matrix33& other) const {
    double result[3][3] = {};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                result[i][j] += data[i][k] * other.data[k][j];
    return Matrix33(result);
}

// problem 1 number 10: operator for scalar multiplication
// time complexity: O(1) because it multiplies each element of a 3x3 matrix by a scalar which is a constant number of operations
Matrix33 Matrix33::operator*(double scalar) const {
    double result[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result[i][j] = data[i][j] * scalar;
    return Matrix33(result);
}

// problem 1 number 11: operator for matrix addition
// time complexity: O(1) because it adds two 3x3 matrices which is a constant number of operations regardless of input size
Matrix33 Matrix33::operator+(const Matrix33& other) const {
    double result[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result[i][j] = data[i][j] + other.data[i][j];
    return Matrix33(result);
}

// problem 1 number 12: operator for printing 
// time complexity: O(1) because it prints a 3x3 matrix which is a constant number of operations regardless of input size
std::ostream& operator<<(std::ostream& output, const Matrix33& matrix) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            output << matrix.data[i][j];
            if (j < 2) output << " "; 
        }
        output << std::endl;  
    }
    return output;
}


// problem 1 number 13: input operator
// time complexity: O(1) because it reads 9 values for a 3x3 matrix which is a constant number of operations regardless of input size
std::istream& operator>>(std::istream& in, Matrix33& matrix) {
    if (matrix.data == nullptr) {
        matrix.data = new double*[3];
        for (int i = 0; i < 3; ++i)
            matrix.data[i] = new double[3];
    }

    std::cout << "Enter 9 values for the 3x3 matrix (row by row): ";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            in >> matrix.data[i][j];
    return in;
}


// problem 1 number 14: determinant function
// time complexity: O(1) because it calculates the determinant of a 3x3 matrix which is a constant number of operations regardless of input size
double Matrix33::determinant() const {
    double a = data[0][0];
    double b = data[0][1];
    double c = data[0][2];
    double d = data[1][0]; 
    double e = data[1][1];
    double f = data[1][2];
    double g = data[2][0];
    double h = data[2][1];
    double i = data[2][2];

    return a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
}

// Overload the operator for accessing the private attributes of the Vector3 and Matrix33 classes.
// time complexity: O(1) because it accesses a specific element in a 3x3 matrix which is a constant number of operations regardless of input size
double Matrix33::operator()(int row, int col) const {
    return data[row][col];
}

// Overload the operator for accessing the private attributes of the Vector3 and Matrix33 classes.
// time complexity: O(1) because it accesses a specific element in a 3x3 matrix which is a constant number of operations regardless of input size
double& Matrix33::operator()(int row, int col) {
    return data[row][col];
}