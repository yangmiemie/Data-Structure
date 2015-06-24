#include "sort.h"
#include <stdio.h>

#define BUFSIZE 50

void PrintArray(ElementType A[], int N)
{
	int i;
	for (i = 0; i < N; ++i)
	{
		printf("%d ", A[i]);
	}

	printf("\n");
}

int main(int argc, char const *argv[])
{
	int Array[BUFSIZE] = {0};
	int i;

	for (i = 0; i < BUFSIZE; ++i)
		Array[i] = rand() % (BUFSIZE * 10);
	
	PrintArray(Array, BUFSIZE);

	MergeSort(Array, BUFSIZE);
	PrintArray(Array, BUFSIZE);

	for (i = 0; i < BUFSIZE; ++i)
		Array[i] = BUFSIZE - i;
	
	PrintArray(Array, BUFSIZE);

	// QuickSort(Array, BUFSIZE);
	// PrintArray(Array, BUFSIZE);

	MergeSort(Array, BUFSIZE);
	PrintArray(Array, BUFSIZE);
	return 0;
}