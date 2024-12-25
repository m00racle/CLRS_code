#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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