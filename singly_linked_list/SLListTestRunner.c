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

	testStarted("test_1_gives_a_singly_linked_list_with_head_NULL");
	setup();
		test_1_gives_a_singly_linked_list_with_head_NULL();
	tearDown();
	testEnded();
	testStarted("test_2_inserts_element_as_head_of_linked_list");
	setup();
		test_2_inserts_element_as_head_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_3_inserts_element_at_the_end_of_linked_list");
	setup();
		test_3_inserts_element_at_the_end_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_4_inserts_element_at_middle_of_linked_list");
	setup();
		test_4_inserts_element_at_middle_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_5_inserts_multiple_elements_at_head_of_linked_list");
	setup();
		test_5_inserts_multiple_elements_at_head_of_linked_list();
	tearDown();
	testEnded();
	testStarted("test_6_inserts_double_element_in_the_linked_list");
	setup();
		test_6_inserts_double_element_in_the_linked_list();
	tearDown();
	testEnded();
	testStarted("test_7_inserts_character_elements_in_the_linked_list");
	setup();
		test_7_inserts_character_elements_in_the_linked_list();
	tearDown();
	testEnded();
	testStarted("test_8_inserts_the_string_elements_in_the_linked_list");
	setup();
		test_8_inserts_the_string_elements_in_the_linked_list();
	tearDown();
	testEnded();
	testStarted("test_9_inserts_the_structures_in_the_linked_list");
	setup();
		test_9_inserts_the_structures_in_the_linked_list();
	tearDown();
	testEnded();
	testStarted("test_10_deletes_element_from_list_which_has_only_one_element");
	setup();
		test_10_deletes_element_from_list_which_has_only_one_element();
	tearDown();
	testEnded();
	testStarted("test_11_deletes_first_element_from_list_when_more_than_one_elements_are_there");
	setup();
		test_11_deletes_first_element_from_list_when_more_than_one_elements_are_there();
	tearDown();
	testEnded();
	testStarted("test_12_deletes_last_element_from_linked_list");
	setup();
		test_12_deletes_last_element_from_linked_list();
	tearDown();
	testEnded();
	testStarted("test_13_deletes_element_in_between_of_linked_list");
	setup();
		test_13_deletes_element_in_between_of_linked_list();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
