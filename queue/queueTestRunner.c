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

	testStarted("test_create_queue_for_integer_value");
	setup();
		test_create_queue_for_integer_value();
	tearDown();
	testEnded();
	testStarted("test_create_queue_for_float_value");
	setup();
		test_create_queue_for_float_value();
	tearDown();
	testEnded();
	testStarted("test_create_queue_for_character_value");
	setup();
		test_create_queue_for_character_value();
	tearDown();
	testEnded();
	testStarted("test_create_queue_for_String_value");
	setup();
		test_create_queue_for_String_value();
	tearDown();
	testEnded();
	testStarted("test_create_queue_for_double_value");
	setup();
		test_create_queue_for_double_value();
	tearDown();
	testEnded();
	testStarted("test_for_enqueing_integer_element_in_queue");
	setup();
		test_for_enqueing_integer_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_for_enqueing_float_element_in_queue");
	setup();
		test_for_enqueing_float_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_for_enqueing_double_element_in_queue");
	setup();
		test_for_enqueing_double_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_for_enqueing_string_element_in_queue");
	setup();
		test_for_enqueing_string_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_for_enqueing_character_element_in_queue");
	setup();
		test_for_enqueing_character_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_for_dequeueing_integer_element_from_queue");
	setup();
		test_for_dequeueing_integer_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_for_dequeueing_float_element_from_queue");
	setup();
		test_for_dequeueing_float_element_from_queue();
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
