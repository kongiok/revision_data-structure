#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  int m, n, i, j, i1, j1, cnt, ind;
  int *nu, *com;

  printf("請輸入矩陣的列數(-1退出)：");
  scanf("%d", &m);
  printf("請輸入矩陣的行數(-1退出)：");
  scanf("%d", &n);
  srand(time(NULL));

  while (m != -1 || n != -1) {
    printf("請輸入要產生的隨機數數量：");
    scanf("%d", &cnt);

    nu = (int *)malloc(m * n * sizeof(int));
    for (i = 0; i < m * n; i++)
      nu[i] = 0;

    com = (int *)malloc((cnt + 1) * 3 * sizeof(int));
    ind = 0;
    for (i = 0; i < (cnt + 1) * 3; i++)
      com[i] = 0;
    com[ind] = m;
    ind++;
    com[ind] = n;
    ind++;
    com[ind] = cnt;
    ind++;

    printf("矩陣維度和隨機數數量：\n");
    for (i = 0; i < (cnt + 1) * 3; i += 3) {
      printf("%d %d %5d\n", com[i], com[i + 1], com[i + 2]);
    }

    for (i = 0; i < cnt; i++) {
      i1 = rand() % m;
      j1 = rand() % n;
      nu[i1 * n + j1] = rand() % 20 + 1;
      printf("(%d,%d) 賦值 --> %d\n", i1, j1, nu[i1 * n + j1]);
    }

    printf("完整矩陣內容：\n");
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        printf("%5d\t", nu[i * n + j]);
      }
      printf("\n");
    }

    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        if (nu[i * n + j] != 0) {
          com[ind] = i;
          ind++;
          com[ind] = j;
          ind++;
          com[ind] = nu[i * n + j];
          ind++;
        }
      }
    }

    printf("非零元素及其位置：\n");
    for (i = 0; i < (cnt + 1) * 3; i += 3) {
      printf("%d %d %5d\n", com[i], com[i + 1], com[i + 2]);
    }

    free(nu);
    free(com);

    printf("請輸入矩陣的列數(-1退出)：");
    scanf("%d", &m);
    printf("請輸入矩陣的行數(-1退出)：");
    scanf("%d", &n);
  }
  return 0;
}
