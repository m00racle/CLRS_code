#include <stdio.h>
#include <stdlib.h>

/*
    unit test framewok 
*/

void intAssertEquals(int value, int target, char* test_id)
{
    printf("\nTEST ID: %s\n", test_id);
    if (value == target) 
    {
        printf("test pass: the value %d is the same as target %d\n", value, target);
    } else
    {
        printf("test failed: \n" );
        printf("  cause: value %d is not the same as the target %d\n", value, target);
    }
}