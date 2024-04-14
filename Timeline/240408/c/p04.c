#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int i) {
  int sum;
  if (i == 0)
    return 1;
  return i * fact(i - 1);
}

int fib(int n) {
  if (n == 0)
    return 0;
  if (n == 1 || n == 2)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

void hanoi(int n, int p1, int p2, int p3) {
  if (n == 1)
    printf("%d 環從 %d 移到 %d\n", n, p1, p3);
  else {
    hanoi(n - 1, p1, p2, p3);
    printf("%d 環從 %d 移到 %d\n", n, p1, p3);
    hanoi(n - 1, p2, p3, p1);
  }
}

int main() {
  do {
    printf("請輸入n=");
    int n, j, n1, n2, sum;
    scanf("%d", &n);
    if (n == -1)
      break;
    for (int i = 0; i <= n; i++) {
      for (int j = i; j > 0; j--) {
        sum *= j;
        printf("%d! = %3d\n", i, sum);
        sum = 1;
      }
    }
    for (int i = 0; i <= n; i++)
      printf("%d!值為 %3d\n", i, fact(i));
    for (int i = 0; i <= n; i++) {
      switch (i) {
      case 0:
        sum = 0;
        break;
      case 1:
      case 2:
        n1 = n2 = sum = 1;
        break;
      default:
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
        break;
      }
    }
    printf("第 %d 項費氏數列為 %d\n", n, fib(n));
    for (int i = 0; i <= n; i++)
      printf("第 %d 項費氏數列為 %d\n", i, fib(i));
    hanoi(n, 1, 2, 3);
  } while (1);
}
