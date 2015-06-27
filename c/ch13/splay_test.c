#include "splay.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
	char Array[] = {'A', 'S', 'E', 'R', 'C', 'H', 'I', 'N', 'G'};
	int i;
	SplayTree T;

	T = NULL;
	for (i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i)
		T = Insert(Array[i], T);


	T = NULL;
	for (i = 1; i < 6; ++i)
		T = InsertRotate(i, T);

	PreOrderTraverse(T);
	printf("\n");

	InOrderTraverse(T);
	printf("\n");

	PostOrderTraverse(T);
	printf("\n");

	T = InsertRotate(3, T);

	PreOrderTraverse(T);
	printf("\n");

	InOrderTraverse(T);
	printf("\n");

	PostOrderTraverse(T);
	printf("\n");

	// T = InsertRotate(2, T);

	// PreOrderTraverse(T);
	// printf("\n");

	// InOrderTraverse(T);
	// printf("\n");

	// PostOrderTraverse(T);
	// printf("\n");

	return 0;
}