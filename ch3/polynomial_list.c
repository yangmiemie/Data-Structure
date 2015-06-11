#include <stdio.h>

typedef struct Node* PtrToNode;

struct Node
{
	int Coefficient;
	int Exponent;
	PtrToNode Next;
};

typedef PtrToNode List;
typedef PtrToNode Position;

Position FindPrevious(Position P, List L)
{
	Position TmpCell;
	TmpCell = L;
	while(TmpCell->Next != NULL && TmpCell->Next != P)
		TmpCell = TmpCell->Next;

	return TmpCell;
}

Position Find(int Exponent, List L)
{
	Position P;

	P = L->Next;
	while(P != NULL && P->Exponent != Exponent)
		P = P->Next;

	return P;
}

int IsLast(Position P)
{
	return P->Next == NULL;
}

void Insert(Position P, List L, PtrToNode Node)
{	
	Position TmpCell;
	TmpCell = P->Next;
	P->Next = Node;
	Node->Next = TmpCell;
}

void printPolynomial(const List L)
{
	PtrToNode P;
	for (P = L; P != NULL; P = P->Next)
		if (P->Coefficient != 0)
			printf("%dX^%d ", P->Coefficient, P->Exponent);

	printf("\n");
}

PtrToNode NewNode(int Coefficient, int Exponent)
{
	PtrToNode P = malloc(sizeof(struct Node));
	P->Coefficient = Coefficient;
	P->Exponent = Exponent;
	P->Next = NULL;
	return P;
}

void DeleteList(List L)
{
	Position P, TmpCell;
	P = L->Next;
	L-> Next = NULL;
	
	while(P)
	{
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
}

void AddPolynomial(const List List1, const List List2, List ListSum)
{
	Position P1, P2;
	for (P1 = List1->Next, P2 = List2->Next; (P1 != NULL) && (P2 != NULL); )
	{
		if (P1->Exponent > P2->Exponent)
		{
			Insert(ListSum, ListSum, NewNode(P1->Coefficient, P1->Exponent));
			P1 = P1->Next;
		}
		else if (P1->Exponent < P2->Exponent)
		{
			Insert(ListSum, ListSum, NewNode(P2->Coefficient, P2->Exponent));
			P2 = P2->Next;
		}
		else
		{
			Insert(ListSum, ListSum, NewNode(P2->Coefficient + P1->Coefficient, P2->Exponent + P1->Exponent));
			P2 = P2->Next;			
			P1 = P1->Next;
		}
	}

	while(P1 != NULL)
	{
		Insert(ListSum, ListSum, NewNode(P1->Coefficient, P1->Exponent));
		P1 = P1->Next;
	}


	while(P2 != NULL)
	{
		Insert(ListSum, ListSum, NewNode(P2->Coefficient, P2->Exponent));
		P2 = P2->Next;
	}

}

void MultiPolynomial(const List List1, const List List2, List ListProd)
{
	Position P1, P2, P;
	Position TmpCell;

	for (P1 = List1->Next; P1 != NULL; P1 = P1->Next)
		for (P2 = List2->Next; P2 != NULL; P2 = P2->Next)
		{
			P = Find(P1->Exponent + P2->Exponent, ListProd);
			if (P)
			{
				P->Exponent += P1->Exponent + P2->Exponent;
				P->Coefficient += P1->Coefficient * P2->Coefficient;
			}
			else
			{
				 TmpCell = NewNode(P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent);
				 Insert(ListProd, ListProd, TmpCell);
			}
		}
}

int main(int argc, char const *argv[])
{
	List header1 = malloc(sizeof(struct Node));
	List header2 = malloc(sizeof(struct Node));
	List headerSum = malloc(sizeof(struct Node));
	List headerProd = malloc(sizeof(struct Node));
	header1->Next = NULL;
	header2->Next = NULL;
	headerProd->Next = NULL;

	PtrToNode P = malloc(sizeof(struct Node));
	P->Coefficient = 1;
	P->Exponent = 0;
	Insert(header1, header1, P);

	P = malloc(sizeof(struct Node));
	P->Coefficient = 5;
	P->Exponent = 14;
	Insert(header1, header1, P);

	P = malloc(sizeof(struct Node));
	P->Coefficient = 10;
	P->Exponent = 1000;
	Insert(header1, header1, P);

	P = malloc(sizeof(struct Node));
	P->Coefficient = 5;
	P->Exponent = 0;
	Insert(header2, header2, P);

	P = malloc(sizeof(struct Node));
	P->Coefficient = 11;
	P->Exponent = 14;
	Insert(header2, header2, P);

	P = malloc(sizeof(struct Node));
	P->Coefficient = -2;
	P->Exponent = 1492;
	Insert(header2, header2, P);

	P = malloc(sizeof(struct Node));
	P->Coefficient = 3;
	P->Exponent = 1990;
	Insert(header2, header2, P);

	printPolynomial(header1);
	printPolynomial(header2);

	AddPolynomial(header1, header2, headerSum);
	printPolynomial(headerSum);

	MultiPolynomial(header1, header2, headerProd);
	printPolynomial(headerProd);

	DeleteList(header1);
	DeleteList(header2);
	DeleteList(headerSum);
	DeleteList(headerProd);
	return 0;
}