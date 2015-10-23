#include "open_address_hash.h"
#include <stdlib.h>

int Hash(ElementType Key, int TableSize)
{
  return Key % TableSize;
}

HashTable InitializeTable(int TableSize)
{
  HashTable H;
  int i;

  H = malloc(sizeof(struct HashTbl));
  H -> TableSize = TableSize;
  H -> TheCells = malloc(sizeof(Cell) * TableSize);

  for (i = 0; i < TableSize; ++i)
  {
    H -> TheCells[i].Info = Empty;
  }
  return H;
}

int Power(int Base, int Exponent)
{
  int i = 0;
  int Result = 1;

  while(i <  Exponent)
  {
    Result *= Base;
    ++i;
  }

  return Result;
}
// void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H)
{
  Position P;
  int CollisionNum;

  P = Hash(Key, H -> TableSize);
  CollisionNum = 0;

  // while(H -> TheCells[P].Info != Empty && H -> TheCells[P].Element != Key)
  // {
  //  P += ++CollisionNum;

  //  if (P >= H -> TableSize)
  //    P -= H -> TableSize;
  // }  

  // while(H -> TheCells[P].Info != Empty && H -> TheCells[P].Element != Key)
  // {
  //  P += Power(++CollisionNum, 2);

  //  while (P >= H -> TableSize)
  //    P -= H -> TableSize;
  // }

  while(H -> TheCells[P].Info != Empty && H -> TheCells[P].Element != Key)
  {
    P = 7 - (Key % 7);
  }
  return P;
}

void Insert(ElementType Key, HashTable H)
{
  Position P;
  P = Find(Key, H);

  if (H -> TheCells[P].Info != Legitimate)
  {
    H -> TheCells[P].Element = Key;
    H -> TheCells[P].Info = Legitimate;
  }
}
