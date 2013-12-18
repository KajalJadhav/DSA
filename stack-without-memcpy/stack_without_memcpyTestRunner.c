#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_creates_stack");
	setup();
		test_1_creates_stack();
	tearDown();
	testEnded();
	testStarted("test_2_pushes_integer_element_in_stack");
	setup();
		test_2_pushes_integer_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_3_pushes_float_element_in_stack");
	setup();
		test_3_pushes_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_4_pushes_character_element_in_stack");
	setup();
		test_4_pushes_character_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_5_pushes_double_element_in_stack");
	setup();
		test_5_pushes_double_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_6_pushes_String_element_in_stack");
	setup();
		test_6_pushes_String_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_7_pops_integer_element_from_stack");
	setup();
		test_7_pops_integer_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_8_pops_float_element_from_stack");
	setup();
		test_8_pops_float_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_9_pops_character_element_from_stack");
	setup();
		test_9_pops_character_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_10_pops_double_element_from_stack");
	setup();
		test_10_pops_double_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_11_pops_string_element_from_stack");
	setup();
		test_11_pops_string_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_12_gives_top_integer_element_of_stack");
	setup();
		test_12_gives_top_integer_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_13_gives_top_float_element_of_stack");
	setup();
		test_13_gives_top_float_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_14_gives_top_double_element_of_stack");
	setup();
		test_14_gives_top_double_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_15_gives_top_character_element_of_stack");
	setup();
		test_15_gives_top_character_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_16_gives_top_string_element_of_stack");
	setup();
		test_16_gives_top_string_element_of_stack();
	tearDown();
	testEnded();
	testStarted("test_fail");
	setup();
		test_fail();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
