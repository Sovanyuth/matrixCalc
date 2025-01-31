#include <iostream>
#include "matrix.h"
using namespace std;

Matrix createMatrix(int rows, int cols)
{
    // Checking for invalid matrices
    if (rows <= 0 || cols <= 0) 
    {
        // Throwing an invalid argument and give them a message
        throw invalid_argument("Rows and Columns must be of valid integers");
    }
    return Matrix(rows, vector<double>(cols, 0)); // Correct way to initialize
}

Matrix addMatrices(const Matrix& m1, const Matrix& m2)
{
    // Similar to the add function but this time switch the subtract sign
    int m1Rows = m1.size();
    int m1Cols = m1[0].size();
    int m2Rows = m2.size();
    int m2Cols = m2[0].size();

    if (m1Rows != m2Rows || m1Cols != m2Cols)
    {
        throw invalid_argument("Rows and Columns must be identical to add!");
    }
    else
    {
        Matrix results(m1Rows, vector<double>(m1Cols));

        // Else proceed to the the addition
        for (int i = 0; i < m1Rows; i++)
        {
            for (int j = 0; j < m1Cols; j++)
            {
                results[i][j] = m1[i][j] + m2[i][j];
            }
        }
        return results;
    }
}

Matrix subtractMatrices(const Matrix& m1, const Matrix& m2)
{
    // Similar to the add function but this time switch the subtract sign
    int m1Rows = m1.size();
    int m1Cols = m1[0].size();
    int m2Rows = m2.size();
    int m2Cols = m2[0].size();

    if (m1Rows != m2Rows || m1Cols != m2Cols)
    {
        throw invalid_argument("Rows and Columns must be identical to subtract!");
    }
    else 
    {
        Matrix results(m1Rows, vector<double>(m1Cols));

        // Else proceed to the the addition
        for (int i = 0; i < m1Rows; i++)
        {
            for (int j = 0; j < m1Cols; j++)
            {
                results[i][j] = m1[i][j] - m2[i][j];
            }
        }
        return results;
    }
}

Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2)
{
    // Checking validation: if the rows of matrix 1 != rows from matrix 2, this can't be multiplied
    // Columns of matrix 1 must equal rows of matrix 2 to compute the multiplication
    if (m1[0].size() != m2.size())
    {
        throw invalid_argument("Rows of m1 and Columns of m2 must be equal to multiply!");
    }
    else 
    {
        // Matrix results(m1.size(), vector<double>(m2[0].size()));
        // m1Cols == m2Rows
        int m1Rows = m1.size();
        int m1Cols = m1[0].size();
        int m2Cols = m2[0].size();

        Matrix results = createMatrix(m1Rows, m2Cols);
        int resultsRows = results.size();
        int resultsCols = results[0].size();
        
        // iterating through every single elements in each rows and columns of the results.
        for (int i = 0; i < resultsRows; i++)
        {
            for (int j = 0; j < resultsCols; j++)
            {
                // store each sum of the matrix in this variable
                double currentSum = 0;

                // iterate through every element in m1 and m2 to ensure correct multiplication results.
                for (int k = 0; k < m1Cols; k++)
                {
                    double multiply = m1[i][k] * m2[k][j];
                    currentSum += multiply;
                }
                // Add them to the elements of the matrix
                 results[i][j] += currentSum;
            }
        }
        // finally return the result
        return results;
    }
}