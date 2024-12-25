#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/testfrm.h"

void test_addition()
{
    printf("returned: %d", intAssertEquals(2+3, 5, "TEST TRUE ADDITION", false));
    bool fAdd = intAssertEquals(2+3, 6, "TEST false ADDITION", true);
    if (fAdd == false) printf("false");
}

int main()
{
    test_addition();
    return 0;
}