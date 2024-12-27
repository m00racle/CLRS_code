# CLRS_code
code for complementary studying Introduction to Algorithm book

## Headers Contents
- => utils
    - arrutil
        - void intArrCopy(int *src, int *dest, int l);
        - void intArrPrint(int *A, int l);
        - void intArrSet(int *A, int l, int s);
        - char *intArrStr(int *A, int l);
    - testfrm
        - bool boolAssertFalse(int value, char* test_id, bool verbose);
        - bool boolAssertTrue(int value, char* test_id, bool verbose);     
        - bool intAssertEquals(int value, int target, char* test_id, bool verbose);
        - bool intArrayAssertEquals(int* input, int* target, int length, char* test_id, bool verbose);
    - chapter 2 -> Getting Started
        - void InsertionSort(int *A, int length);
        - void MergeSort(int *A, int p, int r);
    - chapter 4 -> Divide and Conquer
        - int* TransMaxSubArray(int* A, int length) : finding max sub array of A (start, end, value) using transformed brute force
        - int* DivMaxSubArray(int* A, int start, int end) : find max sub array of A using Divide and Conquer approach
