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

	testStarted("test_1_returns_false_if_string_not_matches");
	setup();
		test_1_returns_false_if_string_not_matches();
	tearDown();
	testEnded();
	testStarted("test_2_returns_true_if_string_matches");
	setup();
		test_2_returns_true_if_string_matches();
	tearDown();
	testEnded();
	testStarted("test_3_returns_true_if_whole_string_matches");
	setup();
		test_3_returns_true_if_whole_string_matches();
	tearDown();
	testEnded();
	testStarted("test_4_returns_false_if_string_does_not_match");
	setup();
		test_4_returns_false_if_string_does_not_match();
	tearDown();
	testEnded();
	testStarted("test_5_returns_false_if_string_not_matches");
	setup();
		test_5_returns_false_if_string_not_matches();
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
