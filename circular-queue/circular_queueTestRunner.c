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

	testStarted("test_1_creates_queue_for_integers");
	setup();
		test_1_creates_queue_for_integers();
	tearDown();
	testEnded();
	testStarted("test_2_creates_queue_for_floats");
	setup();
		test_2_creates_queue_for_floats();
	tearDown();
	testEnded();
	testStarted("test_3_creates_queue_for_characters");
	setup();
		test_3_creates_queue_for_characters();
	tearDown();
	testEnded();
	testStarted("test_4_creates_queue_for_String");
	setup();
		test_4_creates_queue_for_String();
	tearDown();
	testEnded();
	testStarted("test_5_creates_queue_for_double");
	setup();
		test_5_creates_queue_for_double();
	tearDown();
	testEnded();
	testStarted("test_6_for_enqueing_integer_element_in_queue");
	setup();
		test_6_for_enqueing_integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_7_for_enqueing_float_element_in_queue");
	setup();
		test_7_for_enqueing_float_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_8_for_enqueing_double_element_in_queue");
	setup();
		test_8_for_enqueing_double_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_9_for_enqueing_string_element_in_queue");
	setup();
		test_9_for_enqueing_string_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_10_for_enqueing_character_element_in_queue");
	setup();
		test_10_for_enqueing_character_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_11_for_integer_element_into_queue_when_queue_is_full");
	setup();
		test_11_for_integer_element_into_queue_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_12_for_float_element_into_queue_when_queue_is_full");
	setup();
		test_12_for_float_element_into_queue_when_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_13_for_dequeueing_integer_element_from_queue");
	setup();
		test_13_for_dequeueing_integer_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_14_for_dequeueing_float_element_from_queue");
	setup();
		test_14_for_dequeueing_float_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_15_for_dequeueing_float_element_from_queue_when_queue_is_empty");
	setup();
		test_15_for_dequeueing_float_element_from_queue_when_queue_is_empty();
	tearDown();
	testEnded();
	testStarted("test_16_for_enqueueing_new_integer_element_at_the_0_location_after_dequeueing");
	setup();
		test_16_for_enqueueing_new_integer_element_at_the_0_location_after_dequeueing();
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
