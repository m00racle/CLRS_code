#ifndef CHAP4_H
#define CHAP4_H

int* TransMaxSubArray(int* A, int low, int high);
int* DivMaxSubArray(int*A, int low, int high);
int* BruteMaxSubArray(int* A, int low, int high);
int* SafeDivMaxSubArray(int*A, int low, int high);
int* SafeBruteMaxSubArray(int* A, int low, int high);
void basicMatrixMultiply(int x, int y, int z, int A[x][y], int B[y][z], int C[x][z]);
void squareMatrixMultiply(int n, int A[n][n], int B[n][n], int C[n][n]);

#endif