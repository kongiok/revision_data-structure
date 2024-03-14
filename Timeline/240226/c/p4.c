#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n, m, j, s;
  printf("輸入學生人數直到-1：");scanf("%d", &n);
  printf("輸入科目數：");scanf("%d", &m);srand(time(NULL));
  int stu[n][m + 2];
  while (n != -1 && m != -1) {
    for (i = 0; i < m; i++) {
      printf("成績%1d ", i + 1);
      printf("平均\t名次\n");
    }
    for (i = 0; i < n; i++) {
      for (j = 0, s = 0; j < m; j++) {
        s += stu[i][j] = rand() % 101;
        printf("%5d ", stu[i][j]);
      }
      stu[i][m] = (int)s / m;
      stu[i][m + 1] = 1;
      printf("%5d %5d\n", stu[i][m], stu[i][m + 1]);
    }
    // 比較學生名次
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        if (stu[i][m] > stu[j][m]) {
          stu[i][m + 1]++;
        } else if (stu[i][m] < stu[j][m]) {
          stu[j][m + 1]++;
        }
      }
    }
    for (i = 0; i < m; i++) {
      printf("成績%1d ", i + 1);
      printf("平均\t名次\n");
    }
    for (i = 0; i < n; i++) {
      for (j = 0, s = 0; j < m + 2; j++) {
        printf("%5d ", stu[i][j]);
      }
      printf("\n");
    }
    printf("輸入學生人數直到-1：");
    scanf("%d", &n);
    printf("輸入科目數：");
    scanf("%d", &m);
  }
}
