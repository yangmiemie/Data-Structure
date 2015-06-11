#include <stdio.h>

int array[] = {4, -3, 5, -2, -1, 2, 6, -2};

int MaxSubSequenceSum1(const int A[], int N);
int MaxSubSequenceSum2(const int A[], int N);
int MaxSubSequenceSum3(const int A[], int N);

int main(int argc, char const *argv[])
{
	printf("%d\n", MaxSubSequenceSum1(array, sizeof(array) / sizeof(array[0])));
	printf("%d\n", MaxSubSequenceSum2(array, sizeof(array) / sizeof(array[0])));
	printf("%d\n", MaxSubSequenceSum3(array, sizeof(array) / sizeof(array[0])));
	return 0;
}

int MaxSubSequenceSum1(const int A[], int N)
{
	int i, j;
	int thisSum, maxSum;

	maxSum = 0;
	for (i = 0; i < N; ++i)
	{
		thisSum = 0;
		for (j = i; j < N; ++j)
		{
			thisSum += A[j];
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}

	return maxSum;
}

int Max3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else 
	{
		if (b > c)
			return b;
		else
			return c;
	}
}

int MaxSubSum(const int A[], int left, int right)
{
	int maxLeftSum, maxRightSum;
	int maxLeftBorderSum, maxRightBorderSum;
	int leftBorderSum, rightBorderSum;
	int mid, i;

if (left == right)
{
	if (A[left] > 0)
		return A[left];
	else
		return 0;
}

mid = (left + right) / 2;
maxLeftSum = MaxSubSum(A, left, mid);
maxRightSum = MaxSubSum(A, mid + 1, right);

maxLeftBorderSum = 0;	leftBorderSum = 0;
for (i = mid; i >= 0; --i)
{
	leftBorderSum += A[i];
	if (leftBorderSum > maxLeftBorderSum)
		maxLeftBorderSum = leftBorderSum;
}

maxRightBorderSum = 0;	rightBorderSum = 0;
for (i = mid + 1; i <= right; ++i)
{
	rightBorderSum += A[i];
	if (rightBorderSum > maxRightBorderSum)
		maxRightBorderSum = rightBorderSum;
}

return Max3(maxRightSum, maxLeftSum, maxRightBorderSum + maxLeftBorderSum);
}

int MaxSubSequenceSum2(const int A[], int N)
{
	return MaxSubSum(A, 0, N - 1);
}

int MaxSubSequenceSum3(const int A[], int N)
{
	int i;
	int maxSum, thisSum;

	maxSum = 0;
	thisSum = 0;
	for (i = 0; i < N; ++i)
	{
		thisSum += A[i];
		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}

	return maxSum;
}