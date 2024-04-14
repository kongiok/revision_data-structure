#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **createSparseMatrix(int m, int n, int cnt);
void printSparseMatrix(int **nu, int *com);
void freeSparseMatrix(int **nu, int *com);

int main()
{
  int m, n, cnt;
  int **nu, *com;

  do
  {
    printf("請輸入矩陣的列數(-1退出)：");
    scanf("%d", &m);
    printf("請輸入矩陣的行數(-1退出)：");
    scanf("%d", &n);
    srand(time(NULL));
    printf("請輸入要產生的隨機數數量：");
    scanf("%d", &cnt);
    // Create Matrix
    nu = createSparseMatrix(m, n, cnt);
    printSparseMatrix(nu, com);
    freeSparseMatrix(nu, com);
  } while (m != -1 || n != -1);
  return 0;
}

int **createSparseMatrix(int col, int row, int cnt)
{
  int **table;
  if (col <= 0 || row <= 0 || cnt <= 0)
  {
    printf("輸入的矩陣維度或隨機數數量錯誤！\n");
    return NULL;
  }
  table = (int**)malloc(cnt*sizeof(int*));
  for(int i=0; i<cnt; i++){
    table[i] = (int *)malloc(3*sizeof(int));
  }
  int i, j, k, t;
  table[0][0] = col;
  table[0][1] = row;
  table[0][2] = cnt;
  for (i = 1; i <= cnt; i++)
  {
    table[i][0] = rand() % col;
    table[i][1] = rand() % row;
    table[i][2] = rand() % 100;
  }
  return table;
}

void printSparseMatrix(int **nu, int *com)
{
  int i, j;
  printf("矩陣維度和隨機數數量：\n");
  for (i = 0; i < (com[2] + 1) * 3; i += 3)
  {
    printf("%d %d %5d\n", com[i], com[i + 1], com[i + 2]);
  }
  printf("完整矩陣內容：\n");
  for (i = 0; i < com[0]; i++)
  {
    for (j = 0; j < com[1]; j++)
    {
      printf("%5d\t", nu[i][j]);
    }
    printf("\n");
  }
}

void freeSparseMatrix(int **nu, int *com)
{
  int i;
  for (i = 0; i < com[0]; i++)
    free(nu[i]);
  free(nu);
  free(com);
}
