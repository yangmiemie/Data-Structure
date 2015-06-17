#include <stdio.h>
#include <string.h>
#include "stack_list.h"
#include "queue.h"

#define BUFSIZE 64
#define IS_CHAR(X) (((X) >= 'a') && ((X) <= 'z'))
#define IS_OP(X) (((X) == '+') || ((X) == '-') || ((X) == '*') || ((X) == '/'))
#define IS_PAREN(X) ((X) == '(') || ((X) == ')')
#define IS_DIGIT(X) ((X - '0') <= 9) && ((X - '0') >= 0)
char ExpressList[BUFSIZE];

void SplitExpress(char*, char*);
int Priority(int X);
int Calculate(int Op1, int Op2, char Tmp);

int main(int argc, char const *argv[])
{
	// char *Express = "a + b * c + ( d + e + f ) * g";
	// char *Express = "1 + 2 * 3 + ( 4 + 5 + 6 - 2 ) * 7";
	char *Express = "6 * ( 5 + ( 2 + 3 ) * 8 + 3 )";
	Stack S;
	struct StackRecord* StackSum;
	Queue Q;
	int i, Len, Tmp, Op1, Op2, Result;
	char TmpOp = -1;

	SplitExpress(Express, ExpressList);
	printf("%s\n", ExpressList);
	
	S = CreateStack();
	StackSum = CreateStackArray(BUFSIZE);
	Q = CreateQueue(BUFSIZE);
	Len = strlen(ExpressList);

	for (i = 0; i < Len; ++i)
	{
		if (IS_DIGIT(ExpressList[i]))
			Enqueue(ExpressList[i], Q);

		if (TmpOp != -1)
		{
			Enqueue(TmpOp, Q);
			TmpOp = -1;
		}

		if (ExpressList[i] == '(')
			Push(ExpressList[i], S);

		if (ExpressList[i] == ')')
		{
			while(!IsEmptyStack(S) && (Top(S) != '('))
			{
				Enqueue(Top(S), Q);
				Pop(S);
			}

			if (IsEmptyStack(S))
			{
				fprintf(stderr, "Error Expression\n");
				exit(1);
			}
			Pop(S);
		}

		if (IS_OP(ExpressList[i]))
		{
			if (!IsEmptyStack(S))
			{
				if ((Priority(Top(S)) < Priority(ExpressList[i])))
					TmpOp = ExpressList[i];
					// Enqueue(ExpressList[i], Q);
				else if ((Priority(Top(S)) > Priority(ExpressList[i])))
				{
					if (Top(S) == '(')
					{
						Push(ExpressList[i],S);
					}
					else
					{
						while(!IsEmptyStack(S) && (Top(S) != '(') && (Priority(Top(S)) > Priority(ExpressList[i])))
						{
							Enqueue(Top(S), Q);
							Pop(S);
							Push(ExpressList[i], S);
						}
					}
				}
				else if (Priority(Top(S)) == Priority(ExpressList[i]))
				{
					Enqueue(Top(S), Q);
					Pop(S);
					Push(ExpressList[i], S);				
				}
			}
			else
			{
				Push(ExpressList[i], S);
			}
		}
	}g

	while(!IsEmptyStack(S))
	{
		Enqueue(Top(S), Q);
		Pop(S);	
	}

	while(!IsEmptyQueue(Q))
	{	
		Tmp = FrontAndDequeue(Q);

		if (IS_DIGIT(Tmp))
			PushArray(Tmp - '0', StackSum);
		else if (IS_OP(Tmp))
		{
			if (IsEmptyStackArray(StackSum))
			{
				fprintf(stderr, "Empty Stack for Sum\n");
				exit(1);
			}
			else
			{
				Op2 = TopArray(StackSum);
				PopArray(StackSum);
				Op1 = TopArray(StackSum);
				PopArray(StackSum);

				PushArray(Calculate(Op1, Op2, Tmp), StackSum);
			}
		}
		printf("%c ", Tmp);
	}

	Result = TopArray(StackSum);

	printf("\n");
	printf("Result = %d\n", Result);

	return 0;
}

int Calculate(int Op1, int Op2, char Tmp)
{
	int result;

	switch(Tmp)
	{
		case '+':
			result = Op1 + Op2;
			break;
		case '-':
			result = Op1 - Op2;
			break;
		case '*':
			result = Op1 * Op2;
			break;
		case '/':
			result = Op1 / Op2;
			break;
	}

	return result;
}

int Priority(int X)
{
	switch(X)
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

void SplitExpress(char* Express, char* List)
{
	char* PtrToFront, *PTrToRear;

	PtrToFront = Express;
	PTrToRear = Express;
	while(*PtrToFront != '\0')
	{
		if (*PtrToFront == ' ')
		{
			*List++ = *PTrToRear;
			PTrToRear = PtrToFront + 1;
		}	

		++PtrToFront;
	}

	*List++ = *PTrToRear;
	*List = '\0';
}