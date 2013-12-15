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

	testStarted("test_1_creates_integer_stack");
	setup();
		test_1_creates_integer_stack();
	tearDown();
	testEnded();
	testStarted("test_2_pushes_an_integer_element_in_the_stack");
	setup();
		test_2_pushes_an_integer_element_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_3_pushes_an_float_element_in_the_stack");
	setup();
		test_3_pushes_an_float_element_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_4_pushes_an_double_element_in_the_stack");
	setup();
		test_4_pushes_an_double_element_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_5_pushes_an_character_element_in_the_stack");
	setup();
		test_5_pushes_an_character_element_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_6_pushes_an_string_in_the_stack");
	setup();
		test_6_pushes_an_string_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_7_pushes_multiple_integer_elements_in_the_stack");
	setup();
		test_7_pushes_multiple_integer_elements_in_the_stack();
	tearDown();
	testEnded();
	testStarted("test_8_pops_integer_element_from_the_stack");
	setup();
		test_8_pops_integer_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_9_pops_float_element_from_the_stack");
	setup();
		test_9_pops_float_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_10_pops_double_element_from_the_stack");
	setup();
		test_10_pops_double_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_11_pops_character_element_from_the_stack");
	setup();
		test_11_pops_character_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_12_pops_string_element_from_the_stack");
	setup();
		test_12_pops_string_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_13_cannot_pop_element_from_the_empty_stack");
	setup();
		test_13_cannot_pop_element_from_the_empty_stack();
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
