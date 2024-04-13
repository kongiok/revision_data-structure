#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float pow1(int x, int y) {
  float p = 1;
  int i;
  for (i = 1; i <= y; i++) {
    p *= x;
  }
  return p;
}

int main(int argc, char *argv[]) {
  int x, y;
  while (1) {
    printf("請輸入兩個數字(輸入 0 結束程式): ");
    scanf("%d %d", &x, &y);
    if (x == 0)
      break;
    printf("%d 的 %d 次方是: %f\n", x, y, pow1(x, y));
    printf("%d 的 %d 次方是（標準函數）: %f\n", x, y, pow(x, y));
  }
  return 0;
}
