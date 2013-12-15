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

	testStarted("test_1_searches_8_in_integer_array");
	setup();
		test_1_searches_8_in_integer_array();
	tearDown();
	testEnded();
	testStarted("test_2_searches_9_in_integer_array_which_is_not_present");
	setup();
		test_2_searches_9_in_integer_array_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_3_searches_1st_element_in_integer_array");
	setup();
		test_3_searches_1st_element_in_integer_array();
	tearDown();
	testEnded();
	testStarted("test_4_searches_middle_element_in_integer_array");
	setup();
		test_4_searches_middle_element_in_integer_array();
	tearDown();
	testEnded();
	testStarted("test_5_searches_last_element_in_integer_array");
	setup();
		test_5_searches_last_element_in_integer_array();
	tearDown();
	testEnded();
	testStarted("test_6_searches_element_in_float_array");
	setup();
		test_6_searches_element_in_float_array();
	tearDown();
	testEnded();
	testStarted("test_7_searches_element_in_float_array_which_is_not_present");
	setup();
		test_7_searches_element_in_float_array_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_8_searches_element_in_double_array");
	setup();
		test_8_searches_element_in_double_array();
	tearDown();
	testEnded();
	testStarted("test_9_searches_a_in_character_array");
	setup();
		test_9_searches_a_in_character_array();
	tearDown();
	testEnded();
	testStarted("test_10_searches_m_in_character_array_which_is_not_present");
	setup();
		test_10_searches_m_in_character_array_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_11_searches_first_element_in_character_array_with_similar_characters");
	setup();
		test_11_searches_first_element_in_character_array_with_similar_characters();
	tearDown();
	testEnded();
	testStarted("test_12_searches_last_element_in_character_array_with_similar_and_diiferent_charaters");
	setup();
		test_12_searches_last_element_in_character_array_with_similar_and_diiferent_charaters();
	tearDown();
	testEnded();
	testStarted("test_13_searches_kajal_in_String_array");
	setup();
		test_13_searches_kajal_in_String_array();
	tearDown();
	testEnded();
	testStarted("test_14_searches_shital_in_String_array_which_is_not_present");
	setup();
		test_14_searches_shital_in_String_array_which_is_not_present();
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
