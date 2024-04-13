#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int num[2][3][3] = {
      {{33, 45, 67}, {23, 71, 56}, {55, 38, 66}},
      {{21, 9, 15}, {38, 69, 18}, {90, 101, 89}},
  };
  int min = num[0][0][0], *p = &num[0][0][0];
  printf("一般矩陣如下：\n");
  for (int i = 0; i < 2; i++) {
    printf("|\t\n");
    for (int j = 0; j < 3; j++) {
      printf("\t|\t");
      for (int k = 0; k < 3; k++) {
        printf("%d\t", num[i][j][k]);
      }
      printf("|\n");
    }
    printf("|\n");
  }
  printf("指標矩陣如下：\n");
  for (int i = 0; i < 2; i++) {
    printf("|\t\n");
    for (int j = 0; j < 3; j++) {
      printf("\t|\t");
      for (int k = 0; k < 3; k++) {
        printf("%d\t", *(p++));
      }
      printf("|\n");
    }
    printf("|\n");
  }
  // Calculate the minimum value
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (num[i][j][k] >= min) {
          continue;
        }
        min = num[i][j][k];
      }
    }
  }
  printf("最小值：%d\n", min);
  return 0;
}
