all:	string

string:	string_functions.c
	gcc string_functions.c -o string
clean:
	rm string
