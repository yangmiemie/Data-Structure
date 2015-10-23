#include <stdio.h>
#include <stdlib.h>

typedef struct Node* PtrToNode;

struct Node
{
  int Coefficient;
  int Exponent;
  PtrToNode Next;
};

typedef PtrToNode List;
typedef PtrToNode Position;

int IsEmpty(List L)
{
  return L->Next == NULL;
}

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
  PtrToNode P = L -> Next;
  for ( ;P != NULL; P = P->Next)
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
  int Exp;

  for (P1 = List1->Next; P1 != NULL; P1 = P1->Next)
    for (P2 = List2->Next; P2 != NULL; P2 = P2->Next)
    {
      if (IsEmpty(ListProd))
      {
         TmpCell = NewNode(P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent);
         Insert(ListProd, ListProd, TmpCell);       
      }
      else
      {
        P = ListProd;
        Exp = P1 -> Exponent + P2 -> Exponent;

        while(P != NULL)
        {
          if (P -> Exponent == Exp)
          {
            P -> Coefficient += P1->Coefficient * P2->Coefficient;
            break;
          }
          else if (P -> Exponent < Exp && (P -> Next == NULL || P -> Next -> Exponent > Exp))
          {
            TmpCell = NewNode(P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent);
            Insert(P, ListProd, TmpCell);   
            break;      
          }

          P = P -> Next;
        }
      }
    }
}


Position GetMiddle(List List1, List List2)
{
  Position P;
  P = List1;

  if (IsEmpty(List1))
    return NULL;

  while(P != List2 && P -> Next != List2)
  {
    List1 = List1 -> Next;
    P = P -> Next -> Next;
  }

  return List1;
}

// Position MergePolynomial(List List1, List Middle, List List2)
// {
//  Position P, P1, P2, Header;
//  P1 = List1;
//  P2 = Middle;
//  Header = List1;
//  P = Header;

//  if (P1 -> Exponent > P2 -> Exponent)
//  {
//    P = P2;
//    P2 = P2 -> Next;
//  }
//  else
//  {
//    P = P1;
//    P1 = P1 -> Next;
//  }

//  while(P1 != Middle && P2 != List2)
//  {
//    if (P1 -> Exponent > P2 -> Exponent)
//    {
//      P -> Next = P2;
//      P2 = P2 -> Next;
//      P = P -> Next;
//    }
//    else
//    {
//      P -> Next = P1;
//      P1 = P1 -> Next;
//      P = P -> Next;
//    }
//  }

//  if (P1 != Middle)
//    P -> Next = P1;

//  if (P2 != List2)
//    P -> Next = P2;

//  return Header;
// }

Position MergePolynomial(List List1, List List2)
{
  Position P, P1, P2, Header;
  P1 = List1;
  P2 = List2;

  if (P1 -> Exponent > P2 -> Exponent)
  {
    P = P2;
    P2 = P2 -> Next;
  }
  else
  {
    P = P1;
    P1 = P1 -> Next;
  }

  Header = P;

  while(P1 != NULL && P2 != NULL)
  {
    if (P1 -> Exponent > P2 -> Exponent)
    {
      P -> Next = P2;
      P2 = P2 -> Next;
      P = P -> Next;
    }
    else
    {
      P -> Next = P1;
      P1 = P1 -> Next;
      P = P -> Next;
    }
  }

  if (P1 != NULL)
    P -> Next = P1;

  if (P2 != NULL)
    P -> Next = P2;

  return Header;
}

Position Split(List List1)
{
  Position P, Tmp;
  P = List1;
  Tmp = List1;

  while(P != NULL && P -> Next != NULL)
  {
    Tmp = List1;
    List1 = List1 -> Next;
    P = P -> Next -> Next;
  }

  Tmp -> Next = NULL;
  return List1;
}

Position MergeSortPolynomial(Position* List1)
{
  Position P;

  if (*List1 == NULL || (*List1) -> Next == NULL)
    return;

  P = Split(*List1);
  MergeSortPolynomial(List1);
  MergeSortPolynomial(&P);

  *List1 = MergePolynomial(*List1, P);
}


void RemoveDupPoly(List List1)
{
  Position P1, P2, Tmp;
  if (IsEmpty(List1))
    return;

  P1 = List1 -> Next;
  P2 = P1 -> Next;
  
  while(P2 != NULL)
  {
    if (P1 -> Exponent == P2 -> Exponent)
    {
      P1 -> Coefficient += P2 -> Coefficient;
      Tmp = P2;
      P2 = P2 -> Next;
      P1 -> Next = P2;
      free(Tmp);
    }
    else
    {
      P1 = P1 -> Next;
      P2 = P2 -> Next;
    }
  }
}

void MultiPolynomialLogN(const List List1, const List List2, List ListProd)
{
  Position P1, P2, P;
  Position TmpCell;
  int Exp;

  for (P1 = List1->Next; P1 != NULL; P1 = P1->Next)
    for (P2 = List2->Next; P2 != NULL; P2 = P2->Next)
    {
        TmpCell = NewNode(P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent);
        Insert(ListProd, ListProd, TmpCell);  
    }

  printPolynomial(ListProd);
  MergeSortPolynomial(&(ListProd -> Next));
  printPolynomial(ListProd);
  RemoveDupPoly(ListProd);
  printPolynomial(ListProd);
}


int main(int argc, char const *argv[])
{
  List header1 = malloc(sizeof(struct Node));
  List header2 = malloc(sizeof(struct Node));
  List headerSum = malloc(sizeof(struct Node));
  List headerProd = malloc(sizeof(struct Node));
  header1->Next = NULL;
  header2->Next = NULL;
  headerProd -> Next = NULL;
  headerProd -> Exponent = -1;
  PtrToNode Tmp;


  PtrToNode P = malloc(sizeof(struct Node));
  Tmp = header1;
  P->Coefficient = 1;
  P->Exponent = 1;
  Insert(Tmp, header1, P);
  Tmp = Tmp -> Next;

  P = malloc(sizeof(struct Node));
  P->Coefficient = 2;
  P->Exponent = 2;
  Insert(Tmp, header1, P);
  Tmp = Tmp -> Next;

  P = malloc(sizeof(struct Node));
  P->Coefficient = 3;
  P->Exponent = 3;
  Insert(Tmp, header1, P);
  Tmp = Tmp -> Next;

  P = malloc(sizeof(struct Node));
  P->Coefficient = 4;
  P->Exponent = 4;
  Insert(Tmp, header1, P);
  Tmp = Tmp -> Next;

  P = malloc(sizeof(struct Node));
  Tmp = header2;
  P->Coefficient = 1;
  P->Exponent = 1;
  Insert(Tmp, header2, P);
  Tmp = Tmp -> Next;

  P = malloc(sizeof(struct Node));
  P->Coefficient = 2;
  P->Exponent = 2;
  Insert(Tmp, header2, P);
  Tmp = Tmp -> Next;

  P = malloc(sizeof(struct Node));
  P->Coefficient = 3;
  P->Exponent = 3;
  Insert(Tmp, header2, P);
  Tmp = Tmp -> Next;

  P = malloc(sizeof(struct Node));
  P->Coefficient = 4;
  P->Exponent = 4;
  Insert(Tmp, header2, P);
  Tmp = Tmp -> Next;

  // PtrToNode P = malloc(sizeof(struct Node));
  // Tmp = header1;
  // P->Coefficient = 1;
  // P->Exponent = 0;
  // Insert(Tmp, header1, P);
  // Tmp = Tmp -> Next;

  // P = malloc(sizeof(struct Node));
  // P->Coefficient = 5;
  // P->Exponent = 14;
  // Insert(Tmp, header1, P);
  // Tmp = Tmp -> Next;

  // P = malloc(sizeof(struct Node));
  // P->Coefficient = 10;
  // P->Exponent = 1000;
  // Insert(Tmp, header1, P);
  // Tmp = Tmp -> Next;

  // P = malloc(sizeof(struct Node));
  // P->Coefficient = 5;
  // P->Exponent = 0;
  // Insert(Tmp, header1, P);
  // Tmp = Tmp -> Next;

  // P = malloc(sizeof(struct Node));
  // P->Coefficient = 11;
  // P->Exponent = 14;
  // Insert(Tmp, header1, P);
  // Tmp = Tmp -> Next;

  // P = malloc(sizeof(struct Node));
  // P->Coefficient = -2;
  // P->Exponent = 1492;
  // Insert(Tmp, header1, P);
  // Tmp = Tmp -> Next;

  // P = malloc(sizeof(struct Node));
  // P->Coefficient = 3;
  // P->Exponent = 1990;
  // Insert(Tmp, header1, P);

  // printPolynomial(header1);
  // printPolynomial(header2);

  // AddPolynomial(header1, header2, headerSum);
  // printPolynomial(headerSum);

  // MultiPolynomial(header1, header2, headerProd);
  // printPolynomial(headerProd);
  MultiPolynomialLogN(header1, header2, headerProd);
  
  // header1 -> Next = MergeSortPolynomial(header1 -> Next, NULL);
  // printPolynomial(header1);

  DeleteList(header1);
  DeleteList(header2);
  DeleteList(headerSum);
  DeleteList(headerProd);
  return 0;
}