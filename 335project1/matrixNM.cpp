// Author: Ishrat Arshad
// CSCI 335: Project 1 - Problem 3
// File name: matrixNM.cpp
// Description: this file implements the MatrixNM class which represents an n x m matrix using std::vector.
// Date: 06/05/2024

#include "matrixNM.h"
#include <iostream>

// this is the constructor that takes number of rows and columns
// time complexity: O(n * m) because itializes a 2D vector with n rows and m columns where ach of the n rows is filled with m default values (0.0). This results in n * m operations 
MatrixNM::MatrixNM(int n, int m) : rows(n), cols(m), data(n, std::vector<double>(m)) {}

// this is the copy constructor
// time complexity: O(n * m) because it copies the entire other.data, which has n rows and m columns and copying each element leads to n * m operations.
MatrixNM::MatrixNM(const MatrixNM& other) : rows(other.rows), cols(other.cols), data(other.data) {}

// this is the move constructor (no noexcept)
// time complexity: O(1) because it just moves pointers where there is no element copying. It instead assigns data = std::move(other.data) and updates other.rows and other.cols. This is all constant-time operation.
MatrixNM::MatrixNM(MatrixNM&& other) : rows(other.rows), cols(other.cols), data(std::move(other.data)) {
    other.rows = 0;
    other.cols = 0;
}

// this is the copy assignment
// time complexity: O(n * m) because it replaces the current data with a deep copy of another matrix’s data, which involves copying n * m elements.
MatrixNM& MatrixNM::operator=(const MatrixNM& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

// this is the move assignment
// time complexity: O(1) because it transfers ownership of the data from one MatrixNM object to another without copying the data. It simply moves the vector and resets the other matrix's dimensions to zero.
MatrixNM& MatrixNM::operator=(MatrixNM&& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = std::move(other.data);
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

// this is for matrix addition
// time complexity: O(n * m) because it adds each corresponding element from two matrices. Each element requires one operation, in total n * m.
MatrixNM MatrixNM::operator+(const MatrixNM& other) const {
    MatrixNM result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

// this is for matrix multiplication
// time complexity: O(n * m * k) because for each of the n * p elements in the result matrix where p = other.cols, you compute a dot product that takes k steps
MatrixNM MatrixNM::operator*(const MatrixNM& other) const {
    MatrixNM result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

// this is for scalar multiplication
// time complexity: O(n * m) because each of the n * m elements is multiplied by a scalar — one operation per element.
MatrixNM MatrixNM::operator*(double scalar) const {
    MatrixNM result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] * scalar;
    return result;
}

// scalar multiplication from the left
// time complexity: O(n * m) because each of the n * m elements is multiplied by a scalar — one operation per element.
MatrixNM operator*(double scalar, const MatrixNM& m) {
    return m * scalar;
}

// this compute the determinant (only for square matrices)
// time complexity: O(n!) because the determinant calculation involves recursive calls for submatrices, leading to a factorial growth in the number of operations as the size of the matrix increases. The base cases for 1x1 and 2x2 matrices are O(1), but for larger matrices, the recursive nature leads to O(n!) complexity.
double MatrixNM::determinant() const {
    // check if the matrix is square
    if (rows != cols)
        throw std::invalid_argument("determinant only defined for square matrices.");
    // base cases for 1x1 and 2x2 matrices
    if (rows == 1) // 1x1 matrix
        return data[0][0];
    
    if (rows == 2) // 2x2 matrix
        return data[0][0]*data[1][1] - data[0][1]*data[1][0];
    // for larger matrices, use Laplace expansion
    double det = 0.0;
    // iterate over the first row
    for (int col = 0; col < cols; ++col) {
        // create a submatrix by excluding the first row and the current column
        MatrixNM s(rows - 1, cols - 1);
        // fill the submatrix
        for (int i = 1; i < rows; ++i) {
            int s_col = 0;
            for (int j = 0; j < cols; ++j) {
                if (j == col) 
                    continue;
                s(i - 1, s_col) = data[i][j];
                s_col++;
            }
        }

        double cofact = (col % 2 == 0 ? 1 : -1) * data[0][col] * s.determinant();
        det += cofact;
    }
    return det;
}


// this gives element access (non-const)
// time complexity: O(1) because it simply returns a reference to the element at the specified row and column without any additional computation.
double& MatrixNM::operator()(int row, int col) {
    return data[row][col];
}

// this gives element access (const)
// time complexity: O(1) because it simply returns a reference to the element at the specified row and column without any additional computation.
double MatrixNM::operator()(int row, int col) const {
    return data[row][col];
}

// this is the output operator
// time complexity: O(n * m) because it iterates through each element of the matrix, printing them in a formatted way. Each element is printed once, leading to n * m operations where n is the number of rows and m is the number of columns.
std::ostream& operator<<(std::ostream& out, const MatrixNM& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            out << m.data[i][j];
            if (j < m.cols - 1) out << " ";
        }
        out << std::endl;
    }
    return out;
}

// this is the input operator
// time complexity: O(n * m) because it reads n * m values from the input stream to fill the matrix, where n is the number of rows and m is the number of columns.
std::istream& operator>>(std::istream& in, MatrixNM& m) {
    std::cout << "Enter " << m.rows * m.cols << " values for a " << m.rows << "x" << m.cols << " matrix:" << std::endl;
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            in >> m.data[i][j];
    return in;
}
