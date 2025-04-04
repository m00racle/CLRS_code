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

int** sumStrassenMatrix(int size_Add, int** matrix_A, int** matrix_B)
{
    /*  
        Add two (pointer based) matrices for Strassen's recursive steps
        
        Also correspond to different basis sizes 
        WARNING: this is for strassen's algorithm use only
        The function assumes that the size to add is ALWAYS a square matrix
        It is the caller function responsibility to ensure that the size_Add is appropriate

        RETURN: int** matrix with size = size_Add x size_Add

        PARAMTERS:
        int size_Add = the size of row or col of the addition area
        int** matrix_A = the matrix A 
        int** matrix_B = the matrix B
    */
    // initiate the result matrix
    int** summedMatrix = initMatrix(size_Add, size_Add);
    //start addition operations
    for (int i = 0; i < size_Add; i++)
        for (int j = 0; j < size_Add; j++)
            summedMatrix[i][j] = matrix_A[i][j] + matrix_B[i][j];
    
    return summedMatrix;
}

int** subStrassenMatrix(int size_Sub, int** matrix_A, int** matrix_B)
{
    /*  
        Subtract matrices A - B for Strassen's recursive steps

        Also correspond to different basis sizes 
        WARNING: this is for strassen's algorithm use only
        The function assumes that the size to add is ALWAYS a square matrix
        It is the caller function responsibility to ensure that the size_Add is appropriate

        RETURN: int** matrix with size = size_Add x size_Add

        PARAMTERS:
        int size_Add = the size of row or col of the subtraction area
        int** matrix_A = the matrix A 
        int** matrix_B = the matrix B
    */
    // init the result matrix
    int** subtractedMatrix = initMatrix(size_Sub, size_Sub);
    // start subtraction operation
    for (int i = 0; i < size_Sub; i++)
        for (int j = 0; j < size_Sub; j++)
            subtractedMatrix[i][j] = matrix_A[i][j] - matrix_B[i][j];

    return subtractedMatrix;
}

void putStrassenMatrix(int size_put, int** source, int row0to, int col0to, int** target)
{
    /*
        Put elements of source onto target 
        But can choose which elements from source to be transferred 
        And can choose where in the target those element would be put

        RETURN: void

        PARAMETERS: 
        int size_put = the size of the element (row or col NOT row x col) of the operation
        int** source = matrix used as source of elements to be put
        int row0to = starting row index in target matrix which element to be substitute with element from source
        int col0to = starting column index in target matrix which element to be substitute with element from source
        int** target = target matrix in which its elements to be substituted by elements from source matrix
    */
    // start the iteration using row and column start plus the size
    for (int i = 0; i < size_put; i++)
        for (int j = 0; j < size_put; j++)
            target[row0to + i][col0to + j] = source[i][j];

}

int** splitStrassenMatrix(int ext_size, int row0, int col0, int** ori_matrix)
{
    /* 
        Split and extract the part of the matrix into smaller matrix
        ASSUMES : the ori_matrix is n x n square matrix which n is power of two
        
        RETURN: int** smaller n/2 x n/2 matrix

        PARAMETERS =
        int ext_size = size of the extraction row wise or column wise 
        int row0 = the starting row index for split and extract operation will begin
        int col0 = the starting column index for split and extract operation will begin
        int** ori_matrix = 2D array pointer represent original matrix to be splitted and extracted
    */
    // initial returned matrix for extracted elements from splitted matrix
    int** ext_matrix = initMatrix(ext_size, ext_size);
    // begin extracting elements from original matrix based on index position
    for (int i = 0 ; i < ext_size; i++)
        for (int j = 0; j < ext_size; j++)
            ext_matrix[i][j] = ori_matrix[row0 + i][col0 + j];

    return ext_matrix;
}

int** recursiveStrassen(int matrix_size, int** A, int** B)
    /* 
        recursive steps of Strassen's algorithm
    */
{
    // initialize multiplication result matrix
    int** C = initMatrix(matrix_size, matrix_size);
    // base case 
    if (matrix_size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];   
    } else
    {
        // divide the size
        int n = matrix_size/2;
        // extract each matrix into size/2 x size /2 
        int** A11 = splitStrassenMatrix(n, 0, 0, A);
        int** A12 = splitStrassenMatrix(n, 0, n, A);
        int** A21 = splitStrassenMatrix(n, n, 0, A);
        int** A22 = splitStrassenMatrix(n, n, n, A);
        int** B11 = splitStrassenMatrix(n, 0, 0, B);
        int** B12 = splitStrassenMatrix(n, 0, n, B);
        int** B21 = splitStrassenMatrix(n, n, 0, B);
        int** B22 = splitStrassenMatrix(n, n, n, B);
        // start making matrices S1 up to S10
        int** S1 = subStrassenMatrix(n, B12, B22);
        int** S2 = sumStrassenMatrix(n, A11, A12);
        int** S3 = sumStrassenMatrix(n, A21, A22);
        int** S4 = subStrassenMatrix(n, B21, B11);
        int** S5 = sumStrassenMatrix(n, A11, A22);
        int** S6 = sumStrassenMatrix(n, B11, B22);
        int** S7 = subStrassenMatrix(n, A12, A22);
        int** S8 = sumStrassenMatrix(n, B21, B22);
        int** S9 = subStrassenMatrix(n, A11, A21);
        int** S10 = sumStrassenMatrix(n, B11, B12);
        // free unused splits matrices
        freeMatrix(A12, n);
        freeMatrix(A21, n);
        freeMatrix(B12, n);
        freeMatrix(B21, n);
        // recursive steps
        int** P1 = recursiveStrassen(n, A11, S1);
        int** P2 = recursiveStrassen(n, S2, B22);
        int** P3 = recursiveStrassen(n, S3, B11);
        int** P4 = recursiveStrassen(n, A22, S4);
        int** P5 = recursiveStrassen(n, S5, S6);
        int** P6 = recursiveStrassen(n, S7, S8);
        int** P7 = recursiveStrassen(n, S9, S10);
        // clean the rest of As and Ss
        freeMatrix(A11, n);
        freeMatrix(A22, n);
        freeMatrix(B11, n);
        freeMatrix(B22, n);
        freeMatrix(S1, n);
        freeMatrix(S2, n);
        freeMatrix(S3, n);
        freeMatrix(S4, n);
        freeMatrix(S5, n);
        freeMatrix(S6, n);
        freeMatrix(S7, n);
        freeMatrix(S8, n);
        freeMatrix(S9, n);
        freeMatrix(S10, n);
        // arrange the part of matrix C from Ps
        int** C11L = sumStrassenMatrix(n, P5, P4);
        int** C11R = subStrassenMatrix(n, P2, P6);
        int** C11 = subStrassenMatrix(n, C11L, C11R);
        int** C12 = sumStrassenMatrix(n, P1, P2);
        int** C21 = sumStrassenMatrix(n, P3, P4);
        int** C22L = sumStrassenMatrix(n, P5, P1);
        int** C22R = sumStrassenMatrix(n, P3, P7);
        int** C22 = subStrassenMatrix(n, C22L, C22R);
        // free unused matrices
        freeMatrix(P1, n);
        freeMatrix(P2, n);
        freeMatrix(P3, n);
        freeMatrix(P4, n);
        freeMatrix(P5, n);
        freeMatrix(P6, n);
        freeMatrix(P7, n);
        freeMatrix(C11L, n);
        freeMatrix(C11R, n);
        freeMatrix(C22L, n);
        freeMatrix(C22R, n);
        // put the part of the matrix back to matrix C
        putStrassenMatrix(n, C11, 0, 0, C);
        putStrassenMatrix(n, C12, 0, n, C);
        putStrassenMatrix(n, C21, n, 0, C);
        putStrassenMatrix(n, C22, n, n, C);
        //free 4 last matrices called by this funcition
        freeMatrix(C11, n);
        freeMatrix(C12, n);
        freeMatrix(C21, n);
        freeMatrix(C22, n);
    }
    return C;
}

int** basicStrassenCross(int x, int y, int z, int A[x][y], int B[y][z])
{
    /*  
        FUNCTION: basicStrassenCross
        matrix multiplication using Strassen's algorithm

        Return: int** 2D array matrix result of multiplicaton
        CAUTION: return pointer onto heap memory. Always clear afterwards to avoid memory leak!

        Parameters: 
        int x : number of rows in first matrix (A)
        int y : number of column(s) of first matrix (A), rows in second matrix (B)
        int z : number of column(s) of second matrix (B) 
        int A[][] : first matrix with x rows and y columns
        int B[][] : second matrix with y rows and z columns 
    */
    // finding largest size as basic for padding factor
    int max_size;
    if (x > y)
    {
        max_size = x;
    } else 
    {
        max_size = y;
    }
    // test final against z
    if (z > y) max_size = z;
    // finding padding factor
    int pad_size;
    if (isPowerofTwo(max_size))
    {
        pad_size = max_size;
    } else
    {
        int log_2Val = log2(max_size);
        // increment log_2Val to increase to the nearest power of two above max size
        log_2Val++;
        pad_size = pow(2,log_2Val);
    }
    // put each input matrix to padding process to convert them to heap pointers
    int** padA = paddingMatrix(x, y, A, pad_size);
    int** padB = paddingMatrix(y, z, B, pad_size);
    // multiply padded A and B
    int** padC = recursiveStrassen(pad_size, padA, padB);
    // free the padded A and B
    freeMatrix(padA, pad_size);
    freeMatrix(padB, pad_size);
    //extract C from the padded C matrix
    int** C = reduceMatrix(x, z, padC);
    // free padded C 
    freeMatrix(padC, pad_size);
    
    return C;
}

int** squareStrassenCross(int n, int A[n][n], int B[n][n])
{
    /*  
        FUNCTION: squareStrassenCross
        matrix multiplication using Strassen's algorithm for square matrix both inputs

        Return: int** 2D array matrix result of multiplicaton
        CAUTION: return pointer onto heap memory. Always clear afterwards to avoid memory leak!

        Parameters: 
        int n : number of rows or columns for all matrices involved in calculation
        int A[][]
        int B[][]
    */
    // pass the input onto basic StrassenCross
    return basicStrassenCross(n, n, n, A, B);
}