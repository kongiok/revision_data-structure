#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Matrix {
  char name;
  int row;
  int col;
  int *arr;
};

void printMatrix(struct Matrix *matrix);
int *createSpaceOfMatrix(struct Matrix matrix);
void insertValuesIntoMatrix(struct Matrix *matrix, int initialize);
struct Matrix multiplyMatrix(struct Matrix *A, struct Matrix *B);
void freeMatrix(struct Matrix *matrix, int size);

int main(int argc, char const *argv[]) {
  struct Matrix Collection[3];
  for (int i = 0; i < 2; i++) {
    switch (i) {
    case 0:
      Collection[i].name = 'A';
      break;
    case 1:
      Collection[i].name = 'B';
      break;
    case 2:
      Collection[i].name = 'C';
      break;
    }
    printf("請輸入矩陣%c的行及列，並用空格在數字間分隔：(x y)",
           Collection[i].name);
    scanf("%d %d", &Collection[i].row, &Collection[i].col);
    Collection[i].arr = createSpaceOfMatrix(Collection[i]);
    if (!Collection[i].arr) {
      printf("Memory allocation failed\n");
      return 1;
    }
    insertValuesIntoMatrix(&Collection[i], 0);
  }
  Collection[2].arr = NULL;
  Collection[2] = multiplyMatrix(&Collection[0], &Collection[1]);

  for (int i = 0; i < 3; i++) {
    struct Matrix *currentMatrix = &Collection[i];
    printf("陣列%d\n", i);
    printMatrix(currentMatrix);
  }

  freeMatrix(Collection, 3);
  return 0;
}

int *createSpaceOfMatrix(struct Matrix matrix) {
  return (int *)malloc(matrix.row * matrix.col * sizeof(int));
}
void insertValuesIntoMatrix(struct Matrix *matrix, int initialize) {
  if (initialize == 1)
    srand(time(NULL));
  else
    printf("請輸入矩陣%c的值：\n", matrix->name);
  for (int i = 0; i < matrix->col; i++) {
    // printf("Line %d\n", i + 1);
    for (int j = 0; j < matrix->row; j++) {
      int pos = i * matrix->col + j;
      if (initialize == 1) {
        *(matrix->arr + pos) = rand() % 20;
        printf("%d\t", *(matrix->arr + pos));
        continue;
      }
      scanf("%d", (matrix->arr + pos));
    }
    printf("\n");
  }
}

struct Matrix multiplyMatrix(struct Matrix *A, struct Matrix *B) {
  struct Matrix C;
  C.row = A->col;
  C.col = B->row;
  C.arr = createSpaceOfMatrix(C);
  int temp;
  if (C.row != C.col || C.row < 1 || C.col < 1) {
    printf("Matrix can multiply only if the row is equal to column and greater "
           "than 0\n");
    return (struct Matrix){0};
  }
  for (int i = 0; i < C.col; i++) {
    for (int j = 0; j < C.row; j++) {
      temp = 0;
      for (int k = 0; k < C.col; k++) {
        temp += *(A->arr + i * A->col + k) * *(B->arr + k * B->col + j);
      }
      *(C.arr + i * C.col + j) = temp;
    }
  }
  return C;
}
void printMatrix(struct Matrix *matrix) {
  for (int i = 0; i < matrix->col; i++) {
    printf("|\t");
    for (int j = 0; j < matrix->row; j++) {
      printf("%d\t", *(matrix->arr + i * matrix->col + j));
    }
    printf("|\n");
  }
}

void freeMatrix(struct Matrix *matrixArray, int size) {
  for (int i = 0; i < size; i++) {
    if (!matrixArray[i].arr)
      continue;
    free(matrixArray[i].arr);
    matrixArray[i].arr = NULL;
  }
}
