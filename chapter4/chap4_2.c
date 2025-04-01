#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include "../utils/arrutil.h"

/*  
    4.2 Strassen’s algorithm for matrix multiplication
*/

int** basicMatrixCross(int x, int y, int z, int A[x][y], int B[y][z])
    /* 
        FUNCTION: basicMatrixCross
        Basic (vector) multiplication of matrix

        Return: int** 2D array matrix result of multiplication

        Parameters:
        int x : number of rows in first matrix (A)
        int y : number of column(s) of first matrix (A), rows in second matrix (B)
        int z : number of column(s) of second matrix (B) 
        int A[][] : first matrix with x rows and y columns
        int B[][] : second matrix with y rows and z columns
    */
{
    // initialize result matrix
    int** C = initMatrix(x, z);

    // begin multiplication steps
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < z; j++)
        {
            for (int k = 0; k < y; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int** squareMatrixCross(int n, int A[n][n], int B[n][n])
    /* 
        FUNCTION: squareMatrixCross
        matrix multiplicaton but for square matrix

        Return: int** 2D array represents square matrix multiplication results

        Parameters: 
        int n : number of rows or columns for all matrices involved in calculation
        int A[][]
        int B[][]
    */
{
    // pass to basicMatrixCross
    int** squareC = basicMatrixCross(n, n, n, A, B);
    
    return squareC;
}

int** sumStrassenMatrix(int size_Add, int row0A, int col0A, int** matrix_A, int row0B, int col0B, int** matrix_B)
{
    /*  
        Add two (pointer based) matrices for Strassen's recursive steps
         A[row0A to row0A + size_Add][col0A to col0A + size Add] + B[row0B to row0B + size_Add][col0B to col0B +_ size_Add]
        Also correspond to different basis sizes 
        WARNING: this is for strassen's algorithm use only
        The function assumes that the size to add is ALWAYS a square matrix
        It is the caller function responsibility to ensure that the size_Add is appropriate

        RETURN: int** matrix with size = size_Add x size_Add

        PARAMTERS:
        int size_Add = the size of row or col of the addition area
        int row0A = the starting point of row for matrix A to be used in addition operation
        int col0A = the starting point of column for matrix A to be used in addtion operation
        int** matrix_A = the matrix A 
        int row0B = the starting point of row for matrix B to be used in addition operation
        int col0B = the starting point of column for matrix B to be used in addtion operation
        int** matrix_B = the matrix B
    */
    // initiate the result matrix
    int** summedMatrix = initMatrix(size_Add, size_Add);
    //start addition operations
    for (int i = 0; i < size_Add; i++)
        for (int j = 0; j < size_Add; j++)
            summedMatrix[i][j] = matrix_A[row0A + i][col0A + j] + matrix_B[row0B + i][row0B + j];
    
    return summedMatrix;
}

int** subStrasssenMatrix(int size_Sub, int row0A, int col0A, int** matrix_A, int row0B, int col0B, int** matrix_B)
{
    /*  
        Subtract matrices A - B for Strassen's recursive steps
         A[row0A to row0A + size_Add][col0A to col0A + size Add] - B[row0B to row0B + size_Add][col0B to col0B +_ size_Add]

        Also correspond to different basis sizes 
        WARNING: this is for strassen's algorithm use only
        The function assumes that the size to add is ALWAYS a square matrix
        It is the caller function responsibility to ensure that the size_Add is appropriate

        RETURN: int** matrix with size = size_Add x size_Add

        PARAMTERS:
        int size_Add = the size of row or col of the subtraction area
        int row0A = the starting point of row for matrix A to be used in subtraction operation
        int col0A = the starting point of column for matrix A to be used in subtraction operation
        int** matrix_A = the matrix A 
        int row0B = the starting point of row for matrix B to be used in subtraction operation
        int col0B = the starting point of column for matrix B to be used in subtraction operation
        int** matrix_B = the matrix B
    */
    // init the result matrix
    int** subtractedMatrix = initMatrix(size_Sub, size_Sub);
    // start subtraction operation
    for (int i; i < size_Sub; i++)
        for (int j; j < size_Sub; j++)
            subtractedMatrix[i][j] = matrix_A[row0A + i][col0A + j] - matrix_B[row0B + i][col0B + j];

    return subtractedMatrix;
}