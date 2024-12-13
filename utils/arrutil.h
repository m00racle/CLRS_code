#ifndef ARRUTIL_H
#define ARRUTIL_H

/*
    utilities to handle common function for array
    make sure to read the short documentation 
*/

// copy array of int(s) from one array to other array
// Parameters:
// - src : int array which source of the copied data
// - dest : int array prepared as the destination of the copy
// - l : int length of the copied data (in numvber not in memory size)
void intArrCopy(int *src, int *dest, int l);

// print elements of an array of int
// Parameters:
// - A : array of ints 
// - l : int number of element to print
void intArrPrint(int *A, int l);

// set or reset elements of an array of int
// Parameters:
// - A : array of ints
// - l : amount of data element want to be reset
// - s : set/reset value (int)
void intArrSet(int *A, int l, int s);

#endif