#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ITEMS 6

void PrintPoly(int Poly[], int items);
void PolySum(int Poly1[ITEMS], int Poly2[ITEMS]);

int main(int argc, char *argv[]) {
    int PolyA[ITEMS] = {4, 3, 7, 0, 6, 2};
    int PolyB[ITEMS] = {4, 1, 5, 2, 0, 9};
    
    printf("多項式A==>"); PrintPoly(PolyA, ITEMS);
    printf("多項式B==>"); PrintPoly(PolyB, ITEMS);
    printf("A+B => ");  PolySum(PolyA, PolyB);

    return 0;
}

void PrintPoly(int Poly[], int items) {
    int i, MaxExp;
    MaxExp = Poly[0];
    for (i = 1; i <= Poly[0] + 1; i++) {
        MaxExp--;
        if (Poly[i] != 0) {
            if ((MaxExp + 1) != 0)
                printf(" %dX^%d ", Poly[i], MaxExp + 1);
            else
                printf(" %d", Poly[i]);
            if (MaxExp >= 0) printf("%c", '+');
        }
    }
    printf("\n");
}

void PolySum(int Poly1[ITEMS], int Poly2[ITEMS]) {
    int i, result[ITEMS];
    result[0] = Poly1[0]; // 假設第一項是最高次項的係數，且兩個多項式的最高次數相同
    for (i = 1; i <= Poly1[0] + 1; i++) result[i] = Poly1[i] + Poly2[i]; 
    PrintPoly(result, ITEMS);
}