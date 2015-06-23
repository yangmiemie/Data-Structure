#include <stdio.h>

#define BUFSIZE 100
#define RANGE 30

void DeleteElement(int i, int* Array, int Size)
{
	int j;
	for (j = i; j < Size - 1; ++j)
	{
		Array[j] = Array[j+1];
	}
}

int RemoveDupElement(int *Array, int Size)
{
	int i, j;

	for (i = 0; i < Size; ++i)
	{
		for (j = i + 1; j < Size;)
		{
			if (Array[i] == Array[j])
			{
				DeleteElement(j, Array, Size);
				--Size;
			}
			else
			{
				++j;
			}
		}
	}

	return Size;
}

void Swap(int* Array, int i, int j)
{
	int Temp;

	Temp = Array[i];
	Array[i] = Array[j];
	Array[j] = Temp;
}

int RemoveSortedDupElement(int *Array, int Size)
{
	int i;

	for (i = 0; i < Size; ++i)
	{
		while (1)
		{
			if ((i < Size) && (Array[i] == Array[i+1]))
			{
				DeleteElement(i + 1, Array, Size);
				--Size;
			}
			else
				break;
		}
	}

	return Size;
}

void QuickSort(int* Array, int Start, int End)
{
	int i, j, Pivot;

	if (Start >= End)
		return;

	Pivot = Array[Start];
	i = Start + 1;
	j = End;	
	
	while(1)
	{
		while(i <= j && Array[i] <= Pivot) ++i;
		while(i <= j && Array[j] >= Pivot) --j;

		if (i > j)
			break;

		Swap(Array, i, j);
		++i;
		--j;
	}

	Swap(Array, Start, j);

	QuickSort(Array, Start, j - 1);
	QuickSort(Array, j + 1, End);
}

int main(int argc, char const *argv[])
{
	int Array[BUFSIZE], Array2[BUFSIZE];
	int i, j;
	int Len;

	for (i = 0 ; i < BUFSIZE; ++i )
	{
			Array[i] = rand() % RANGE;
			Array2[i] = Array[i];
	}

	// for (i = 0; i < BUFSIZE; ++i)
	// {
	// 	printf("%d ", Array[i]);
	// }
	// printf("\n");

	Len = RemoveDupElement(Array, BUFSIZE);

	// for (i = 0; i < Len; ++i)
	// {
	// 	printf("%d ", Array[i]);
	// }
	// printf("\n");

	int N = BUFSIZE;

	// for (i = 0; i < N; ++i)
	// {
	// 	Array2[i] = i;
	// }

	QuickSort(Array2, 0, N - 1);
	for (i = 0; i < N; ++i)
	{
		printf("%d ", Array2[i]);
	}
	printf("\n");

	// Len = RemoveSortedDupElement(Array2, BUFSIZE);

	// for (i = 0; i < Len; ++i)
	// {
	// 	printf("%d ", Array2[i]);
	// }
	// printf("\n");


	return 0;
}