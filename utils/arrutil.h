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

#endif