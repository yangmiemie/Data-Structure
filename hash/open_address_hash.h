#define ElementType int
#define HashSize 10

typedef int Position;

typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);

enum  KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry
{
  ElementType Element;
  enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
  int TableSize;
  Cell* TheCells;
};