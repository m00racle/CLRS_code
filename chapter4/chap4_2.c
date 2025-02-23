#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
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