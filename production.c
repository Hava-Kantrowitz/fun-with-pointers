/*
 * production.c
 *
 *  Created on: Jan 26, 2019
 *      Author: student
 */

#include "tests.h"
#include "production.h"


void shell_sort(int a[], int size)
{
	int i, j;
	int h = 1;
	do {
		h = h * 3 + 1;
	} while (h <= size);
	do {
		h /= 3;
		for (i = h; i < size; i++)
		{
			int v = a[i];
			for (j = i; j >= h && a[j - h] > v; j -= h)
				a[j] = a[j - h];
			if (i != j)
				a[j] = v;

		}
	} while (h != 1);
}
/**
 * going to read a list of integers from the command line
 */
bool production(int argc, char* argv[])
{
	bool result = 0;
	int* a = NULL;
	char* p;

	a = (int*)malloc((argc - 1) * sizeof(int));
	for (int i = 0; i < argc - 1; i++)
	{
		long aL = strtol(argv[i+1], &p, 10);
		a[i] = (int)aL;
	}
	printf("The unsorted array is: ");
	for(int i = 0; i<argc-1; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	shell_sort(a, argc);
	printf("The sorted array is:   ");

	for (int i = 0; i < argc - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	free(a);
	return result;
}
