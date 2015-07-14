#define ElementType int

typedef struct SplayNode *Position;
typedef struct SplayNode *SplayTree;

struct SplayNode
{
	ElementType Element;
	Position Right;
	Position Left;
};

SplayTree Insert(ElementType Element, SplayTree T);
SplayTree BSTInsert(ElementType Element, SplayTree T);
SplayTree Splay(ElementType X, SplayTree T);
