/*
 * tests.c
 *
 *  Created on: Feb 4, 2019
 *      Author: Hava Kantrowitz
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystring.h"

/**
 * determines whether tests of functions work properly
 * @return true if all tests pass, false otherwise
 */
bool tests(void)
{
	bool ok = false;
	bool ok1 = testMystrlen1();

	if (ok1) {
		puts("mystrlen1() passed.");
	}

	bool ok2 = testMystrlen2();
	if (ok2) {
		puts("mystrlen2() passed.");
	}

	bool ok3 = testMystrdup();
	if (ok3) {
		puts("mystrdup() passed.");
	}

	bool ok4 = testMystrncpy();
	if (ok4) {
		puts("mystrncpy() passed.");
	}

	bool ok5 = testMystrcpy();
	if (ok5) {
		puts("mystrcpy() passed.");
	}

	bool ok6 = testMystrncat();
	if (ok6) {
		puts("mystrncat() passed.");
	}


	bool ok7 = testMystrcat();
	if (ok7) {
		puts("mystrcat() passed.");
	}


	bool ok8 = testMystrndup();
	if (ok8) {
		puts("mystrndup() passed.");
	}

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8; // Did all tests pass?
	return ok;
}

/** Tests the mystrlen1() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen1(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen1(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen1(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}


/** Tests the mystrlen2() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen2(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen2(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen2(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
	return ok;
}

/** Test mystrdup() function by comparing it to the standard strdup().
 * @return true if it passes all tests.
 */
bool testMystrdup() {
	bool ok1 = false;

	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strdup(s1); // Copy it using standard function
	char* s3 = mystrdup(s1); // Copy it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}

	char* s4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok1, on stack:   %p\n", &ok1);
	printf("Address of original string, on stack:        %p\n", s1);
	printf("Address of first duplicate string, on heap:  %p\n", s2);
	printf("Address of second duplicate string, on heap: %p\n", s3);
	printf("Address of other string, on heap?:           %p\n", s4);

	bool ok = ok1;
	return ok;
}

/*
 * Test mystrcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpy() {
	bool ok1 = false;
	bool ok2 = false;

	char s1[] = "Some sample string."; // String we will copy.
	char s2[30]; // Empty string we will copy into

	char* s3 = mystrcpy(s2, s1); // Copy the string
	if (strcmp(s1, s2) == 0) { // Does original equal copy?
		ok1 = true; // Yes!
	}

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	bool ok = ok1 && ok2;
	return ok;
}

/*
 * Test mystrncpy() function.
 * @return true if pass, false if fail.
 */

bool testMystrncpy() {

	bool ok = false;

	//n is shorter than src
	bool ok1 = false;
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a = strncpy(s1a, s2a, 2); // The result

	//printf("In testMystrncpy(): s3a = /%s/\n", s3a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b = mystrncpy(s1b, s2b, 2); // The result

	if (strcmp(s3a, s3b) == 0) {
		ok1 = true;
		//printf("1 succeeded.\n");
	}


	//n is longer than src
	bool ok2 = false;
	char s1a2[] = "012345678901234567890123456789"; // A long string
	char s2a2[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a2 = strncpy(s1a2, s2a2, 12); // The result

	//printf("In testMystrncpy(): s3a = /%s/\n", s3a);

	char s1b2[] = "012345678901234567890123456789"; // A long string
	char s2b2[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b2 = mystrncpy(s1b2, s2b2, 12); // The result

	if (strcmp(s3a2, s3b2) == 0) {
		ok2 = true;
		//printf("2 succeeded.\n");
	}

	//n is equal to src
	bool ok3 = false;
	char s1a3[] = "012345678901234567890123456789"; // A long string
	char s2a3[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a3 = strncpy(s1a3, s2a3, 6); // The result

	//printf("In testMystrncpy(): s3a = /%s/\n", s3a);

	char s1b3[] = "012345678901234567890123456789"; // A long string
	char s2b3[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b3 = mystrncpy(s1b3, s2b3, 6); // The result

	if (strcmp(s3a3, s3b3) == 0) {
		ok3 = true;
		//printf("3 succeeded.\n");
	}

	ok = ok1 && ok2 && ok3;
	return ok;
}

/*
 * Test mystrncat() function by comparing it to standard strncat() function.
 * @return true if pass, false if fail.
 */
bool testMystrncat() {
	bool ok = false;

	//n is less than src
	bool ok1 = false;
	bool ok2 = false;

	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1a, s2a);
	char* s4a =	strncat(s1a, s2a, 2); // The result

	//printf("In testMystrncat(): s1a = /%s/\n", s1a);
	//printf("In testMystrncat(): s4a = /%s/\n", s4a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1b, s2b);
	char* s4b = mystrncat(s1b, s2b, 2); // The result

	//printf("Long1: %s\n", s1a);
	//printf("Long2: %s\n", s1b);

	//printf("Short1: %s\n", s2a);
	//printf("Short2: %s\n", s2b);

	//printf("copy1: %s\n", s3a);
	//printf("copy2: %s\n", s3b);

	//printf("Concat1: %s\n", s4a);
	//printf("Concat2: %s\n", s4b);

	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}

	//printf("Ok1: %i\n", ok1);
	//printf("Ok2: %i\n", ok2);

	//n is greater than src
	bool ok3 = false;
	bool ok4 = false;

	char s1a1[] = "012345678901234567890123456789"; // A long string
	char s2a1[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1a1, s2a1);
	char* s4a1 =	strncat(s1a1, s2a1, 10); // The result

	char s1b1[] = "012345678901234567890123456789"; // A long string
	char s2b1[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1b1, s2b1);
	char* s4b1 = mystrncat(s1b1, s2b1, 10); // The result

	if (strcmp(s1a1, s1b1) == 0) {
		ok3 = true;
	}

	if (strcmp(s4a1, s4b1) == 0) {
		ok4 = true;
	}

	//n is equal to src
	bool ok5 = false;
	bool ok6 = false;

	char s1a2[] = "012345678901234567890123456789"; // A long string
	char s2a2[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1a2, s2a2);
	char* s4a2 =	strncat(s1a2, s2a2, 6); // The result

	char s1b2[] = "012345678901234567890123456789"; // A long string
	char s2b2[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1b2, s2b2);
	char* s4b2 = mystrncat(s1b2, s2b2, 6); // The result

	if (strcmp(s1a2, s1b2) == 0) {
		ok5 = true;
	}

	if (strcmp(s4a2, s4b2) == 0) {
		ok6 = true;
	}

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6;
	return ok;
}

/*
 * Test mystrcat() function but comparing it to standard strcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcat(){
	bool ok1 = false;
	bool ok2 = false;

	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1a, s2a);
	char* s4a =	strcat(s1a, s2a); // The result

	//printf("In testMystrncat(): s1a = /%s/\n", s1a);
	//printf("In testMystrncat(): s4a = /%s/\n", s4a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1b, s2b);
	char* s4b = mystrcat(s1b, s2b); // The result

	//printf("Concat1: %s\n", s4a);
	//printf("Concat2: %s\n", s4b);

	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}


	return ok1 && ok2;
}

/** Test mystrndup() function by comparing it to the standard strndup().
 * @return true if it passes all tests.
 */
bool testMystrndup() {

	bool ok = false;

	//n shorter than s
	bool ok1 = false;

	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strndup(s1, 4); // Copy 4 characters in it using standard function
	char* s3 = mystrndup(s1, 4); // Copy 4 characters in it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}

	//n is longer than s
	bool ok2 = false;

	char s1a[] = "Sample."; // String we will duplicate.
	char* s2a = strndup(s1a, 9); // Copy 4 characters in it using standard function
	char* s3a = mystrndup(s1a, 9); // Copy 4 characters in it using my function

	if (strcmp(s2a, s3a) == 0) { // Same result!
		ok2 = true;
	}

	//n is equal to s
	bool ok3 = false;

	char s1b[] = "Sample."; // String we will duplicate.
	char* s2b = strndup(s1b, 7); // Copy 4 characters in it using standard function
	char* s3b = mystrndup(s1b, 7); // Copy 4 characters in it using my function

	if (strcmp(s2b, s3b) == 0) { // Same result!
		ok3 = true;
	}

	ok = ok1 && ok2 && ok3;
	return ok;
}
