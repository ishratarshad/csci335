// Author: Ishrat Arshad
// CSCI 335: Project 1 - Problem 2
// File name: main.cpp
// Description: Computes Ax = b where A is a 3x3 matrix and x is a 3D vector
// Date: 06/05/2024

#include <iostream>
#include "matrix33.h"
#include "vector3.h"

using namespace std;

Vector3 multiply(Matrix33& A, Vector3& x) {
    double b0 = A(0,0)*x(0) + A(0,1)*x(1) + A(0,2)*x(2);
    double b1 = A(1,0)*x(0) + A(1,1)*x(1) + A(1,2)*x(2);
    double b2 = A(2,0)*x(0) + A(2,1)*x(1) + A(2,2)*x(2);

    return Vector3(b0, b1, b2);
}


int main() {
    Matrix33 A;
    Vector3 x;
    cin >> A;
    cin >> x;
    Vector3 b = multiply(A, x);
    cout << "Result of Ax is: " << b << endl;
    return 0;
}

// this tests all three problems (1, 2 and 3) in the project.
// #include <iostream>
// #include "matrix33.h"
// #include "vector3.h"
// #include "matrixNM.h"

// using namespace std;

// void testProblem1() {
//     cout << "=== Problem 1: Matrix33 and Vector3 ===" << endl;

//     Matrix33 m1;
//     cout << "Enter 3x3 matrix (Matrix33):" << endl;
//     cin >> m1;

//     Matrix33 m2;
//     cout << "Enter another 3x3 matrix (Matrix33):" << endl;
//     cin >> m2;

//     Matrix33 mSum = m1 + m2;
//     Matrix33 mProduct = m1 * m2;
//     Matrix33 mScalar = m1 * 2.0;

//     cout << "Matrix Sum:\n" << mSum;
//     cout << "Matrix Product:\n" << mProduct;
//     cout << "Matrix Scalar Multiplication (×2):\n" << mScalar;
//     cout << "Determinant of m1: " << m1.determinant() << endl;

//     Vector3 v1;
//     cout << "Enter 3D vector (Vector3):" << endl;
//     cin >> v1;
//     cout << "v1 magnitude: " << v1.magnitude() << endl;
//     cout << "v1 * 3: " << (v1 * 3.0) << endl;
// }

// void testProblem2() {
//     cout << "\n=== Problem 2: Ax = b ===" << endl;

//     Matrix33 A;
//     Vector3 x;
//     cout << "Enter 3x3 matrix A:" << endl;
//     cin >> A;
//     cout << "Enter 3D vector x:" << endl;
//     cin >> x;

//     Vector3 b(
//         A(0,0)*x(0) + A(0,1)*x(1) + A(0,2)*x(2),
//         A(1,0)*x(0) + A(1,1)*x(1) + A(1,2)*x(2),
//         A(2,0)*x(0) + A(2,1)*x(1) + A(2,2)*x(2)
//     );

//     cout << "Result b = Ax: " << b << endl;
// }

// void testProblem3() {
//     cout << "\n=== Problem 3: MatrixNM (Generic Matrix) ===" << endl;

//     MatrixNM mat1(2, 3);
//     MatrixNM mat2(2, 3);
//     cout << "Enter first 2x3 matrix:" << endl;
//     cin >> mat1;
//     cout << "Enter second 2x3 matrix:" << endl;
//     cin >> mat2;

//     MatrixNM sum = mat1 + mat2;
//     MatrixNM scalarProduct = mat1 * 2.0;

//     cout << "Matrix Sum (2x3 + 2x3):\n" << sum;
//     cout << "Scalar Multiplication:\n" << scalarProduct;

//     MatrixNM mat3(3, 2);
//     cout << "Enter 3x2 matrix to multiply with 2x3 matrix:" << endl;
//     cin >> mat3;

//     MatrixNM product = mat1 * mat3;
//     cout << "Matrix Product (2x3 × 3x2):\n" << product;

//     // determinant test
//     MatrixNM square(2, 2);
//     cout << "Enter square matrix (2x2) for determinant:" << endl;
//     cin >> square;
//     try {
//         cout << "Determinant: " << square.determinant() << endl;
//     } catch (const invalid_argument& e) {
//         cerr << "Error: " << e.what() << endl;
//     }

//     // try determinant on non-square
//     try {
//         cout << "Trying determinant on non-square matrix (2x3):" << endl;
//         cout << mat1.determinant() << endl;
//     } catch (const invalid_argument& e) {
//         cerr << "Expected error: " << e.what() << endl;
//     }
// }

// int main() {
//     testProblem1();
//     testProblem2();
//     testProblem3();
//     return 0;
// }
