/*
 ============================================================================
 Name        : LabHW3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "tests.h"
#include "production.h"


int main(int argc, char* argv[]) {
	puts("!!!Hello classmates, we are starting HW3!!!"); /* prints !!!Hello World!!! */
	if(tests())
	{//try production if tests pass

		puts("\nYay, we made it to production.");
		bool ok = production(argc, argv);
		if(ok)
		{
			puts("Production was also a success.");
		}
		else
		{
			puts("Something seems to have gone wrong in production");
		}
	}
	else
	{
		puts("Tests did not pass.");
	}

	    return EXIT_SUCCESS;
}
