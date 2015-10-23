#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "timer.h"

#define ElementType char*
#define N 2000
#define R 26
#define WordBytes 3

int Digit(ElementType A, int W)
{
  return A[W] - 'a';
}

void RadixLSD(ElementType A[], int Left, int Right)
{
  ElementType *Aux;
  int Count[R+1];
  int i, j, W;

  Aux = malloc(sizeof(ElementType) * (Right - Left + 1));
  W = WordBytes;

  for (j = W - 1; j >= 0; --j)
  {
    for (i = 0; i < R + 1; ++i)
      Count[i] = 0;

    for (i = Left; i <= Right; ++i)
      Count[Digit(A[i], j) + 1]++;

    for (i = 1; i < R; ++i)
      Count[i] += Count[i-1];

    for (i = Left; i <= Right; ++i)
      Aux[Count[Digit(A[i], j)]++] = A[i];

    for (i = Left; i <= Right; ++i)
      A[i] = Aux[i - Left];   
  }

  free(Aux);
}

void RMSD(ElementType A[], int Left, int Right, int W)
{
  if (Left >= Right)
    return;

  if (W >= WordBytes)
    return;

  ElementType *Aux;
  int Count[R+1];
  int i, j;

  Aux = malloc(sizeof(ElementType) * (Right - Left + 1));

  for (i = 0; i <= R; ++i)
    Count[i] = 0;

  for (i = Left; i <= Right; ++i)
    Count[Digit(A[i], W) + 1]++;

  for (i = 1; i <= R; ++i)
    Count[i] += Count[i-1];

  for (i = Left; i <= Right; ++i)
    Aux[Count[Digit(A[i], W)]++] = A[i];

  for (i = Left; i <= Right; ++i)
    A[i] = Aux[i - Left];

  free(Aux);

  RMSD(A, Left, Left + Count[0] - 1, W + 1);

  for (i = 0; i < R - 1; ++i)
    RMSD(A, Left + Count[i], Left + Count[i+1] -1, W + 1);
}

void RadixMSD(ElementType A[], int Left, int Right)
{
  RMSD(A, Left, Right, 0);
}

int main(int argc, char const *argv[])
{
  int i, j;
  struct timeval tvBegin, tvEnd, tvDiff;
  ElementType *A;

  tvBegin = time_print();
  A = malloc((sizeof(ElementType)) * N);

  for (i = 0; i < N; ++i)
  {
    A[i] = malloc(sizeof(char) * (WordBytes + 1));
    memset(A[i], 0, WordBytes + 1);

    for (j = 0; j < WordBytes; ++j)
      A[i][j] = rand() % 26 + 'a';
  }

  // for (i = 0; i < N; ++i)
  //  printf("%s ", A[i]);

  // printf("\n");


  RadixLSD(A, 0, N - 1);
  // RadixMSD(A, 0, N - 1);

  tvEnd = time_print();
  time_diff_print(&tvDiff, &tvEnd, &tvBegin);

  // for (i = 0; i < N; ++i)
  // {
  //  printf("%s ", A[i]);
  //  free(A[i]);
  // }

  free(A);
  printf("\n");
  return 0;
}