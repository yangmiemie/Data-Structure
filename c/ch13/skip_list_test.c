#include "skip_list.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char Array[] = {'A', 'S', 'E', 'R', 'C', 'H', 'I', 'N', 'G', 'X', 'M', 'P', 'L'};
	int i, Len;
	SkipList SL;
	Position P;
	char Target = 'H';

	SL = SLInit();
	Len = sizeof(Array) / sizeof(Array[0]);

	for (i = 0; i < Len; ++i)
		Insert(SL, Array[i]);
	
	PrintLink(SL);
	printf("%d\n", Size(SL));

	P = Search(SL, Target);
	printf("P = %c\n", Value(P));

	P = Search(SL, 'G');
	printf("P = %c\n", Value(P));

	P = Search(SL, 'P');
	printf("P = %c\n", Value(P));

	Delete(SL, Target);
	PrintLink(SL);
	printf("%d\n", Size(SL));

	return 0;
}