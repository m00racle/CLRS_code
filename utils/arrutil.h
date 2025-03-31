#ifndef ARRUTIL_H
#define ARRUTIL_H

/*
    utilities to handle common function for array
    make sure to read the short documentation 
*/

// copy array of int(s) from one array to other array
void intArrCopy(int *src, int *dest, int l);

// print elements of an array of int
void intArrPrint(int *A, int l);

// set or reset elements of an array of int
void intArrSet(int *A, int l, int s);

// return string version of the array to use inside printf
char *intArrStr(int *A, int l);

// return string version of matrix in form of array of arrays
char *intMatrixStr(int r, int c, int A[r][c]);
// return string version of matrix POINTER of 2D array
char *intMatrixPtr(int r, int c, int** A);

int** initMatrix(int r, int c);
    /* 
        function: initMatrix
        initiate all zero matrix
        the main purpose is to set aside and prepare enough memory in heap
        to accomodate certain size of 2D array represent a matrix

        WARNING: located in heap, FREE in the end of the process

        Return: int** pointer 2D array will all 0s elements

        parameters:
        int r : number or rows for the matrix
        int c : number of columns for the matrizx
    */

void freeMatrix(int** A, int r);
    /* 
        function: freeMatrix
        free the heap memory allcated to 2D array matrix

        Return: void

        Paramters:
        int** A: 2D int array represent the matrix in the heap
        int r: number of rows in matrix A
    */

int** setMatrix(int r, int c, int B[r][c]);
    /*  
        FUNCTION: setMatrix
        set matrix by filling the matrix elements represented by 2D array in the heap 
        with element of another matrix in 2D array in stack (manually initiated)

        Return: int** 2D array matrix filled its elements with specified 

        Parameters:
        int r: number of rows of 2D array matrix to set
        int c: number of columns of 2D array matrix to set
        int B[][] : the stack 2D array matrix which element wanted to transfer to heap
    */

bool isPowerofTwo(int n);
    /*  
        find out whether n is power of two
        PARAMETERS 
        int n = integer tested whether it is power of two or not!
    */

int** paddingMatrix(int ori_row, int ori_col, int Mat[ori_row][ori_col], int pad_size);
    /*  
        convert original matrix into square matrix of n x n which n is power of two

        RETURN: int** pointer matrix

        PARAMS:
        int ori_row : original row size of Matrix
        int ori_col : original column size of Matrix
        int Mat[][] : the original matrix
        int pad_size : the size of row of the padded matrix returned
    */

int** reduceMatrix(int spec_row, int spec_col, int** bigger_matrix);
    /*  
        reduces big matrix elements onto matrix of specified row and column size
        
        WARNING: this function does NOT clear memory of the bigger matrix always 
        clear the bigger matrix memory allocation once this function is destroyed

        RETURN: int** matrix which reduced version of the bigger matrix

        PARAMETERS:
        int spec_row = specified rows size of the reduced matrix
        int spec_col = specified column size of the reduced matrix
        int** bigger_matrix = the matrix to be reduced
    */


#endif