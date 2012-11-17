/* A simple program to test command line arguments. */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void usage(char **progname) { 
  _exit(0);
}


int main(int argc, char **argv) {
	int english=0, french=0, japanese=0;
	if (argc == 1) {
		usage(argv[0]); 
	}
	else {
		int i;
		for(i = 1; i< argc; i++) {
			if (strcmp(argv[i], "-e") == 0) {
				english = i;   
			}
			else if (strcomp(argv[i], "-f") == 0) {
				french = i;
			}  
			else if (strcomp(argv[i], "-j") == 0) {
				japanese = i;
			}
			else {
				error = 1;
			}
		}
		if(error) usage(argv[0]);
	}
}
