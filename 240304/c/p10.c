#include <stdio.h>
#define ITEMS 6

void printPoly(int poly[]);
void sumPoly(int poly1[ITEMS], int poly2[ITEMS]);

int main(int argc, char const *argv[]) {
  int PolyA[ITEMS]={4,3,7,0,6,2}, PolyB[ITEMS]={4,1,5,2,0,9};
printf("多項式A=>");PrintPoly(PolyA, ITEMS);
printf("多項式B=> "); PrintPoly(PolyB, ITEMS);
printf ("A+B => "); PolySum(PolyA,PolyB);
  return 0;
}

void printPoly(int Poly[]) {
  int i,MaxExp;
  MaxExp= Poly[0];
  for (i=1;i<=Poly[0]+1;i++) {
    MaxExp--;
    if (Poly[i] == 0)
      break;
    if ((MaxExp + 1) == 0)
      printf(" %d", Poly[i]);
    else
      printf(" %dX^%d", Poly[i], MaxExp + 1);
    if (MaxExp >= 0)
      printf("+");
  }
  printf("\n");
}

void sumPoly(int poly1[ITEMS], int poly2[ITEMS]) {
  int i, result[ITEMS];
  result[0] = poly1[0];
  for (i = 1; i <= poly1[0] + 1; i++) {
    result[i] = poly1[i] + poly2[i];
  }
  printPoly(result);
}
