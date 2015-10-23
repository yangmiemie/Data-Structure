#include "sort.h"
#include "stack.h"

#define SIZE 10

void Swap(ElementType A[], int i, int j)
{
  ElementType Temp;
  Temp = A[i];
  A[i] = A[j];
  A[j] = Temp;
}

void SelectionSort(ElementType A[], int N)
{
  int i, j, MinIndex;

  for (i = 0; i < N; ++i)
  {
    MinIndex = i;

    for (j = i + 1; j < N; ++j)
    {
      if (A[j] < A[MinIndex])
      {
        MinIndex = j;
      }
    }

    Swap(A, i, MinIndex);
  }
}

void InsertionSort(ElementType A[], int N)
{
  int i, j;
  ElementType Item;

  for (i = 1; i < N; ++i)
  {
    Item = A[i];

    for (j = i - 1; j >= 0; --j)
    {
      if (A[j] > Item)
        Swap(A, j, j + 1);
    }
  }
}

void InsertionSortImproved(ElementType A[], int N)
{
  int i, j;
  int MinIndex, Item;

  MinIndex = 0;
  for(i = 0; i < N; ++i)
    if (A[i] < A[MinIndex])
      MinIndex = i;

  Swap(A, MinIndex, 0);

  for (i = 2; i < N; ++i)
  {
    Item = A[i];
    j = i;
    
    // while(A[j] > Item) cannot work, j = 0 and will replace first item.
    while(A[j-1] > Item)
    {
      A[j] = A[j-1];
      --j;
    } 

    A[j] = Item;
  }
}

void BubbleSort(ElementType A[], int N)
{
  int i, j;

  for (j = N - 1; j > 0; --j)
  {
    for (i = 0; i < j; ++i)
    {
      if (A[i] > A[i+1])
        Swap(A, i, i + 1);
    }
  }
}

void ShellSort(ElementType A[], int N)
{
  int i, j, h;
  ElementType Item;

  for (h = 1; h <= N / 9; h = 3 * h + 1);

  for (; h >= 1; h /= 3)
  {
  h = 1;

    for (i = h; i < N; ++i)
    {
      j = i;
      Item = A[i];
      while((j >= h) && (A[j-h] > Item))
      {
        A[j] = A[j-h];
        j -= h;
      } 

      A[j] = Item;
    }
  }

}

int Partition(ElementType A[], int Left, int Right)
{
  int i, j, Pivot;

  i = Left + 1;
  j = Right;
  Pivot = A[Left];

  while(1)
  {
    while(i <= Right && A[i] < Pivot) ++i;
    while(A[j] > Pivot) --j;

    if (i > j)
      break;

    Swap(A, i, j);
    ++i, --j;
  }

  Swap(A, Left, j);
  return j;
}

void QSort(ElementType A[], int Left, int Right)
{
  int Position;

  if (Right <= Left)
    return;

  Position = Partition(A, Left, Right);
  QSort(A, Left, Position - 1);
  QSort(A, Position + 1, Right);
}

void QuickSort2(ElementType A[], int Left, int Right)
{
  int i, j;
  int Pivot;

  if (Left >= Right)
    return;

  i = Left + 1;
  j = Right;
  Pivot = A[Left];

  while(1)
  {
    while(i <= Right && A[i] < Pivot) ++i;
    while(A[j] > Pivot) --j;

    if (i > j)
      break;

    Swap(A, i, j);
    ++i, --j;
  }

  Swap(A, Left, j);

  QuickSort2(A, Left, j - 1);
  QuickSort2(A, j + 1, Right);
}

void QuickSort3(ElementType A[], int Left, int Right)
{
  Stack S;
  int i, j, Position;

  S = CreateStack(32);
  Push(Left, S), Push(Right, S);

  while(!IsEmpty(S))
  {
    i = TopAndPop(S);
    j = TopAndPop(S);

    if (Right <= Left)
      continue;

    Position = Partition(A, j, i);

    if (Position > j)
      Push(j, S), Push(Position - 1, S);

    if (Position < i)
      Push(Position + 1, S), Push(i, S);
  }
}

int GetMiddle(ElementType A[], int Left, int Right)
{
  int Center;

  Center = (Left + Right) / 2;

  if (A[Center] > A[Right])
    if (A[Left] > A[Center])
      return Center;
    else
      if (A[Left] < A[Right])
        return Right;
      else
        return Left;
  else
    if (A[Left] > A[Right])
      return Right;
    else
      if (A[Left] < A[Center])
        return Center;
      else
        return Left;
}
void QuickSort4(ElementType A[], int Left, int Right)
{
  int i, j, Pivot;

  if (Right - Left <= SIZE)
    return;

  Swap(A, Left, GetMiddle(A, Left, Right));

  i = Left + 1;
  j = Right;
  Pivot = A[Left];

  while(1)
  {
    while(i <= Right && A[i] < Pivot) ++i;
    while(A[j] > Pivot) --j;

    if (i > j)
      break;

    Swap(A, i, j);
    ++i, --j;
  }

  Swap(A, Left, j);

  QuickSort4(A, Left ,j - 1);
  QuickSort4(A, j + 1, Right);
}

void QSort2(ElementType A[], int Left, int Right)
{
  QuickSort4(A, Left, Right);
  InsertionSort(A, Right + 1);
}

void QSort3(ElementType A[], int Left, int Right)
{
  int i, j, p, q; 
  int Pivot;

  if (Left >= Right)
    return;

  i = Left + 1;
  j = Right;
  p = i, q = j;
  Pivot = A[Left];

  while(1)
  {
    while(i <= Right && A[i] < Pivot) ++i;
    while(A[j] > Pivot) --j;

    if (i >= j)
      break;

    Swap(A, i, j);
    if (A[i] == Pivot) Swap(A, p++, i);
    if (A[j] == Pivot) Swap(A, q--, j);
    ++i, --j;
  }

  --p, ++q;

  for (; p >= Left; --p, --j) 
    Swap(A, p, j);
  
  for (; q <= Right; ++q, ++i)
    Swap(A, q, i);

  QSort3(A, Left, j);
  QSort3(A, i, Right);
}

void QuickSort(ElementType A[], int N)
{
  QSort3(A, 0, N - 1);
}

void Select(ElementType A[], int Left, int Right, int K)
{
  int Position;

  if (Left >= Right)
    return;

  Position = Partition(A, Left, Right);

  if (Position < K)
    Select(A, Position + 1, Right, K);

  if (Position > K)
    Select(A, Left, Position - 1, K);
}

void Select2(ElementType A[], int Left, int Right, int K)
{
  int Position;

  while(Left < Right)
  {
    Position = Partition(A, Left, Right);
    if (Position <= K) Left = Position + 1;
    if (Position >= K) Right = Position - 1;
  }
}

void Merge(ElementType A[], ElementType TmpArray[], int Left, int Center, int Right)
{
  int i, j, k;

  i = Left;
  j = Center + 1;
  k = 0;

  while(i <= Center && j <= Right)
  {
    if (A[i] < A[j])
      TmpArray[k++] = A[i++];
    else
      TmpArray[k++] = A[j++];
  }

  while(i <= Center)
    TmpArray[k++] = A[i++];

  while(j <= Right)
    TmpArray[k++] = A[j++];

  for (i = 0, j = Left; i < k; ++i, ++j)
    A[j] = TmpArray[i];
}

void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
  int Center;

  if (Left >= Right)
    return;

  Center = (Left + Right) / 2;
  MSort(A, TmpArray, Left, Center);
  MSort(A, TmpArray, Center + 1, Right);
  Merge(A, TmpArray, Left, Center, Right);
}

void MergeAB(ElementType C[], ElementType A[], int M, ElementType B[], int N)
{
  int i, j, k;

  i = j = k = 0;
  while(i < M && j < N)
  {
    if (A[i] < B[j])
      C[k++] = A[i++];
    else
      C[k++] = B[j++];
  }

  while(i < M)
    C[k++] = A[i++];

  while(j < N)
    C[k++] = B[j++];
}

void MSort2(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
  int Center;

  if (Left >= Right)
    return;

  Center = (Left + Right) / 2;
  MSort(TmpArray, A, Left, Center);
  MSort(TmpArray, A, Center + 1, Right);
  MergeAB(A + Left, TmpArray, Center - Left + 1, TmpArray + Center + 1, Right - Center);
}

ElementType Min(ElementType a, ElementType b)
{
  return a > b ? b : a;
}

void MSort3(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
  int i, m;

  for(m = 1; m <= Right - Left; m += m)
  {
    for (i = Left; i <= Right - m; i += m + m)
    {
      Merge(A, TmpArray, i, i + m - 1, Min(i + 2 * m - 1, Right));
    }
  }
}

void MergeSort(ElementType A[], int N)
{
  ElementType *TmpArray;
  int i;

  TmpArray = malloc(sizeof(ElementType) * N);

  // for (i = 0; i < N; ++i)
  //  TmpArray[i] = A[i];

  MSort3(A, TmpArray, 0, N - 1);
  free(TmpArray);
}

