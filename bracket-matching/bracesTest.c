#include <stdio.h>
#include "testUtils.h"
#include "braces.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_returns_false_if_string_not_matches(){
	String str = "([]";
	ASSERT(braceMatch(str) == false);
}

void test_2_returns_true_if_string_matches(){
	String str = "()";
	ASSERT(braceMatch(str) == true);
}

void test_3_returns_true_if_whole_string_matches(){
	String str = "{([])}";
	ASSERT(braceMatch(str) == true);
}

void test_4_returns_false_if_string_does_not_match(){
	String str = "[]}";
	ASSERT(braceMatch(str) == false);
}

void test_5_returns_false_if_string_not_matches(){
	String str = "[{]";
	ASSERT(braceMatch(str) == false);
}
void test_fail(){
	ASSERT(0);
}
