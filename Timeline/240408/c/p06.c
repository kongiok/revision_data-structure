#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multiplyWithRecursion(int i, int j) {
  if (j == 1)
    return i;
  else
    return i + multiplyWithRecursion(i, j - 1);
}
int multiplyWithoutRecursion(int i, int j) { return i * j; }

int main() {
  do {
    printf("請輸入n=");
    int n, j, n1, n2, sum;
    scanf("%d", &n);
    if (n == -1)
      break;
    printf("請輸入n1:");
    scanf("%d", &n1);
    printf("%d 與 %d 的商 %d\n", n, n1, multiplyWithRecursion(n, n1));
    printf("\n%d 與 %d 的商 %d\n", n, n1, multiplyWithRecursion(n, n1));
  } while (1);
}
