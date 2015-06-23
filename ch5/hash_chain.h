#define ElementType int
#define HashSize 10

// struct ListNode;
typedef struct ListNode *Position;
typedef struct ListNode *List;

// struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);

struct ListNode
{
	ElementType Element;
	Position Next;
};

struct HashTbl
{
	int TableSize;
	List* TheList;
};