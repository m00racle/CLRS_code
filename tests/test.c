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
    // using safe divide and conquer
    int* safe_ori_div = SafeDivMaxSubArray(ori, 0, ori_length -1);
    intArrayAssertEquals(safe_ori_div, oriExp, 3, "Safe Div Max Sub Array on Ori Data", true);
    // using brute force
    int* ori_brute= BruteMaxSubArray(ori, 0, ori_length -1);
    intArrayAssertEquals(ori_brute, oriExp, 3, "Brute Max Sub Array on Ori Data", true);
    // using safe brute force
    int* safe_ori_brute= SafeBruteMaxSubArray(ori, 0, ori_length -1);
    intArrayAssertEquals(safe_ori_brute, oriExp, 3, "Safe Brute Max Sub Array on Ori Data", true);
    
    // all increase case data
    printf("\nthe all increase data: %s\n", intArrStr(all_increase, 7));
    int* increase_trans = TransMaxSubArray(all_increase, 0, 6);
    intArrayAssertEquals(increase_trans, all_increaseExp, 3, "Trans Max Sub Array all increase data", true);
    // using divide and conquer
    int* increase_div = DivMaxSubArray(all_increase, 0, 6);
    intArrayAssertEquals(increase_div, all_increaseExp, 3, "Div Max Sub Array all increase data", true);
    // using safe divide and conquer
    int* safe_increase_div = SafeDivMaxSubArray(all_increase, 0, 6);
    intArrayAssertEquals(safe_increase_div, all_increaseExp, 3, "Safe Div Max Sub Array all increase data", true);
    // using brute force
    int* increase_brute = BruteMaxSubArray(all_increase, 0, 6);
    intArrayAssertEquals(increase_brute, all_increaseExp, 3, "Brute Max Sub Array all increase data", true);
    // using safe brute force
    int* safe_increase_brute = SafeBruteMaxSubArray(all_increase, 0, 6);
    intArrayAssertEquals(safe_increase_brute, all_increaseExp, 3, "Safe Brute Max Sub Array all increase data", true);

    // all negative data
    printf("\nthe all negative data: %s", intArrStr(all_down, 7));
    int* down_trans = TransMaxSubArray(all_down, 0, 6);
    intArrayAssertEquals(down_trans, all_downExp, 3, "Trans Max Sub Array all negative data", true);
    // using divide and conquer
    int* down_div = DivMaxSubArray(all_down, 0, 6);
    intArrayAssertEquals(down_div, all_downAlt, 3, "Div Max Sub Array all negative data", true);
    // using safe divide and conquer
    int* safe_down_div = SafeDivMaxSubArray(all_down, 0, 6);
    intArrayAssertEquals(safe_down_div, all_downExp, 3, "Safe Div Max Sub Array all negative data", true);
    // using brute force
    int* down_brute = BruteMaxSubArray(all_down, 0, 6);
    intArrayAssertEquals(down_brute, all_downAlt, 3, "Brute Max Sub Array allnegative data", true);
    // using safe brute force
    int* safe_down_brute = SafeBruteMaxSubArray(all_down, 0, 6);
    intArrayAssertEquals(safe_down_brute, all_downExp, 3, "Safe Brute Max Sub Array allnegative data", true);
}

void test_chap42()
{
    /* 
        testing for matrix and Strassen algoritm related
    */
    
    // start with the old matrix assert equal tests
    int** init_zeros = initMatrix(2, 3);
    int value_matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int mul_matrix[3][1] = {{1}, {1}, {1}};
    int id3_matrix[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    int squareA_matrix[3][3] = {{1,2,3}, {4,5,6}, {7, 8, 9}};
    
    // comparison 
    int compare_zero[2][3] = {{0, 0, 0}, {0, 0, 0}};
    // TEST: init matrix all zeros
    intMatrixAssertEquals(2, 3, init_zeros, compare_zero, "TEST: init all zero matrix", true);
    //free the heap matrix
    freeMatrix(init_zeros, 2);

    // TEST set matrix
    int** init_set = setMatrix(2, 3, value_matrix);

    //test: set matrix same as value matrix
    intMatrixAssertEquals(2, 3, init_set, value_matrix, "TEST: set values matrix", true);
    // TEST: set matrix but compare to test FALSE assertion
    int wrong_set[2][3] = {{1,2,5}, {5, 7, 6}};
    intMatrixAssertEquals(2, 3, init_set, wrong_set, "TEST: expected to FALSE Asertion", true);
    // free the init set
    freeMatrix(init_set, 2);

    // TEST: matrix cross multiplication
    int** cross_matrix = basicMatrixCross(2, 3, 1, value_matrix, mul_matrix);
    // testing step
    int mul_target[2][1] = {{6},{15}};
    intMatrixAssertEquals(2, 1, cross_matrix, mul_target, "TEST: matrix cross", true);
    // free cross matrix
    freeMatrix(cross_matrix, 2);

    // TEST: square matrix cross multiplicaton
    int** idSquare_cross = squareMatrixCross(3, id3_matrix, squareA_matrix);
    // testing step
    intMatrixAssertEquals(3, 3, idSquare_cross, squareA_matrix, "TEST: square to id matrix cross", true);
    // free is square cross
    freeMatrix(idSquare_cross, 3);

    // test power of two
    boolAssertFalse(isPowerofTwo(5), "TEST: 5 is Power of Two should return FALSE", true);
    boolAssertTrue(isPowerofTwo(8), "TEST: 8 is Power of Two should return TRUE", true);

    // test padding matrix
    int expPadded_value_matrix[4][4] = {{1,2,3,0},{4,5,6,0}, {0,0,0,0},{0,0,0,0}};
    int** padded_value_matrix = paddingMatrix(2, 3, value_matrix, 4);
    intMatrixAssertEquals(4, 4, padded_value_matrix, expPadded_value_matrix, "TEST: padding 2x3 matrix to 4x4", true);
    // free the padded value matrix
    freeMatrix(padded_value_matrix, 4);

    int** padded_zeros = paddingMatrix(2, 3, compare_zero, 4);
    int** reduced_zeros = reduceMatrix(2, 3, padded_zeros);
    intMatrixAssertEquals(2, 3, reduced_zeros, compare_zero, "TEST: reduced padded matrix should return 2 x 3 all zeros", true);
    freeMatrix(padded_zeros, 4);
    freeMatrix(reduced_zeros, 2);

    // TEST: matrix Strassen's multiplication
    // int mul_matrix[3][1] = {{1}, {1}, {1}};
    int** strassen_basic_mul = basicStrassenCross(2, 3, 1, value_matrix, mul_matrix);
    // testing step
    // int mul_target[2][1] = {{6},{15}};
    intMatrixAssertEquals(2, 1, strassen_basic_mul, mul_target, "TEST: Strassen's basic non square matrix cross", true);
    // free cross matrix
    freeMatrix(strassen_basic_mul, 2);
}

int main()
{
    test_array();
    test_chapter2();
    test_chapter4();
    test_chap42();
    return 0;
}