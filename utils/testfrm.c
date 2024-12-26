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
            if (verbose) printf("  - fail: input index %d is %d when it shoud be %d in target\n", i, input[i], target[i]);
        }
    }

    if (verbose)
    {
        if (flag)
        {
            printf("-> Test Passed\n");
            printf("input:\n%s\nequals to\n%s\ntarget", intArrStr(input, length), intArrStr(target, length));
        } else
        {
            printf("-> Test Failed!\n");
            printf("input:\n%s\ndiffrent to\n%s\ntarget", intArrStr(input, length), intArrStr(target, length));
        }
    }

    return flag;
}