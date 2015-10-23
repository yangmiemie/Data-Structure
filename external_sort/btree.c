#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElementType int
#define M 6

typedef struct BNode* BLink;
typedef struct EntryNode* ELink;
typedef struct BHead* Head;

typedef struct {
  ElementType Key;
  union {
    BLink Next;
    ELink Item; 
  } Ref;
} Entry;

struct BNode {
  Entry Buffer[M];
  int Size;
};

struct EntryNode {
  ElementType Element;
  ElementType Key;
};

struct BHead {
  BLink Link;
  int Number;
  int Height;
};

ELink NewENode(ElementType X)
{
  ELink L;
  L = malloc(sizeof(struct EntryNode));
  L -> Element = X / 2;
  L -> Key = X;
}

BLink NewBNode()
{
  BLink L;

  L = malloc(sizeof(struct BNode));
  L -> Size = 0;
  memset(L -> Buffer, 0, sizeof(Entry) * M);
  return L;
}

Head Init()
{
  Head H;

  H = malloc(sizeof(struct BHead));
  H -> Number = H -> Height = 0;
  H -> Link = NewBNode();

  return H;
}

BLink Split(BLink L)
{
  int i;
  BLink P;

  P = NewBNode();

  for (i = 0; i < M / 2; ++i)
    P -> Buffer[i] = L -> Buffer[i + M / 2];

  P -> Size = M / 2;
  L -> Size = M / 2;
  return P;
}

BLink BInsert(BLink L, ElementType X, int Height)
{
  int i, j;
  Entry E;
  BLink P;

  E.Key = X;
  E.Ref.Item = NewENode(X);

  if (Height == 0)
  {
    for (j = 0; j < L -> Size; ++j)
      if (E.Key < L -> Buffer[j].Key)
        break;
  }

  if (Height > 0)
  {
    for (j = 0; j < L -> Size; ++j)
      if ((j + 1 == L -> Size) || (E.Key < L -> Buffer[j+1].Key))
      {
        P = BInsert(L -> Buffer[j].Ref.Next, X, Height - 1);
        ++j;
        if (P == NULL)
          return NULL;

        E.Key = P -> Buffer[0].Key;
        E.Ref.Next = P;
        break;
      }
  }

  for (i = (L -> Size)++; i > j; --i)
    L -> Buffer[i] = L -> Buffer[i-1];
  L -> Buffer[j] = E;

  if (L -> Size < M)
    return NULL;
  else
    return Split(L);
}

void Insert(Head H, ElementType X)
{
  BLink L, P;

  L = BInsert(H -> Link, X, H -> Height);

  if (L == NULL)
  {
    H -> Number++;
    return;
  }

  P = NewBNode();
  P -> Size = 2;
  P -> Buffer[0].Ref.Next = H -> Link;
  P -> Buffer[0].Key = H -> Link -> Buffer[0].Key;
  P -> Buffer[1].Ref.Next = L;
  P -> Buffer[1].Key = L -> Buffer[0].Key;

  H -> Link = P;
  H -> Height++;
  H -> Number++;
}

ELink BSearch(BLink L, ElementType X, int Height)
{
  int i;
  if (Height == 0)
    for (i = 0; i < L -> Size; ++i)
      if (L -> Buffer[i].Key == X)
        return L -> Buffer[i].Ref.Item;

  if (Height != 0)
  {
    for (i = 0; i < L -> Size; ++i)
      if ((i + 1 == L -> Size) || (L -> Buffer[i+1].Key > X))
        return BSearch(L -> Buffer[i].Ref.Next, X, Height - 1);
  }

  return NULL;
}

ELink Search(Head H, ElementType X)
{
  return BSearch(H -> Link, X, H -> Height);
}

void PrintBTree(BLink L, int Height)
{
  int i;

  if (L -> Size <= 0)
  {
    printf("\n");
    return;
  }

  if (Height == 0)
  {
    for (i = 0; i < L -> Size; ++i)
      printf("%d ", L -> Buffer[i].Key);
    return;
  }
    
  for (i = 0; i < L -> Size; ++i)
    PrintBTree(L -> Buffer[i].Ref.Next, Height - 1);
}

void PrintTree(Head H)
{
  PrintBTree(H -> Link, H -> Height);
}

int main(int argc, char const *argv[])
{
  // ElementType Array[] = {706, 176, 601, 153, 513, 773, 742, 373};
  ElementType Array[] = {706, 176, 601, 153, 513, 773, 742, 373, 524, 766, 275, 737, 574, 434, 641, 207, 001, 277, 061, 736, 526, 562,017, 107, 147, 12, 103, 665};
  Head H;
  int i, Len;
  ELink L;

  H = Init();
  Len = sizeof(Array) / sizeof(Array[0]);
  for (i = 0; i < Len - 3; ++i)
      Insert(H, Array[i]);

  PrintTree(H);
  printf("\n");

  for (i = 0; i < Len; ++i)
  {
    L = Search(H, Array[i]);
    if (L)
      printf("Found\n");
    else
      printf("Not Found\n");
  }
  return 0;
}