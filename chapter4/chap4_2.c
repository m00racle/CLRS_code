#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "../utils/arrutil.h"

/*  
    4.2 Strassen’s algorithm for matrix multiplication
*/

int** basicMatrixMultiply(int x, int y, int z, int A[x][y], int B[y][z])
{
    /* 
        Basic Matrix Multiplication -> C = A x B

        Return int** 2D Array

        Parameters:
        int x : number of rows in first matrix (A)
        int y : number of column(s) of first matrix (A), rows in second matrix (B)
        int z : number of column(s) of second matrix (B) 
        int A[][] : first matrix with x rows and y columns
        int B[][] : second matrix with y rows and z columns
    */
    
    // initialize 2D matrix
    int** C = (int**)malloc(x * sizeof(int*));
    for (int h = 0; h < x; h++)
    {
        C[h] = (int*)malloc(z * sizeof(int));
    }

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