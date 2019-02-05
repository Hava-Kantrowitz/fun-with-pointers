/*
 * mystring.c
 *
 *  Created on: Feb 4, 2019
 *      Author: Hava Kantrowitz
 */
#include <stdlib.h>
#include "mystring.h"

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}
/**
 * Calculate the length of the string
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/** Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strcpy(newstr, s);
	}
	return newstr;
}

/**
 * Copies the string from one location to another
 * @param dest: pointer to the first character in the array the string will be copied to
 * @param src: pointer to the first character in the character array (string) that is being copied
 * @return pointer to the first array element in the destination
 */
char* mystrcpy(char* dest, char* src) {

	//Keep incrementing pointer until we hit null terminator
	char* firstDest = dest;
	while(*src != '\0'){
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return firstDest;
}

/**
 * Copies a specified amount of characters the string from one location to another
 * @param dest: pointer to the first character in the array the string will be copied to
 * @param src: pointer to the first character in the character array (string) that is being copied
 * @param n: number of characters to be copied
 * @return pointer to the first array element in the destination
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	return dest;
}
/**
 * Copies a specified amount of characters in a  string into the end of another string
 * @param dest: pointer to the first character in the array the string will be copied to
 * @param src: pointer to the first character in the character array (string) that is being copied
 * @param n: number of characters to be copied
 * @return pointer to the first array element in the destination
 */
char* mystrncat(char* dest, char* src, size_t n) {
	return dest;
}
