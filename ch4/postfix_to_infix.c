#include "stack.h"
#include <string.h>
#include <stdio.h>

#define TreeNodeElementType char
#define ExpressionSize 32

#define ISDIGIT(X) (((X) >= 'A') && ((X) <= 'Z')) || (((X) >= 'a') && ((X) <= 'z'))
#define ISOP(X) (((X) == '+') || ((X) == '-') || ((X) == '*') || ((X) == '/'))

typedef struct ExpressionTreeNode* ExpressionTreePosition;
typedef struct ExpressionTreeNode* ExpressionTree;

struct ExpressionTreeNode
{
	TreeNodeElementType Element;
	ExpressionTree Left;
	ExpressionTree Right;
};

ExpressionTreePosition CreateNode(TreeNodeElementType X)
{
	ExpressionTreePosition P;
	P = malloc(sizeof(struct ExpressionTreeNode));
	P -> Left = NULL;
	P -> Right = NULL;
	P -> Element = X;
	return P;
}

ExpressionTree BuildExpressionTree(char* PostfixExpression)
{
	ArrayStack S;
	ExpressionTreePosition P;
	int Size, i;

	S = CreateArrayStack(ExpressionSize);
	Size = strlen(PostfixExpression);

	for (i = 0; i < Size; ++i)
	{
		if (ISDIGIT(PostfixExpression[i]))
			Push(CreateNode(PostfixExpression[i]), S);
		else if (ISOP(PostfixExpression[i]))
		{
			P = CreateNode(PostfixExpression[i]);
			P -> Right = TopAndPop(S);
			P -> Left = TopAndPop(S);
			Push(P, S);
		}
	}

	P = TopAndPop(S);
	if (!IsArrayStackEmpty(S))
	{
		fprintf(stderr, "Error PostfixExpression\n");
		exit(1);
	}

	DisposeStack(S);
	return P;
}

void PreOrderTraverse(ExpressionTree T)
{
	if (T != NULL)
	{
		printf("%c", T -> Element);
		PreOrderTraverse(T -> Left);
		PreOrderTraverse(T -> Right);
	}
}

void InOrderTraverse(ExpressionTree T)
{
	if (T != NULL)
	{
		InOrderTraverse(T -> Left);
		printf("%c", T -> Element);
		InOrderTraverse(T -> Right);
	}
}

void PostOrderTraverse(ExpressionTree T)
{
	if (T != NULL)
	{
		PostOrderTraverse(T -> Left);
		PostOrderTraverse(T -> Right);
		printf("%c", T -> Element);
	}
}

int main(int argc, char const *argv[])
{
	// char *s = "ab+";
	char *s = "ab+cde+**";
	ExpressionTree T;

	T = BuildExpressionTree(s);

	PreOrderTraverse(T);
	printf("\n");

	InOrderTraverse(T);
	printf("\n");

	PostOrderTraverse(T);
	printf("\n");
	return 0;
}
