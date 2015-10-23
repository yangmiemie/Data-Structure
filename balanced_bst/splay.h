#define ELementType int

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SplayTree;

SplayTree Insert(ELementType X, SplayTree T);
void PostOrderTraverse(SplayTree T);
void InOrderTraverse(SplayTree T);
void PreOrderTraverse(SplayTree T);
SplayTree InsertRotate(ELementType X, SplayTree T);


