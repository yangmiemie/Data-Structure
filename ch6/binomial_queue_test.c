#include "binomial_queue.h"
#include <stdio.h>

void PrintBinTree(BinTree T)
{
	if (T)
	{
		printf("%d ", T -> Element);
		PrintBinTree(T -> LeftChild);
		PrintBinTree(T -> NextSibling);
	}
}

void PrintCollection(BinQueue Q)
{
	int i;

	for (i = 0; i < MaxTrees; ++i)
	{
		if (Q -> TheTrees[i])
		{
			printf("Level %d: ", i);
			PrintBinTree(Q -> TheTrees[i]);
			printf("\n");
		}
	}

}

int main(int argc, char const *argv[])
{
	BinQueue Q, Q1, Q2;
	int i;

	Q = CreateCollection();

	for (i = 1; i < 9; ++i)
	{
		Insert(i, Q);
	}

	PrintCollection(Q);

	DisposeCollection(Q);

	// Q1 = CreateCollection();
	// Q2 = CreateCollection();

	// Insert(12, Q1);
	// Insert(21, Q1);
	// Insert(24, Q1);
	// Insert(65, Q1);

	// Insert(14, Q2);
	// Insert(26, Q2);
	// Insert(16, Q2);
	// Insert(18, Q2);

	// PrintCollection(Q1);
	// PrintCollection(Q2);

 //  Merge(Q1, Q2);

	// PrintCollection(Q1);

	// DisposeCollection(Q1);
	// DisposeCollection(Q2);

	Q1 = CreateCollection();
	Q2 = CreateCollection();

	int Array1[] = {12, 21, 24, 65, 14, 26, 16, 18, 23, 51, 24, 65, 13};
	int Array2[] = {2, 11, 29, 55, 15, 18, 4};

	for (i = 0; i < sizeof(Array1) / sizeof(Array1[0]); ++i)
		Insert(Array1[i], Q1);

	for (i = 0; i < sizeof(Array2) / sizeof(Array2[0]); ++i)
		Insert(Array2[i], Q2);

	printf("Q1\n");
	PrintCollection(Q1);
	printf("Q2\n");
	PrintCollection(Q2);
	Merge(Q1, Q2);

	printf("After Merge: Q1\n");
	PrintCollection(Q1);


	for (i = 0; i < 5; ++i)
	{
		printf("The Min Value is %d, CurrentSize is %d\n", DeleteMin(Q1), Q1 -> CurrentSize);
		PrintCollection(Q1);
	}

	DisposeCollection(Q1);
	DisposeCollection(Q2);

	return 0;
}