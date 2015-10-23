#define ElementType int
#define NULL 0
#define MaxTrees 32

#include <stdlib.h>

typedef struct BinNode *Position;
typedef struct BinNode *BinTree;
typedef struct Collection *BinQueue;

struct BinNode
{
  ElementType Element;
  Position LeftChild;
  Position NextSibling;
};

struct Collection
{
  int CurrentSize;
  BinTree TheTrees[MaxTrees];
};

BinQueue CreateCollection();
void Insert(ElementType X, BinQueue Q);
BinTree CombineTrees(BinTree T1, BinTree T2);
void DisposeCollection(BinQueue Q);
BinQueue Merge(BinQueue Q1, BinQueue Q2);
