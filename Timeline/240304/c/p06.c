#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatrix(int *arr, int size);

int main(int argc, char const *argv[]) {
  int A[3][3] = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
  int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int C[3][3] = {0};
  // Initialize Matrix C
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  printf("矩陣A：\n");
  printMatrix(&A[0][0], 3);
  printf("矩陣B：\n");
  printMatrix(&B[0][0], 3);
  printf("矩陣C：\n");
  printMatrix(&C[0][0], 3);

  return 0;
}

void printMatrix(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("\t|\t");
    for (int j = 0; j < size; j++) {
      printf("%d\t", *(arr + i * size + j));
    }
    printf("|\n");
  }
}
