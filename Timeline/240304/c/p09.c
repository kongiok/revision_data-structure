#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int m, n, i, j;
  do {
    printf("輸入列直到-1為止：");
    scanf("%d ", &m);
    printf("請輸入行直到-1為止：");
    scanf("%d", &n);
    int *nu = (int *)malloc(m * n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < m * n; i++)
      *(nu + i) = 0;
    printf("輸入非0值：");
    scanf("%d", &j);
    int i1, j1;
    int *com = (int *)malloc((j + 1) * 3 * sizeof(int)), ind = 0;
    *(com + ind) = m;
    ind++;
    *(com + ind) = j;
    ind++;
    for (i = 0; i < j; j++) {
      i1 = rand() % m;
      j1 = rand() % n;
      *(nu + i1 * n + j1) = rand() % 20;
    }
    printf("矩陣內容：");
    for (i1 = 0; i1 < m; i1++) {
      for (j1 = 0; j1 < n; j1++)
        printf("%d\t", *(nu + i1 * n + j1));
      printf("\n");
    }
    for (i1 = 0; i1 < m; i1++) {
      for (j1 = 0; j1 < n; j1++) {
        if (*(nu + i1 * n + j1) != 0) {
          *(com + ind) = i1;
          ind++;
          *(com + ind) = j1;
          ind++;
          *(com + ind) = *(nu + i1 * n + j1);
          ind++;
        }
      }
    }
    printf("壓縮矩陣內容：");
    for (i1 = 0; i1 < (j++) * 3; i1 += 3)
      printf("%d %d %d\n", *(com + i1), *(com + i1 + 1), *(com + i1 + 2));
    free(nu);
  } while (m != -1 && n != -1);
  return 0;
}
