#include "skip_list.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char Array[] = {'A', 'S', 'E', 'R', 'C', 'H', 'I', 'N', 'G', 'X', 'M', 'P', 'L'};
	int i, Len;
	SkipList SL;

	SL = SLInit();
	Len = sizeof(Array) / sizeof(Array[0]);

	for (i = 0; i < Len; ++i)
		Insert(SL, Array[i]);
	

	PrintLink(SL);
	return 0;
}