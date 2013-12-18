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

	testStarted("test_1_enqueues_an_integer_element_in_empty_queue_and_gives_back_that_element_when_dequeued");
	setup();
		test_1_enqueues_an_integer_element_in_empty_queue_and_gives_back_that_element_when_dequeued();
	tearDown();
	testEnded();
	testStarted("test_2_enqueues_the_integer_elements_in_queue_and_dequeue_the_top_element");
	setup();
		test_2_enqueues_the_integer_elements_in_queue_and_dequeue_the_top_element();
	tearDown();
	testEnded();
	testStarted("test_3_enqueues_an_float_element_in_empty_queue_and_gives_back_that_element_when_dequeued");
	setup();
		test_3_enqueues_an_float_element_in_empty_queue_and_gives_back_that_element_when_dequeued();
	tearDown();
	testEnded();
	testStarted("test_4_enqueues_the_float_elements_in_queue_and_dequeue_the_element_with_lowest_priority");
	setup();
		test_4_enqueues_the_float_elements_in_queue_and_dequeue_the_element_with_lowest_priority();
	tearDown();
	testEnded();
	testStarted("test_5_enqueues_an_double_element_in_empty_queue_and_gives_back_that_element_when_dequeued");
	setup();
		test_5_enqueues_an_double_element_in_empty_queue_and_gives_back_that_element_when_dequeued();
	tearDown();
	testEnded();
	testStarted("test_6_enqueues_the_double_elements_in_queue_and_dequeue_the_element_with_lowest_priority");
	setup();
		test_6_enqueues_the_double_elements_in_queue_and_dequeue_the_element_with_lowest_priority();
	tearDown();
	testEnded();
	testStarted("test_7_enqueues_an_character_element_in_empty_queue_and_gives_back_that_element_when_dequeued");
	setup();
		test_7_enqueues_an_character_element_in_empty_queue_and_gives_back_that_element_when_dequeued();
	tearDown();
	testEnded();
	testStarted("test_8_enqueues_the_characters_elements_in_queue_and_dequeue_the_top_element");
	setup();
		test_8_enqueues_the_characters_elements_in_queue_and_dequeue_the_top_element();
	tearDown();
	testEnded();
	testStarted("test_9_enqueues_an_String_element_in_empty_queue_and_gives_back_that_element_when_dequeued");
	setup();
		test_9_enqueues_an_String_element_in_empty_queue_and_gives_back_that_element_when_dequeued();
	tearDown();
	testEnded();
	testStarted("test_10_enqueues_the_String_elements_in_queue_and_dequeue_the_top_element");
	setup();
		test_10_enqueues_the_String_elements_in_queue_and_dequeue_the_top_element();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
