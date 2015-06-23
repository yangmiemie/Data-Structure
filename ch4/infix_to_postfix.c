#include "stack.h"
#include "queue.h"
#include "string.h"

#define ISCHAR(X) ((((X) >= 'A') && ((X) <= 'Z')) || (((X) >= 'a') && ((X) <= 'z')))
#define ISOP(X) ((X == '+') || (X == '-') || (X == '*') || (X == '/') || (X == '(') || (X == ')'))
#define ExpressionSize 32

int OperatorPriority(char c);

void InfixToPostfix(char* InfixExpression, char* PostfixExpression)
{
	ArrayStack S;
	Queue Q;
	char* Ptr;
	char c;

	Ptr = InfixExpression;
	S = CreateArrayStack(ExpressionSize);
	Q = CreateQueue(ExpressionSize);

	while((c = *Ptr) != '\0')
	{
		if (ISCHAR(c))
			Enqueue(c, Q);
		else if (ISOP(c))
		{
			if (IsArrayStackEmpty(S))
				Push(c, S);	
			else
			{
				if (c == '(')
					Push(c, S);
				else if (c == ')')
				{
					while((!IsArrayStackEmpty(S)) && Top(S) != '(')
					{
						Enqueue(TopAndPop(S), Q);
					}
					Pop(S);
				}
				else if (OperatorPriority(c) > OperatorPriority(Top(S)))
					Push(c, S);
				else
				{
					while((!IsArrayStackEmpty(S)) && (Top(S) != '(') && (OperatorPriority(c) <= OperatorPriority(Top(S))))
					{
						Enqueue(TopAndPop(S), Q);
					}
					Push(c, S);
				}
			}
		}
		else
		{
			fprintf(stderr, "Error Character");
			exit(1);
		}
		++Ptr;
	}

	while (!IsArrayStackEmpty(S))
	{
		Enqueue(TopAndPop(S), Q);
	}

	Ptr = PostfixExpression;
	while(!IsEmpty(Q))
	{
		*Ptr++ = FrontAndDequeue(Q);
	}
}

int main(int argc, char const *argv[])
{
	char *infix = "((a+b*c))+((d*e+f)*g)";
	char *PostfixExpression;

	PostfixExpression = (char*)malloc(strlen(infix));

	InfixToPostfix(infix, PostfixExpression);
	printf("%s\n", PostfixExpression);
	return 0;
}


int OperatorPriority(char c)
{
	switch(c)
	{
		case '-':
		case '+':
			return 0;
		case '*':
		case '/':
			return 1;
		case '(':
		case ')':
			return 2;
		default:
			return -1;
	}
}