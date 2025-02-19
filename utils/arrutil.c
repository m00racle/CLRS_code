#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    
    // I want to put the static in heap not in stack to ensure it survive multi scope functions
    static char z[10000];

    // reset the string to empty:
    // if NOT since we use concatenation by strcat the new int array will be put after the old one if exist!!
    strcpy(z, "");

    // put opening {:
    strcat(z, "{");
    
    // iterate all element in A and change them to char then concatenate to r:
    for (int i = 0; i < l; i++)
    {
        // prepare place to store the added elemeent
        char sint[5];
        // change the int into char
        sprintf(sint, "%d", A[i]);
        // concat to z:
        strcat(z, sint);
        // add commas and space except the last element:
        if (i < l - 1)
        {
            strcat(z, ", ");
        }
    }
    // add closure }
    strcat(z, "}");

    return z;
}

char *intMatrixStr(int r, int c, int A[r][c])
{
    /* 
        make string version of matrix in form of Array of Arrays

        Return: char*

        Parameters:
        - int r : number of matrix rows
        - int c : number of matrix columns
        - int A[][] : the matrix in form of array of arrays
    */
    
    //initialize static char
    static char x[50000];
    //reset the x
    strcpy(x, "");
    //put opening bracket
    strcat(x, "{");

    for (int j = 0; j < r; j++)
    {
        //convert the arrays inside 
        strcat(x, intArrStr(A[j], c));
        // add comma between inside arrays
        if (j < r-1)
        {
            strcat(x,", ");
        }
        
    }
    //add closure in the end
    strcat(x, "}");

    return x;
}