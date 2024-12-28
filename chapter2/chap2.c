#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void InsertionSort(int *A, int length)
{
    // insertion sort
    // declare int data to store soon to be inserted value
    int key;
    // declare i for index moving through the array
    int i;

    for (int j = 1; j < length; j++)
    {
        key = A[j];
        // put the key in slot where it is smaller than existing
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            //shift the elements
            A[i + 1] = A[i];
            // decrement i
            i--;
        }
        // if A[i] > key then stop the shifting; bring back index to before which i + 1 & put the value there
        A[i + 1] = key;
    }
}

void Merge(int* A, int p, int q, int r)
{
    // creating two new arrays
    int n1 = q - p + 1;
    int n2 = r - q;
    // let there be 2 new arrays L and R
    int L[n1 + 1];
    int R[n2 + 1];
    // put the appropriate values inside each L and R sub array
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }
    // add max values in each edge of L and R
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    // start merging
    int m = 0;
    int n = 0;
    // iterate each element from L and R and compare
    for (int k = p; k <= r; k++)
    {
        if (L[m] <= R[n])
        {
            // put element from L to A at index k
            A[k] = L[m];
            // increment index in L
            m++;
        } else
        {
            // put element from R to A at index k
            A[k] = R[n];
            // increment index in R
            n++;
        }
    }
}

void MergeSort(int *A, int p, int r)
{
    // merging
    if (p < r)
    {
        // calculate median value q using floor division
        int q = floor((p + r)/2);
        // recursive steps
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        // merging
        Merge(A, p, q, r);
    }
}
