#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x, r, n;
  while (1) {
    printf("輸入一個數字，或 [-1] 以退出：");
    scanf("%d", &x);
    if (x == -1)
      break;

    int p[x + 1][x + 1];

    for (r = 0; r <= x; r++) {
      p[r][0] = 1;
      for (n = 1; n <= r; n++) {
        p[r][n] = p[r][n - 1] * (r - n + 1) / n;
      }
    }
    for (r = 0; r <= x; r++) {
      for (n = 0; n <= r; n++) {
        printf("%d ", p[r][n]);
      }
      printf("\n");
    }
  }
  return 0;
}
