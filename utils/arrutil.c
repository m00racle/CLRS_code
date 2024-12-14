#include <stdio.h>
#include <stdlib.h>


void intArrCopy(int *src, int *dest, int l)
{
    /*
        copy data elements from src int array to dest int array

        Paramaeters: 
            - src : int array 
            - dest : int array
            - l : int the number of data element want to copy from src to dest
    */

    // begin copy each element from src to dest
    for (int i = 0; i < l; i++) dest[i] = src[i];
}


void intArrPrint(int *A, int l)
{
    /*
        Print the elements of an Array

        Parameters:
            - A : array of int
            - l (int) : the amount of the array elements want to be printed > 0
    */
    printf("{");
    for (int i = 0; i < l - 1; i++) printf("%d, ", A[i]);

    // in case the l is 1 or less even negative just print out the first element
    // else print each element then end it with crlf char.
    if (l <= 1) printf("%d}\n", A[0]); else printf("%d}\n", A[l - 1]);
}


void intArrSet(int *A, int l, int s)
{
    /*  
        Set or Reset elements of int array

        Parameters:
            - A : int array
            - l : (int) number of element to be set/reset
            - s : (int) value to be set to each element
    */
    for (int i = 0; i < l; i++) A[i] = s;
}


char *intArrStr(int *A, int l)
{
    /*
        return string version of the array to use inside printf
        
        Parameters:
            - A : array of ints
            - l : length of element to convert to string
        
        Return: char[]
    */
    static char *r;

    return r;
}