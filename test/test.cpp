#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "matrix.h"

TEST_CASE("Creating a Matrix", "[createMatrix][valid]")
{
    // Creating a 3x3 Matrix
    Matrix matrix1 = createMatrix(3.0, 3.0);

    // Should give 9 Assertions Pass After this test passes
    for (int i = 0; i < matrix1.size(); i++) 
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            REQUIRE(matrix1[i][j] == 0.0);
        }
    }

    // Should give 20 assertions Pass After this Test
    Matrix matrix2 = createMatrix(4, 5);
    for (int i = 0; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[0].size(); j++)
        {
            REQUIRE(matrix2[i][j] == 0.0);
        }
    }
}

TEST_CASE("Creating an invalid Matrix", "[createMatrix][invalid]")
{
    int rows = -1;
    int cols = 2;

    REQUIRE_THROWS_AS(createMatrix(rows, cols), invalid_argument);
}

TEST_CASE("Adding Matrices", "[addMatrices][valid]")
{
    Matrix matrix1 { { 1, 1, 1 },
                    { 1, 1, 1 }, 
                    { 1, 1, 1 } };

    Matrix matrix2 { { 2, 2, 2 },
                  { 2, 2, 2 },
                  { 2, 2, 2 } };

    Matrix result = addMatrices(matrix1, matrix2);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            REQUIRE(result[i][j] == 3);
        }
    }

    Matrix matrix3{ { 0, 2, 3 },
                 { 6, 1, 4 },
                 { 11, 22, 2 } };

    Matrix matrix4{ { 1, 0, 1 },
                  { 8, 3, 5 },
                  { -1, 2, 32 } };

    Matrix results2 = addMatrices(matrix3, matrix4);

    REQUIRE(results2[0][0] == 1);
    REQUIRE(results2[0][1] == 2);
    REQUIRE(results2[2][2] == 34);
}


TEST_CASE("Adding Matrices Invalid", "[addMatrices][invalid]")
{
    Matrix matrix1{ { 1, 1, 1 },
                    { 1, 1, 1 },
                    { 1, 1, 1 } };

    Matrix matrix2{ { 2, 2, 2 },
                  { 2, 2, 2 } };

    REQUIRE_THROWS_AS(addMatrices(matrix1, matrix2), invalid_argument);
}

TEST_CASE("Subtracting Matrices", "[subtractMatrices][valid]")
{
    Matrix matrix1{ { 1, 1, 1 },
                    { 1, 1, 1 },
                    { 1, 1, 1 } };

    Matrix matrix2{ { 2, 2, 2 },
                  { 2, 2, 2 },
                  { 2, 2, 2 } };

    Matrix result = subtractMatrices(matrix1, matrix2);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            REQUIRE(result[i][j] == -1);
        }
    }

    Matrix matrix3{ { 0, 2, 3 },
                 { 6, 1, 4 },
                 { 11, 22, 2 } };

    Matrix matrix4{ { 1, 0, 1 },
                  { 8, 3, 5 },
                  { -1, 2, 32 } };

    Matrix results2 = subtractMatrices(matrix3, matrix4);

    REQUIRE(results2[0][0] == -1);
    REQUIRE(results2[0][1] == 2);
    REQUIRE(results2[0][2] == 2);
    REQUIRE(results2[1][0] == -2);
    REQUIRE(results2[1][1] == -2);
    REQUIRE(results2[1][2] == -1);
    REQUIRE(results2[2][0] == 12);
    REQUIRE(results2[2][1] == 20);
    REQUIRE(results2[2][2] == -30);
}

TEST_CASE("Multiplying Matrix", "[multiplyMatrices][valid]")
{
    SECTION("First Test Case (Most Simple One)")
    {
        // Matrix 2x3
        Matrix matrix1{ { 1, 1 },
                        { 1, 1 } };

        // Matrix 3x2
        Matrix matrix2{ { 2, 2 },
                      { 2, 2 } };
        // Result should be a Matrix of 2x2

        // Checking all the results inside the matrix. They should all be equal to 4.
        Matrix result = multiplyMatrices(matrix1, matrix2);
        for (int i = 0; i < result.size(); i++) 
        {
            for (int j = 0; j < result[0].size(); j++) 
            {
                REQUIRE(result[i][j] == 4);
            }
        }
    }

   SECTION("A More Advanced Test Case")
   {
       // Matrix 2x3
       Matrix matrix3{ { 1, 2, 3 },
                       { 4, 5, 6 } };
       // Matrix 3x2
       Matrix matrix4{ { 10, 11 },
                       { 20, 21 },
                       { 30, 31 } };

       // Resulting Matrix should be 2x2
       Matrix results = multiplyMatrices(matrix3, matrix4);

       int resultingRows = results.size();
       int resultingCols = results[0].size();

       REQUIRE(resultingRows == 2);
       REQUIRE(resultingCols == 2);
       REQUIRE(results[0][0] == 140);
       REQUIRE(results[0][1] == 146);
       REQUIRE(results[1][0] == 320);
       REQUIRE(results[1][1] == 335);
   }
}

TEST_CASE("Multiplying Matrix Invalid", "[multiplyMatrices][invalid]")
{
    // Matrix 2x3
    Matrix matrix3{ { 1, 2, 3 },
                    { 4, 5, 6 } };
    // Matrix 3x2
    Matrix matrix4{ { 10, 11 },
                    { 20, 21 },};

    // Resulting Matrix should be 2x2
    REQUIRE_THROWS_AS(multiplyMatrices(matrix3, matrix4), invalid_argument);
}