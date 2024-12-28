#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "../utils/arrutil.h"

int* TransMaxSubArray(int* A, int low, int high)
{
    /*
        Find the max sub array data (start of the index of the array, then end index and value)
        Return Array {start, end, value}

        Parameters:
        A (array of ints) : array of the daily change of price
        low: int lowest index of A array to be processed
        high: int highest index of A array to be processed
    */
    // transformed brute force
    static int max_data[3];
    // set / reset max data for each process 
    intArrSet(max_data, 3, 0);

    // initialize values:
    int sum = 0;
    int max_sum = 0;
    int start = low; // start inces of contigous sub array
    int end; // end of the contiguous sub array

    for (int i = low; i <= high; i++)
    {
        // add sum to the current day price change
        sum += A[i];

        // only put contagous sub array if the sum is higher
        if (sum > max_sum)
        {
            // put into max data
            max_sum = sum;
            end = i; 
        } else if (sum < 0)
        {
            // new low detected thus it need to be new start
            // but first maintain latest max sum
            if (max_sum > max_data[2])
            {
                // put the data in the max data
                max_data[0] = start; max_data[1] = end; max_data[2] = max_sum;
            }
            //  because it is low take it as new start
            start = i + 1;
            // reset sum back to 0
            sum = 0;
        }
    }
    // there still oen sub array data after the for loop iteration finish
    // chek if the last sub array is better
    if (max_sum > max_data[2])
    {
        // put the last data to max data
        max_data[0] = start; max_data[1] = end; max_data[2] = max_sum;
    }

    return max_data;
}

int* FindMaxCrossSubArray(int* A, int low, int mid, int high)
{
    /*
        Helper function should be only accessed using div max sub array function:
        Calculate the sum of max sub-array combined from 2 different divided sub array
        Return array 

        Parameters:
        A : array of ints consist of price changes data
        low: int lowest index of A array to be processed
        high: int highest index of A array to be processed
    */
    // cross between two sub array sum
    // initial left side
    int left_sum = INT_MIN;
    int max_left;
    // initial right side
    int right_sum = INT_MIN;
    int max_right; 

    // set init sum from 0
    int sum = 0;

    // prepare result array to be returned (no need to set/reset since the value kept updated)
    static int result[3];

    // decrement the index for the left side
    for (int i = mid; i >= low; i--)
    {
        // find max in left
        sum += A[i];
        if (sum > left_sum)
        {
            // put this the max sum on the left
            left_sum = sum;
            max_left = i;
        }
    }

    // increment the right side 
    // reset sum back to zero
    sum = 0;

    for (int j = mid + 1; j <= high; j++)
    {
        // find the max in the right
        sum += A[j];
        if (sum > right_sum)
        {
            // put this as max in the right
            right_sum = sum;
            max_right = j;
        }
    }

    // put the combined left and right results to result array 
    result[0] = max_left; // the start of cross max array
    result[1] = max_right; // the end of cross max array
    result[2] = left_sum + right_sum; // value of teh cross max subarray

    return result;
}

int* DivMaxSubArray(int*A, int low, int high)
{
    /*
        Find the max sub array data using divide and conquer
        Return Array {start, end, value}

        Parameters:
        A : array of ints consist of price changes data
        low: int lowest index of A array to be processed
        high: int highest index of A array to be processed
    */
    // divide and conquer
    // prepare static array to return
    static int div_data[3];
    
    // declare arrays to store low, high indexes, and max sum of each merge part
    int left_data[3];
    int right_data[3];
    int cross_data[3];

    int mid;

    // base case
    if (high == low)
    {
        // meaning only one data left
        div_data[0] = low;
        div_data[1] = high;
        div_data[2] = A[low];

        return div_data;
    } else // recursive case
    {
        mid = floor((low + high) / 2);

        // merge steps: 
        // CAUTION using copy array since you can't directly assign array in C
        intArrCopy(DivMaxSubArray(A, low, mid), left_data, 3);
        intArrCopy(DivMaxSubArray(A, mid + 1, high), right_data, 3);
        intArrCopy(FindMaxCrossSubArray(A, low, mid, high), cross_data, 3);

        if (left_data[2] >= right_data[2] && left_data[2] >= cross_data[2])
        {
            intArrCopy(left_data, div_data, 3);
        } else if (right_data[2] > left_data[2] && right_data[2] > cross_data[2])
        {
            intArrCopy(right_data, div_data, 3);
        } else
        {
            intArrCopy(cross_data, div_data, 3);
        }
    }
    // guard if there is negative sum:
    if (div_data[2] < 0) intArrSet(div_data, 3, 0);

    return div_data;
}