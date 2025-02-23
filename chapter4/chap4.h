#ifndef CHAP4_H
#define CHAP4_H

int* TransMaxSubArray(int* A, int low, int high);
int* DivMaxSubArray(int*A, int low, int high);
int* BruteMaxSubArray(int* A, int low, int high);
int* SafeDivMaxSubArray(int*A, int low, int high);
int* SafeBruteMaxSubArray(int* A, int low, int high);

// LOCATION: chap4_2.c

int** basicMatrixCross(int x, int y, int z, int A[x][y], int B[y][z]);
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

#endif