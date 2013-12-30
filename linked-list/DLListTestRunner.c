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

	testStarted("test_gives_an_Doubly_link_list_with_head_NULL");
	setup();
		test_gives_an_Doubly_link_list_with_head_NULL();
	tearDown();
	testEnded();
	testStarted("test_creates_node");
	setup();
		test_creates_node();
	tearDown();
	testEnded();
	testStarted("test_inserts_an_element_at_head_of_link_list");
	setup();
		test_inserts_an_element_at_head_of_link_list();
	tearDown();
	testEnded();
	testStarted("test_inserts_an_element_at_the_end_of_linkList");
	setup();
		test_inserts_an_element_at_the_end_of_linkList();
	tearDown();
	testEnded();
	testStarted("test_inserts_element_in_middle_of_link_List");
	setup();
		test_inserts_element_in_middle_of_link_List();
	tearDown();
	testEnded();
	testStarted("test_inserts_multiple_element_as_the_head_of_link_list");
	setup();
		test_inserts_multiple_element_as_the_head_of_link_list();
	tearDown();
	testEnded();
	testStarted("test_inserts_the_doubles_in_the_linklist");
	setup();
		test_inserts_the_doubles_in_the_linklist();
	tearDown();
	testEnded();
	testStarted("test_inserts_the_characters_in_the_link_list");
	setup();
		test_inserts_the_characters_in_the_link_list();
	tearDown();
	testEnded();
	testStarted("test_inserts_the_strings_in_the_link_list");
	setup();
		test_inserts_the_strings_in_the_link_list();
	tearDown();
	testEnded();
	testStarted("test_inserts_the_structures_in_the_link_list");
	setup();
		test_inserts_the_structures_in_the_link_list();
	tearDown();
	testEnded();
	testStarted("test_deletes_element_in_list_which_has_one_element");
	setup();
		test_deletes_element_in_list_which_has_one_element();
	tearDown();
	testEnded();
	testStarted("test_deletes_first_element_in_list_when_more_than_one_elements_are_there");
	setup();
		test_deletes_first_element_in_list_when_more_than_one_elements_are_there();
	tearDown();
	testEnded();
	testStarted("test_deletes_last_element_in_the_link_List");
	setup();
		test_deletes_last_element_in_the_link_List();
	tearDown();
	testEnded();
	testStarted("test_deletes_element_in_between_of_link_list");
	setup();
		test_deletes_element_in_between_of_link_list();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
