#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/arrutil.h"

/*
    unit test framewok 
*/

bool boolAssertTrue(int value, char* test_id, bool verbose)
{
    if (verbose) printf("\nTEST ID: %s\n", test_id);
    return value == true;
}

bool boolAssertFalse(int value, char* test_id, bool verbose)
{
    if (verbose) printf("\nTEST ID: %s\n", test_id);
    return value == false;
}

bool intAssertEquals(int value, int target, char* test_id, bool verbose)
{
    if (verbose) printf("\nTEST ID: %s\n", test_id);
    if (value == target) 
    {
        if (verbose) printf("test pass: the value %d is the same as target %d\n", value, target);
        return true;
    } else
    {
        if (verbose)
        {

            printf("test failed: \n" );
            printf("  cause: value %d is not the same as the target %d\n", value, target);
        }
        return false;
    }
}

bool intArrayAssertEquals(int* input, int* target, int length, char* test_id, bool verbose)
{
    if (verbose) printf("\nTEST ID: %s\n", test_id);
    bool flag = true;
    for (int i = 0; i < length; i++) 
    {
        if (input[i] != target[i])
        {
            flag = false;
            if (verbose) printf(" - fail: index %d at input is %d; it shoud be %d as in target\n", i, input[i], target[i]);
        }
    }

    if (verbose)
    {
        if (flag)
        {
            printf("-> Test Passed\n");
            // printf("input:\n%s\nequals to\n%s\ntarget", intArrStr(input, length), intArrStr(target, length));
            // commented out because lead to error as having them in one call to printf will make both print the same
            // string array of char since the intArrStr returns a pointer to the string!
            printf("  input:\n  %s\n", intArrStr(input, length));
            printf("  is equals to target:\n  %s\n", intArrStr(target, length));
        } else
        {
            printf("-> Test Failed!\n");
            // printf("input:\n%s\ndiffrent to\n%s\ntarget", intArrStr(input, length), intArrStr(target, length));
            // commented out because lead to error as having them in one call to printf will make both print the same
            // string array of char since the intArrStr returns a pointer to the string!
            printf("  input:\n  %s\n", intArrStr(input, length));
            printf("  is differs to target:\n  %s\n", intArrStr(target, length));
        }
    }

    return flag;
}

bool intMatrixAssertEquals(int r, int c, int input[r][c], int target[r][c], char* test_id, bool verbose)
{
    /*
        Test if Matrix in the form of Array of int Arrays is equal to target Matrix with the same type
        and dimension

        Return: boolean

        Arguments

        int r: number of matrix rows
        int c: number of matrix columns
        int* input: array of arrays consist of int data type as input to be tested
        int* target: array of arrays consist of int data type as input to be tested 
        char* test_id: string of test identification
        bool verbose: set whether the detail of the test steps are printed out or not
    */

    bool flag = true;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // test one element after another 
            if (input[i][j] != target[i][j]) // error: C can't use index j directly since input is *int
            {
                flag = false;
            }
        }
    }
    return false;
}