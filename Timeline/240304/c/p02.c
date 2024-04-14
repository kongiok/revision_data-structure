#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int a[3][5] = {15 * 0}, *p;
  p = &a[0][0];
  printf("陣列a[0][0]的位址：%p, %p", a, p);
  printf("陣列a[2][3]的位址：%p", p + 13);
  printf("陣列a[2][3]的位址：%p", &a[2][3]);
  int arr[2][2], sum;
  printf("Matrix \n");
  printf("|a1\tb1|\n|a2\tb2|\n");
  printf("a1:");
  scanf("%d", &arr[0][0]);
  printf("b1:");
  scanf("%d", &arr[0][1]);
  printf("a2:");
  scanf("%d", &arr[1][0]);
  printf("b2:");
  scanf("%d", &arr[1][1]);
  sum = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
  printf("|%d\t%d|\n|%d\t%d|\nSum=%d", arr[0][0], arr[0][1], arr[1][0],
         arr[1][1], sum);
  return 0;
}
