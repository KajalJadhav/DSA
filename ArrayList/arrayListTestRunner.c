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

	testStarted("test_inserts_element");
	setup();
		test_inserts_element();
	tearDown();
	testEnded();
	testStarted("test_inserts_multiple_elements");
	setup();
		test_inserts_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_interns_grows_beyond_capacity");
	setup();
		test_interns_grows_beyond_capacity();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_at_index_beyond_length");
	setup();
		test_should_not_insert_at_index_beyond_length();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_at_negative_index");
	setup();
		test_should_not_insert_at_negative_index();
	tearDown();
	testEnded();
	testStarted("test_inserts_at_middle_should_shift_the_elements");
	setup();
		test_inserts_at_middle_should_shift_the_elements();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_when_list_is_null");
	setup();
		test_should_not_insert_when_list_is_null();
	tearDown();
	testEnded();
	testStarted("test_adds_element_when_list_is_empty");
	setup();
		test_adds_element_when_list_is_empty();
	tearDown();
	testEnded();
	testStarted("test_adds_multiple_elements");
	setup();
		test_adds_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_adding_element_list_grows_beyond_capacity");
	setup();
		test_adding_element_list_grows_beyond_capacity();
	tearDown();
	testEnded();
	testStarted("test_removes_element_from_list");
	setup();
		test_removes_element_from_list();
	tearDown();
	testEnded();
	testStarted("test_removes_element_from_multiple_elements");
	setup();
		test_removes_element_from_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_does_not_removes_element_when_index_is_negative");
	setup();
		test_does_not_removes_element_when_index_is_negative();
	tearDown();
	testEnded();
	testStarted("test_should_get_index_of_element_searched");
	setup();
		test_should_get_index_of_element_searched();
	tearDown();
	testEnded();
	testStarted("test_should_get_minus_1_if_element_not_found");
	setup();
		test_should_get_minus_1_if_element_not_found();
	tearDown();
	testEnded();
	testStarted("test_iterator_hasNext_should_give_TRUE_when_element_is_present");
	setup();
		test_iterator_hasNext_should_give_TRUE_when_element_is_present();
	tearDown();
	testEnded();
	testStarted("test_iterator_hasNext_should_give_FALSE_when_element_is_not_present");
	setup();
		test_iterator_hasNext_should_give_FALSE_when_element_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_iterator_next_should_give_next_element");
	setup();
		test_iterator_next_should_give_next_element();
	tearDown();
	testEnded();
	testStarted("test_iterator_next_should_give_NULL_in_empty_ArrayList");
	setup();
		test_iterator_next_should_give_NULL_in_empty_ArrayList();
	tearDown();
	testEnded();
	testStarted("test_deletes_single_element_from_list");
	setup();
		test_deletes_single_element_from_list();
	tearDown();
	testEnded();
	testStarted("test_deletes_and_shifts_elements_left");
	setup();
		test_deletes_and_shifts_elements_left();
	tearDown();
	testEnded();
	testStarted("test_adds_element_to_end_of_list");
	setup();
		test_adds_element_to_end_of_list();
	tearDown();
	testEnded();
	testStarted("test_adds_multiple_data_to_end_of_list");
	setup();
		test_adds_multiple_data_to_end_of_list();
	tearDown();
	testEnded();
	testStarted("test_prints_data_of_each_element");
	setup();
		test_prints_data_of_each_element();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
