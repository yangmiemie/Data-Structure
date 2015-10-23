#include <stdio.h>

#define MaxDegree 6400

typedef struct
{
  int CoeffArray[MaxDegree+1];
  int HighPower;
} PolyStruct;

typedef PolyStruct* Polynomial;

void ZeroPolynomial(Polynomial Poly)
{
  int i;
  for (i = 0; i <= MaxDegree; ++i)
    Poly->CoeffArray[i] = 0;

  Poly->HighPower = 0;
}

int Max(int a, int b)
{
  return (a > b) ? a : b;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
  int i;
  ZeroPolynomial(PolySum);
  PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);

  for (i = 0; i <= PolySum->HighPower ; ++i)
    PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultiPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
  int i, j;
  ZeroPolynomial(PolyProd);
  PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

  for (i = 0; i <= Poly1->HighPower; ++i)
    for (j = 0; j <= Poly2->HighPower; ++j)
    PolyProd->CoeffArray[i+j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
}

void printPolynomial(const Polynomial Poly)
{
  int i;
  for (i = Poly->HighPower; i >= 0; --i)
    if (Poly->CoeffArray[i] != 0)
      printf("%d\X^%d ", Poly->CoeffArray[i], i);

  printf("\n");
}

int main(int argc, char const *argv[])
{
  Polynomial Poly1, Poly2, PolySum, PolyProd;
  Poly1 = malloc(sizeof(PolyStruct));
  Poly2 = malloc(sizeof(PolyStruct));
  PolySum = malloc(sizeof(PolyStruct));
  PolyProd = malloc(sizeof(PolyStruct));

  ZeroPolynomial(Poly1);
  ZeroPolynomial(Poly2);

  Poly1->HighPower = 1000;
  Poly1->CoeffArray[1000] = 10;
  Poly1->CoeffArray[14] = 5;
  Poly1->CoeffArray[0] = 1;

  Poly2->HighPower = 1990;
  Poly2->CoeffArray[1990] = 3;
  Poly2->CoeffArray[1492] = -2;
  Poly2->CoeffArray[14] = 11;
  Poly2->CoeffArray[0] = 5;

  AddPolynomial(Poly1, Poly2, PolySum);
  MultiPolynomial(Poly1, Poly2, PolyProd);

  printPolynomial(Poly1);
  printPolynomial(Poly2);
  printPolynomial(PolySum);
  printPolynomial(PolyProd);
  return 0;
}