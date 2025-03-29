#ifndef TESTFRM_H
#define TESTFRM_H

/*
    Utilities Framework for Unit Test

    This mostly handling assertions
*/

bool boolAssertFalse(int value, char* test_id, bool verbose);
bool boolAssertTrue(int value, char* test_id, bool verbose);
bool intAssertEquals(int value, int target, char* test_id, bool verbose);
bool intArrayAssertEquals(int* input, int* target, int length, char* test_id, bool verbose);
bool intMatrixAssertEquals(int r, int c, int** input, int target[r][c], char* test_id, bool verbose);

#endif