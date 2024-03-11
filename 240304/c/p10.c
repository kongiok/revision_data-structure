#include <stdio.h>
#define ITEMS 6

void printPoly(int poly[]);
void sumPoly(int poly1[ITEMS], int poly2[ITEMS]);

int main(int argc, char const *argv[]) {
  int polyA[ITEMS] = {4, 3, 7, 0, 6, 2};
  int polyB[ITEMS] = {4, 1, 5, 2, 0, 9};
  printf("多項式A：");
  printPoly(polyA);
  printf("多項式B：");
  printPoly(polyB);
  printf("多項式A + 多項式B：");
  sumPoly(polyA, polyB);
  return 0;
}

void printPoly(int poly[]) {
  int i, maxExp;
  maxExp = poly[0];
  for (int i = 1; i <= poly[0] + 1; i++) {
    maxExp--;
    if (poly[i] == 0)
      break;
    if ((maxExp + 1) == 0)
      printf(" %d", poly[i]);
    else
      printf(" %dX^%d", poly[i], maxExp + 1);
    if (maxExp >= 0)
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
