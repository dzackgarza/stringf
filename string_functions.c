/* A variety of string functions

	compare(str1, str2): Given two strings, returns:
		A positive number : String one comes *after* string two (alphabetically)
		A negative number : String one comes *before* string two
		Zero		  : The strings are equal

	copy(destination, source): given two strings:
		Copies string from destination to source.

	trim(string): Given a string:
		Removes all except for the final newline from within the string.

	trimall(string): Given a string:
		Removes all whitespace from the entire string.

	test(): Runs test cases for all functions.
*/
// #TODO: Slight memory error in test output? 

#include <stdio.h>

int compare(char *s, char *t) {
	while(s!='\0' && t!='\0') {
		if (*s-*t != 0) return (*s-*t);
		else {s++; t++;}
	}
	return 0;
}

void copy(char *dest, char *src) {
	while(*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
		
}

void trim(char *s) {
	while(*s != '\0') {
		if (*s == '\n' && *(s+1) == '\0') *s = '\0';
		else s++;
	}
}

void trimall(char *s) {
	int space_counter = 0;
	while(*s != '\0') {
		if(*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r')	space_counter++;
		else space_counter = 0;
	s++;
	}

	*(s-space_counter) = '\0';
}

void test() {
	printf("***** Testing *****\n");
	printf("Before test:\n");
	char a[200] = "Waffles";
	char b[200] = "Bacon";
	printf("a = %s\n", a);
	printf("b = %s\n", b);
	printf("\nComparison test: compare(%s,%s) returns: %i\n", a,b, compare(a,b));
	
	char trim1[200] = "String with newline\n";
	char trim2[200] = "String \n with more than one\n newline\n";
	char trim3[200] = "String with \n newline in the middle.";
	char trim4[200] = "String with no newlines.";
	char trim5[200] = "\n"; // Only a newline
	printf("\n\n*** Trim test: Removes trailing newlines. *** \n");
	
	printf("\n1) Original string: %s", trim1);
	trim(trim1);
	printf("\nTrimmed string: %s", trim1);
	
	printf("\n2) Original string: %s", trim2);
	trim(trim2);
	printf("\nTrimmed string: %s", trim2);
	
	printf("\n3) Original string: %s", trim3);
	trim(trim3);
	printf("\nTrimmed string: %s", trim3);
	
	printf("\n4) Original string: %s", trim4);
	trim(trim4);
	printf("\nTrimmed string: %s", trim4);
	
	printf("\n5) Original string: %s", trim5);
	trim(trim5);
	printf("\nTrimmed string: %s", trim5);

	char ta1[200] = "String plus whitespace\n\r\t\n\t\r   ";
	char ta2[200] = "String \t with \n\t  embeded \n whitespace \r\t\n\n\n\n";
	char ta3[200] = "No ending     \r\t    \n \r    whitespace run.";
	char ta4[200] = "Nowhitespaceatall";
	char ta5[200] = "                                "; // Only whitespace
	printf("\n\n*** Trimall test: Removes trailing whitespace. ***\n");	

	printf("\nOriginal string: %s", ta1);
	trimall(ta1);
	printf("\nTrimmed string: %s", ta1);

	printf("\nOriginal string: %s", ta2);
	trimall(ta2);
	printf("\nTrimmed string: %s", ta2);

	printf("\nOriginal string: %s", ta3);
	trimall(ta3);
	printf("\nTrimmed string: %s", ta3);

	printf("\nOriginal string: %s", ta4);
	trimall(ta4);
	printf("\nTrimmed string: %s", ta4);

	printf("\nOriginal string: %s", ta5);
	trimall(ta5);
	printf("\nTrimmed string %s", ta5);

	printf("\n\n*** Copy test *** \n");
	printf("String a before copy: %s\n", a);
	printf("String b before copy: %s\n", b);
	copy(a, b);
	printf("After copy:\n");
	printf("a = %s\n", a);
	printf("b = %s\n", b);

	printf("*** End tests ***\n");
}
int main() {
	test();
	return 0;
}


