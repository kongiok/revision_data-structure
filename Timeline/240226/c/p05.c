#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int studentCount, subjectCount, i, j, sum;
  printf("請輸入學生人數（輸入 -1 結束）-->");
  scanf("%d", &studentCount);
  printf("請輸入科目數量（輸入 -1 結束）-->");
  scanf("%d", &subjectCount);
  srand(time(NULL));

  int scores[studentCount][subjectCount + 2]; // 學生成績陣列，包括平均分和名次

  while (studentCount != -1 && subjectCount != -1) {
    for (i = 0; i < subjectCount; i++)
      printf("科目 %1d ", i + 1);
    printf("平均 名次\n");

    for (i = 0; i < studentCount; i++) {
      for (j = 0, sum = 0; j < subjectCount; j++) {
        sum += scores[i][j] = rand() % 101;
        printf("%5d ", scores[i][j]);
      }
      scores[i][subjectCount] = sum / subjectCount; // 計算平均分
      scores[i][subjectCount + 1] = 1;              // 初始化名次
      printf("%5d %5d\n", scores[i][subjectCount], scores[i][subjectCount + 1]);
    }

    // 計算名次
    for (i = 0; i < studentCount; i++) {
      for (j = i + 1; j < studentCount; j++) {
        if (scores[i][subjectCount] > scores[j][subjectCount])
          scores[j][subjectCount + 1]++;
        else if (scores[i][subjectCount] < scores[j][subjectCount])
          scores[i][subjectCount + 1]++;
      }
    }

    for (i = 0; i < subjectCount; i++)
      printf("科目 %1d ", i + 1);
    printf("平均 名次\n");

    for (i = 0; i < studentCount; i++) {
      for (j = 0; j < subjectCount + 2; j++)
        printf("%5d ", scores[i][j]);
      printf("\n");
    }

    printf("請輸入學生人數（輸入 -1 結束）-->");
    scanf("%d", &studentCount);
    printf("請輸入科目數量（輸入 -1 結束）-->");
    scanf("%d", &subjectCount);
  }
  return 0;
}
