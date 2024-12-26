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
    int A[5] = {1,2,3,4,5};
    int B[5] = {1,2,3,4,60};
    intArrayAssertEquals(A, B, 5, "ARRAY TRUE", true);
}

int main()
{
    test_addition();
    test_array();
    return 0;
}