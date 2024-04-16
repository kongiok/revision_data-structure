// 計算一個整數的另一個整數次方
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float pow1(int x, int y) {
  float p = 1;
  int i;
  for (i = 1; i <= y; i++)
    p *= x;
  return p;
}

int main(int argc, char *agv[]) {
  int x, y;
  while (1) {
    printf("give 2 number");
    scanf("%d %d", &x, &y);
    if (x == 0)
      break;
    printf("%d^%d=%f", x, y, pow1(x, y));
    printf("%d^%d=%f\n", x, y, pow(x, y));
  }
}
