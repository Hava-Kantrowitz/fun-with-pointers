/*
 * tests.c
 *
 *  Created on: Jan 26, 2019
 *      Author: student
 */

#include "tests.h"
#include "production.h"

bool tests(void)
{
	bool ans = true;
	bool ok1 = testShellSort();
	ans = ok1;
	return ans;
}

bool testShellSort(void)
{
	bool ans = true;//passed every test it has had so far (0 of them)
	bool done = false;
	//test case: 1,2,3,4,5
	//correct answer: 1,2,3,4,5
	//shell sort sorts in place, so we test the array a
	int a[]={1,2,3,4,5};
	int b[]={1,2,3,4,5};
	shell_sort(a,5);
	printf("The sorted array is:   ");

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for(int i = 0; !done && (i<5); i++)
	{
		if(a[i]!=b[i])
		{//found a mismatch between sorted and correct
			ans = false;
			done = true;
			puts("Shell sort did not pass the first test.");
		}
	}

	//test case: 5 4 3 2 1
	//correct answer: 1,2,3,4,5
	int a2[]={5,4,3,2,1};

	shell_sort(a2,5);
	printf("The sorted array is:   ");

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a2[i]);
	}
	for(int i = 0; !done && (i<5); i++)
	{
		if(a2[i]!=b[i])
		{//found a mismatch between sorted and correct
			ans = false;
			done = true;
			puts("Shell sort did not pass the second test.");
		}
	}
	return ans;
}

