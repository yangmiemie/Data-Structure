#include <stdio.h>
#include <stdlib.h>

#define ElementType char

void Shuffle(ElementType A[], int Left, int Right)
{
	int i, j, t, Middle;
	ElementType *Aux;

	Middle = (Left + Right) / 2 + 1;
	Aux = malloc(sizeof(ElementType) * (Right - Left + 1));

	for (i = Left, j = 0, t = Middle; i < Middle; i++, j += 2)
	{
		Aux[j] = A[i];
		Aux[j+1] = A[t++];
	}

	for (i = Left; i <= Right; ++i)
		A[i] = Aux[i - Left];

	free(Aux);
}

void Unshuffle(ElementType A[], int Left, int Right)
{
	int i, j, t, Middle;
	ElementType *Aux;

	Aux = malloc(sizeof(ElementType) * (Right - Left + 1));
	Middle = (Right + Left) / 2 + 1;

	for (i = Left, t = 0; i <= Right; i += 2, ++t)
	{
		Aux[t] = A[i];
		Aux[Middle + t] = A[i+1];
	}

	for (i = Left; i <= Right; ++i)
		A[i] = Aux[i - Left];

	free(Aux);
}

void PrintArray(ElementType A[], int N)
{
	int i;
	for (i = 0; i < N; ++i)
		printf("%c ", A[i]);

	printf("\n");
}

void CompExch(ElementType A[], int i, int j)
{
	ElementType Temp;

	if (A[i] > A[j])
	{
		Temp = A[i];
		A[i] = A[j];
		A[j] = Temp;
	}
}

void MergeTD(ElementType A[], int Left, int Right)
{
	int i, Middle;

	if (Right == Left + 1)
		CompExch(A, Left, Right);

	if (Right < Left + 2)
		return;

	Middle = (Left + Right) / 2;
	Unshuffle(A, Left, Right);
	MergeTD(A, Left, Middle);
	MergeTD(A, Middle + 1, Right);
	Shuffle(A, Left, Right);

	for (i = Left + 1; i < Right; i += 2)
		CompExch(A, i, i + 1);

}

int main(int argc, char const *argv[])
{
	// char Array[] = {'A', 'G', 'I', 'N', 'O', 'R', 'S', 'T', 'A', 'B', 'E', 'E', 'L', 'M', 'P', 'X', 'Z'};
	char Array[] = {'S', 'T', 'B', 'A'};
	int i, Len;

	Len = sizeof(Array) / sizeof(Array[0]);
	PrintArray(Array, Len);

	Shuffle(Array, 0, Len - 1);
	PrintArray(Array, Len);

	Unshuffle(Array, 0, Len - 1);
	PrintArray(Array, Len);

	MergeTD(Array, 0, Len - 1);
	PrintArray(Array, Len);

	return 0;
}