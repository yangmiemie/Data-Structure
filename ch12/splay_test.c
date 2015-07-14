#include "splay.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int Array[] = {12, 5, 25, 20, 30, 24, 15, 13, 18, 16};
	int i, Len;
	SplayTree T;
	Position P;

	Len = sizeof(Array) / sizeof(Array[0]);
	T = NULL;
	for (i = 0; i < Len; ++i)
		T = BSTInsert(Array[i], T);

	PreOrderTraverse(T);
	printf("\n");

	InOrderTraverse(T);
	printf("\n");
	
	PostOrderTraverse(T);
	printf("\n");

	P = Insert(19, T);

	PreOrderTraverse(P);
	printf("\n");

	InOrderTraverse(P);
	printf("\n");
	
	PostOrderTraverse(P);
	printf("\n");
 	return 0;
}