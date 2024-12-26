#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/testfrm.h"
#include "../utils/arrutil.h"
#include "../chapter2/chap2.h"

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

void test_chapter2()
{
    // Arrange:
    int rev1[9] = {4,3,2,1,0,-1,-2,-3,-4};
    int rev2[9] = {4,3,2,1,0,-1,-2,-3,-4};
    int norm[9] = {-4,-3,-2,-1,0,1,2,3,4};

    // act
    printf("\nTest case for Chapter 2:\n");
    printf("rev1 before insertion sort: %s\n", intArrStr(rev1, 9));
    InsertionSort(rev1, 9);
    printf("rev2 before merge sort: %s\n", intArrStr(rev2, 9));
    MergeSort(rev2, 0, 8);

    // assert
    intArrayAssertEquals(rev1, norm, 9, "CHAPTER 2 INSERTION SORT", true);
    intArrayAssertEquals(rev2, norm, 9, "CHAPTER 2 MERGE SORT", true);
}

int main()
{
    test_addition();
    test_array();
    test_chapter2();
    return 0;
}