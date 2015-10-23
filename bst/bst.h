#define ElementType char

struct BSTNode;
typedef struct BSTNode* Position;
typedef struct BSTNode* BSTree;

Position Search(ElementType X, BSTree T);
BSTree Insert(ElementType X, BSTree T);
void PreOrderTraverse(BSTree T);
BSTree Insert2(ElementType X, BSTree T);
BSTree Insert3(ElementType X, BSTree T);
Position Select(int k, BSTree T);
int Value(Position P);
BSTree Partition(int k, BSTree T);
BSTree Delete(ElementType X, BSTree T);
BSTree Join(BSTree T1, BSTree T2);
