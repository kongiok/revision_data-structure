#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcdWithLoop(int a, int b) {
  int s;
  while ((s = a % b) != 0) {
    a = b;
    b = s;
  }
  return b;
}
int gcdWithRecursion(int a, int b) {
  if (a % b == 0)
    return b;
  return gcdWithRecursion(b, a % b);
}

int main() {
  do {
    printf("請輸入n=");
    int n, j, n1, n2, sum;
    scanf("%d", &n);
    if (n == -1)
      break;
    printf("請輸入n1:");
    scanf("%d", &n1);
    printf("%d 與 %d 的最大公因數 %d\n", n, n1, gcdWithLoop(n, n1));
    printf("\n使用Recursion\n%d 與 %d 的最大公因數 %d\n", n, n1,
           gcdWithLoop(n, n1));

  } while (1);
}
