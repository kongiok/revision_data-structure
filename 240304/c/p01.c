#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {
  int a[5][6]={{1,2},{3},{4,5,6},{7,8,9,10}}, *p, i, j;
  for(i=0; i<5; i++){
    for(j=0; j<6; j++){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  p= &a[0][0];
  printf("\n");
  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 6; j++)
    {
      printf("%d ", *(p++));
    }
    printf("\n");
  }
  
}