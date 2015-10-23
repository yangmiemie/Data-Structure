#include <stdio.h>

#define ElementType char
#define BitWord 8
#define N 20

int Digit(ElementType E, int W)
{
  return (E >> (BitWord - W - 1)) & 1;
}

void Swap(ElementType A[], int i, int j)
{
  ElementType Temp;
  Temp = A[i];
  A[i] = A[j];
  A[j] = Temp;
}

void QSort(ElementType A[], int Left, int Right, int W)
{
  if (Left >= Right || W >= BitWord)
    return;

  int i, j;

  i = Left;
  j = Right;

  while(i < j)
  {
    while((Digit(A[i], W) == 0) && i < j) i++;
    while((Digit(A[j], W) == 1) && i < j) --j;
    Swap(A, i, j);
    ++i, --j;
  }

  if (Digit(A[Right], W) == 0) j++;

  QSort(A, Left, j, W + 1);
  QSort(A, j + 1, Right, W + 1);
}

void QuickSort(ElementType A[], int Left, int Right)
{
  QSort(A, Left, Right, 0);
}

int main(int argc, char const *argv[])
{
  ElementType A[N];
  int i;

  for (i = 0; i < N; ++i)
    A[i] = rand() % 128;

  for (i = 0; i < N; ++i)
    printf("%d ", A[i]);

  printf("\n");
  
  QuickSort(A, 0, N - 1);

  for (i = 0; i < N; ++i)
    printf("%d ", A[i]);

  printf("\n");

  return 0;
}