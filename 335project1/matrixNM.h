// Author: Ishrat Arshad
// CSCI 335: Project 1 Problem 3
// File name: matrixNM.h
// Description: this file declares the MatrixNM class which represents an n x m matrix using std::vector.
// Date: 06/05/2024

#ifndef MATRIXNM_H
#define MATRIXNM_H

#include <iostream>
#include <vector>

class MatrixNM {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    // this is the constructor that takes number of rows and columns
    MatrixNM(int n, int m);

    // this is the copy constructor
    MatrixNM(const MatrixNM& other);

    // this is the move constructor
    MatrixNM(MatrixNM&& other);

    // this is the copy assignment
    MatrixNM& operator=(const MatrixNM& other);

    // this is the move assignment
    MatrixNM& operator=(MatrixNM&& other);

    // this is for matrix addition
    MatrixNM operator+(const MatrixNM& other) const;

    // this is for matrix multiplication
    MatrixNM operator*(const MatrixNM& other) const;

    // this is for scalar multiplication
    MatrixNM operator*(double scalar) const;
    friend MatrixNM operator*(double scalar, const MatrixNM& mat);

    // this compute the determinant (only for square matrices)
    double determinant() const;


    // this gives element access
    double& operator()(int row, int col);           
    double operator()(int row, int col) const;      

    // these are for output and input
    friend std::ostream& operator<<(std::ostream& out, const MatrixNM& mat);
    friend std::istream& operator>>(std::istream& in, MatrixNM& mat);
};

#endif
