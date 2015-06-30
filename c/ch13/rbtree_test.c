#include "rb_tree.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
	char Array[] = {'A', 'E', 'S', 'R', 'C', 'H', 'I', 'N', 'G', 'X'};
	// char Array[] = {'A', 'S', 'E', 'R', 'C', 'H', 'I', 'N', 'G', 'X'};
	int i, Len;

	RBTree T;

	T = NULL;
	Len = 3;
	// Len = sizeof(Array) / sizeof(Array[0]);
	for (i = 0; i < Len; ++i)
		T = Insert(Array[i], T);

	PreOrderTraverse(T);
	printf("\n");

	InOrderTraverse(T);
	printf("\n");

	PostOrderTraverse(T);
	printf("\n");
	return 0;
}