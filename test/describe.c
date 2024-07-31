#include <string.h>

#include "w/t35t/assert.h"
#include "w/t35t/test.h"

#include "../describe.h"

TestResult
TestDescribeBuffer(TestContext *tc) {
	char *hw = "Hello world";
	Buffer buf = B_Wrap(hw, strlen(hw)); 

	String actual = u_Describe(buf);
	String expected = S_Wrap("[ 0x48 0x65 0x6c 0x6c 0x6f 0x20 0x77 0x6f    0x72 0x6c 0x64 ]");
	AssertEquals(actual, expected);

	return TEST_OK;
}

int main() {
	TestContext tc = tTC_Alloc();	

	tTC_AddTest(&tc, TestDescribeBuffer);

	return tTC_Engage(&tc);
}
