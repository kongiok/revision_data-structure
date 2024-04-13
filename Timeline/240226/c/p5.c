#include <stdio.h>

int main() {
  int is, ie, js, je, sta, addc, b, tr, tc, i, j;
  // 輸入列起始、列結束、行起始、行結束
  printf("輸入列起始-->");
  scanf("%d", &is);
  printf("輸入列結束-->");
  scanf("%d", &ie);
  printf("輸入行起始-->");
  scanf("%d", &js);
  printf("輸入行結束-->");
  scanf("%d", &je);
  // 輸入單位佔的空間
  printf("輸入單位佔的空間-->");
  scanf("%d", &b);
  // 計算起始位置
  sta = is * tc + js * b;
  while (b != 0) {
    // 計算列為主位址
    addc = sta + ((i - is) * tc + j - js) * b;
    printf("[%d][%d]列為主位址%d\n", i, j, addc);
    // 計算行為主位址
    addc = sta + ((j - js) * tr + i - is) * b;
    printf("[%d][%d]行為主位址%d\n", i, j, addc);
    // 輸入列起始、列結束、行起始、行結束
    printf("輸入列起始-->");scanf("%d", &is);
    printf("輸入列結束-->");scanf("%d", &ie);
    printf("輸入行起始-->");scanf("%d", &js);
    printf("輸入行結束-->");scanf("%d", &je);
    // 輸入單位佔的空間
    printf("輸入單位佔的空間-->");
    scanf("%d", &b);
    // 計算起始位置
    sta = is * tc + js * b;
  }
  return 0;
}
