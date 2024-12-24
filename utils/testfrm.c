#include <stdio.h>
#include <stdlib.h>

/*
    unit test framewok 
*/

void intAssertEquals(int value, int target, char* test_id)
{
    if (value == target) 
    {
        printf("test pass: %s\n", test_id);
    } else
    {
        printf("test failed: %s\n", test_id);
        printf("  cause: value %d is not the same as the target %d\n", value, target);
    }
}