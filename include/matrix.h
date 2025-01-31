#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

using namespace std;

using Matrix = vector<vector<double>>;

Matrix createMatrix(int rows, int cols);

Matrix addMatrices(const Matrix& m1, const Matrix& m2);
Matrix subtractMatrices(const Matrix& m1, const Matrix& m2);
Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2);

#endif // MATRIX_H