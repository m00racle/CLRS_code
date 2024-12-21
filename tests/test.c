#include <stdio.h>
#include <stdlib.h>
#include "../utils/testfrm.h"

void test_addition()
{
    intAssertEquals(2+3, 5, "TEST TRUE ADDITION");
    intAssertEquals(2+3, 6, "TEST false ADDITION");
}

int main()
{
    test_addition();
    return 0;
}