#include <stdio.h>
#include "braces.c"
int main(int argc, char *argv[])
{
	char* input = argv[1];
	if(braceMatch(input))
		printf("All braces are maching");
	else
		printf("Not matching");
	return 0;
}