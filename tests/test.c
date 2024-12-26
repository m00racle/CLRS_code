#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/testfrm.h"
#include "../utils/arrutil.h"

void test_addition()
{
    printf("returned: %d", intAssertEquals(2+3, 5, "TEST TRUE ADDITION", false));
    bool fAdd = intAssertEquals(2+3, 6, "TEST false ADDITION", true);
    if (fAdd == false) printf("false\n");
}

void test_array()
{
    int A[5] = {1,2,91,4,5};
    int B[5] = {1,2,3,4,60};
    // you must declare and define the array before using it as argument to assert

    intArrayAssertEquals(A, B, 5, "ARRAY FALSE", true);
    
    // now we test result true because we just want to evaluate two elements between A and B:
    intArrayAssertEquals(A, B, 2, "ARRAY TRUE", true);
}

int main()
{
    test_addition();
    test_array();
    return 0;
}