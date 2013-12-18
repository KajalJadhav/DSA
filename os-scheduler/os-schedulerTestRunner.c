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
	testStarted("test_2_adds_front_process");
	setup();
		test_2_adds_front_process();
	tearDown();
	testEnded();
	testStarted("test_3_adds_process_that_have_high_priority_rather_than_first");
	setup();
		test_3_adds_process_that_have_high_priority_rather_than_first();
	tearDown();
	testEnded();
	testStarted("test_4_adds_process_with_priority_in_between_process_queue");
	setup();
		test_4_adds_process_with_priority_in_between_process_queue();
	tearDown();
	testEnded();
	testStarted("test_5_adds_process_with_very_low_priority");
	setup();
		test_5_adds_process_with_very_low_priority();
	tearDown();
	testEnded();
	testStarted("test_6_removes_first_which_is_only_process");
	setup();
		test_6_removes_first_which_is_only_process();
	tearDown();
	testEnded();
	testStarted("test_7_removes_processes_in_middle");
	setup();
		test_7_removes_processes_in_middle();
	tearDown();
	testEnded();
	testStarted("test_8_removes_last_process");
	setup();
		test_8_removes_last_process();
	tearDown();
	testEnded();
	testStarted("test_9_removes_first_process_in_many");
	setup();
		test_9_removes_first_process_in_many();
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
