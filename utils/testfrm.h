#ifndef TESTFRM_H
#define TESTFRM_H

/*
    Utilities Framework for Unit Test

    This mostly handling assertions
*/

bool boolAssertFalse(int value, char* test_id, bool verbose);
bool boolAssertTrue(int value, char* test_id, bool verbose);
bool intAssertEquals(int value, int target, char* test_id, bool verbose);

#endif