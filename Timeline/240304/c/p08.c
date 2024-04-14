#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int arrA[4][3] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 11}, {13, 14, 15}},
      arrB[3][4] = {0};
  int i, j;
  printf("請輸入矩陣內容\n");

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++)
      printf("%d\t", arrA[i][j]);
    printf("\n");
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++)
      arrB[i][j] = arrA[j][i];
  }
  printf("轉置後的矩陣：\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++)
      printf("%d\t", arrB[i][j]);
    printf("\n");
  }
  return 0;
}
