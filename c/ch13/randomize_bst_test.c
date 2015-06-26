#include "randomize_bst.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
	char Array[] = {'A', 'S', 'E', 'R', 'C', 'H', 'I', 'N', 'G', 'X', 'M', 'P', 'L'};
	BSTree T;
	Position P;
	int i;

	T = NULL;
	for (i = 0; i < sizeof(Array) / sizeof(Array[0]); ++i)
		T = InsertRandomize(Array[i], T);

	PreOrderTraverse(T);
	printf("\n");


	P = Select(8, T);
	printf("%c\n", Value(P));

	T = Partition(8, T);
	PreOrderTraverse(T);
	printf("\n");

	T = Balance(T);
	PreOrderTraverse(T);
	printf("\n");

	return 0;
}