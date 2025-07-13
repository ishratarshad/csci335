// matrix33.h
#ifndef MATRIX33_H
#define MATRIX33_H

#include <iostream>

class Matrix33 {
private:
    double** data;  

public:
    // this is the default constructor
    Matrix33();

    // this is the constructor that takes a 2D array
    Matrix33(double input[3][3]);

    // this is the copy constructor
    Matrix33(const Matrix33& other);

    // this is the move constructor (no noexcept)
    Matrix33(Matrix33&& other);

    // this is the copy assignment
    Matrix33& operator=(const Matrix33& other);

    // this is the move assignment
    Matrix33& operator=(Matrix33&& other);

    // this is the destructor
    ~Matrix33();  // i just added this 

    // this is the is for matrix addition
    Matrix33 operator+(const Matrix33& other) const;

    // Matrix multiplication
    Matrix33 operator*(const Matrix33& other) const;

    // this is the is for scalar multiplication
    Matrix33 operator*(double scalar) const;
    friend Matrix33 operator*(double scalar, const Matrix33& mat);

    // this gives element access
    double& operator()(int row, int col);           
    double operator()(int row, int col) const;     

    // these are for output and input
    friend std::ostream& operator<<(std::ostream& out, const Matrix33& mat);
    friend std::istream& operator>>(std::istream& in, Matrix33& mat);

    // this is to get the determinant
    double determinant() const;
};

#endif
