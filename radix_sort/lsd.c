#include <stdio.h>
#include <stdlib.h>

#define ElementType char*
#define R 26

int BytesWord = 3;

int Digit(ElementType S, int w)
{
  return S[w] - 'a';
}

void RadixLSD(ElementType A[], int Left, int Right)
{
  int i, j, w, Count[R + 1];
  ElementType *Aux;

  Aux = malloc(sizeof(ElementType) * (Right - Left + 1));

  for (w = BytesWord - 1; w >= 0 ; --w)
  {
    for (j = 0; j < R + 1; ++j)
      Count[j] = 0;

    // The number of char is store in Count with index of char + 1
    for (i = Left; i <= Right; ++i)
      Count[Digit(A[i], w) + 1]++;

    // The char in Count with the index of N are stored in A with the index of Count[N-1]
    // If the char X with index of XX in Count, that is XX = digit(x) + 1
    // Then the index of X in sorted A are XX -1 , which is digit(x) 
    for (j = 1; j < R; ++j)
      Count[j] += Count[j-1];

    // The index of X(A[i]) in sorted A is Count[Digit(X)], if more than one X, then the index ++.
    for (i = Left; i <= Right; ++i)
    {
      j = Count[Digit(A[i], w)]++;
      Aux[j] = A[i];
    }

    for (i = Left; i <= Right; ++i)
      A[i] = Aux[i - Left];
  }

  free(Aux);
}

int main(int argc, char const *argv[])
{
  int i, j, N, Len;
  N = 10000;

  ElementType A[N];

  Len = 3;
  for (i = 0; i < N; ++i)
  {
    A[i] = malloc(sizeof(char) * Len);
    for (j = 0; j < Len; ++j)
      A[i][j] = rand() % 26 + 'a';
  }

  RadixLSD(A, 0, N - 1);

  for (i = 0; i < N; ++i)
  {
    printf("%s ", A[i]);
    free(A[i]);
  }

  printf("\n");
  return 0;
}