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

	testStarted("test_1_creates_a_new_process");
	setup();
		test_1_creates_a_new_process();
	tearDown();
	testEnded();
	testStarted("test_2_adds_first_element_in_queue_of_integer");
	setup();
		test_2_adds_first_element_in_queue_of_integer();
	tearDown();
	testEnded();
	testStarted("test_3_adds_first_element_in_queue_of_float");
	setup();
		test_3_adds_first_element_in_queue_of_float();
	tearDown();
	testEnded();
	testStarted("test_4_adds_first_element_in_queue_of_double");
	setup();
		test_4_adds_first_element_in_queue_of_double();
	tearDown();
	testEnded();
	testStarted("test_5_adds_first_element_in_queue_of_characters");
	setup();
		test_5_adds_first_element_in_queue_of_characters();
	tearDown();
	testEnded();
	testStarted("test_6_adds_first_element_in_queue_of_string");
	setup();
		test_6_adds_first_element_in_queue_of_string();
	tearDown();
	testEnded();
	testStarted("test_7_adds_element_of_high_priority_rather_than_first_for_integer");
	setup();
		test_7_adds_element_of_high_priority_rather_than_first_for_integer();
	tearDown();
	testEnded();
	testStarted("test_8_adds_element_of_high_priority_rather_than_first_for_float");
	setup();
		test_8_adds_element_of_high_priority_rather_than_first_for_float();
	tearDown();
	testEnded();
	testStarted("test_9_adds_element_of_high_priority_rather_than_first_for_character");
	setup();
		test_9_adds_element_of_high_priority_rather_than_first_for_character();
	tearDown();
	testEnded();
	testStarted("test_10_adds_element_of_high_priority_rather_than_first_for_string");
	setup();
		test_10_adds_element_of_high_priority_rather_than_first_for_string();
	tearDown();
	testEnded();
	testStarted("test_11_adds_element_of_priority_in_between_for_integer_queue");
	setup();
		test_11_adds_element_of_priority_in_between_for_integer_queue();
	tearDown();
	testEnded();
	testStarted("test_12_adds_element_of_priority_in_between_for_character_queue");
	setup();
		test_12_adds_element_of_priority_in_between_for_character_queue();
	tearDown();
	testEnded();
	testStarted("test_13_removes_element_as_per_given_priority");
	setup();
		test_13_removes_element_as_per_given_priority();
	tearDown();
	testEnded();
	testStarted("test_14_cannot_remove_an_element_from_empty_queue");
	setup();
		test_14_cannot_remove_an_element_from_empty_queue();
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

void fixtureSetup(){}

void fixtureTearDown(){}
