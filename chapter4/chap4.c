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
            end = i; // TODO validate this
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
    return NULL;
}