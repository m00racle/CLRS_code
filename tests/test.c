#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/testfrm.h"
#include "../utils/arrutil.h"
#include "../chapter2/chap2.h"
#include "../chapter4/chap4.h"

void test_array()
{
    int A[5] = {1,2,91,4,5};
    int B[5] = {1,2,3,4,60};
    // you must declare and define the array before using it as argument to assert

    intArrayAssertEquals(A, B, 5, "ARRAY FALSE", true);
    printf("NOTE: ARRAY FALSE test is DELIBERATELY TO BE FAIL!! NOTHING TO CHANGE HERE!");
    
    // now we test result true because we just want to evaluate two elements between A and B:
    intArrayAssertEquals(A, B, 2, "ARRAY TRUE", true);
}

void test_chapter2()
{
    // Arrange:
    // rev1 is the array to be sorted using insertion sort:
    int rev1[9] = {4,3,2,1,0,-1,-2,-3,-4};
    // rev2 is the array to be sorted using merge sort:
    int rev2[9] = {4,3,2,1,0,-1,-2,-3,-4};
    // norm is the control array which will be used as target to check sorting of rev1 and rev2
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

void test_chapter4()
{
    printf("\nTest cases for chapter 4: Divide and Conquer\n");
    // test original data: I will directly using the transformed data of closing price daily changes data
    int ori[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int ori_length = sizeof(ori) / sizeof(ori[0]);
    int oriExp[] = {7, 10, 43};
    // test case all positive price change
    int all_increase[] = {7,6,5,4,3,2,1};
    int all_increaseExp[] = {0, 6, 28};
    // test case all negative price changes
    int all_down[] = {-10,-2,-3,-4,-5,-1,-2};
    int all_downExp[] = {0,0,0};
    int all_downAlt[] = {5,5,-1};

    // CAUTION: actions and asserts must be done by data segment since the max data uses pointer to same array
    // thus changing case will also change the data used for other assertions!
    // ori data
    printf("\nthe Ori Data: %s\n", intArrStr(ori, ori_length));
    int* ori_trans = TransMaxSubArray(ori, 0, ori_length - 1);
    intArrayAssertEquals(ori_trans, oriExp, 3, "Trans Max Sub Array on Ori Data", true);
    // using divide can conquer
    int* ori_div = DivMaxSubArray(ori, 0, ori_length -1);
    intArrayAssertEquals(ori_div, oriExp, 3, "Div Max Sub Array on Ori Data", true);
    // using brute force
    int* ori_brute= BruteMaxSubArray(ori, 0, ori_length -1);
    intArrayAssertEquals(ori_brute, oriExp, 3, "Brute Max Sub Array on Ori Data", true);
    
    // all increase case data
    printf("\nthe all increase data: %s\n", intArrStr(all_increase, 7));
    int* increase_trans = TransMaxSubArray(all_increase, 0, 6);
    intArrayAssertEquals(increase_trans, all_increaseExp, 3, "Trans Max Sub Array all increase data", true);
    // using divide and conquer
    int* increase_div = DivMaxSubArray(all_increase, 0, 6);
    intArrayAssertEquals(increase_div, all_increaseExp, 3, "Div Max Sub Array all increase data", true);
    // using brute force
    int* increase_brute = BruteMaxSubArray(all_increase, 0, 6);
    intArrayAssertEquals(increase_brute, all_increaseExp, 3, "Brute Max Sub Array all increase data", true);

    // all negative data
    printf("\nthe all negative data: %s", intArrStr(all_down, 7));
    int* down_trans = TransMaxSubArray(all_down, 0, 6);
    intArrayAssertEquals(down_trans, all_downExp, 3, "Trans Max Sub Array all negative data", true);
    // using divide and conquer
    int* down_div = DivMaxSubArray(all_down, 0, 6);
    intArrayAssertEquals(down_div, all_downAlt, 3, "Div Max Sub Array all negative data", true);
    // using brute force
    int* down_brute = BruteMaxSubArray(all_down, 0, 6);
    intArrayAssertEquals(down_brute, all_downAlt, 3, "Brute Max Sub Array allnegative data", true);
}

int main()
{
    test_array();
    test_chapter2();
    test_chapter4();
    return 0;
}