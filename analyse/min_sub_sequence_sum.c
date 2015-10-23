#include <stdio.h>

int array[] = {4, -3, 5, -2, -1, 2, 6, -2};

int minSubSequenceSum1(const int A[], int N);
int minSubSequenceSum2(const int A[], int N);
int minSubSequenceSum3(const int A[], int N);

int main(int argc, char const *argv[])
{
  printf("%d\n", minSubSequenceSum1(array, sizeof(array) / sizeof(array[0])));  
  printf("%d\n", minSubSequenceSum2(array, sizeof(array) / sizeof(array[0])));  
  printf("%d\n", minSubSequenceSum3(array, sizeof(array) / sizeof(array[0])));  
  return 0;
}

int minSubSequenceSum1(const int A[], int N)
{
  int i, j;
  int thisSum, minSum;

  minSum = 0;
  for (i = 0; i < N; ++i)
  {
    thisSum = 0;
    for (j = i; j < N; ++j)
    {
      thisSum += A[j];
      if (thisSum < minSum)
        minSum = thisSum;     
    }
  }

  return minSum;
}

int Min3(int a, int b, int c)
{
  if (a < b)
  {
    if (a < c)
      return a;
    else 
      return c;
  }
  else
  {
    if (b < c)
      return b;
    else 
      return c;
  }
}

int minSubSum(const int A[], int left, int right)
{
  int leftMinSum, rightMinSum;
  int leftBorderSum, rightBorderSum;
  int minLeftBorderSum, minRightBorderSum;

  int mid, i;

  if (left == right)
  {
    if (A[left] < 0)
      return A[left];
    else
      return 0;
  }

  mid = (left + right) / 2;
  leftMinSum = minSubSum(A, 0, mid);
  rightMinSum = minSubSum(A, mid + 1, right);

  leftMinSum = 0;
  minLeftBorderSum = 0;
  for (i = mid; i >= 0; --i)
  {
    leftMinSum += A[i];
    if (minLeftBorderSum > leftMinSum)
      minLeftBorderSum = leftMinSum;
  }

  rightMinSum = 0;
  minRightBorderSum = 0;
  for (i = mid + 1; i <= right; ++i)
  {
    rightMinSum += A[i];
    if (minRightBorderSum > rightMinSum)
      minRightBorderSum = rightMinSum;
  }

  return Min3(leftMinSum, rightMinSum, minRightBorderSum + minLeftBorderSum);
}

int minSubSequenceSum2(const int A[], int N)
{
  return minSubSum(A, 0, N - 1);
}

int minSubSequenceSum3(const int A[], int N)
{
  int i;
  int thisSum, minSum;

  minSum = 0;
  thisSum = 0;
  for (i = 0; i < N; ++i)
  {
    thisSum += A[i];
    if (thisSum < minSum)
      minSum = thisSum;
    else if (thisSum > 0)
      thisSum = 0;
  }

  return minSum;
}