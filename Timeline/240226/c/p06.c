// 算並輸出指定位置的位址
#include <stdio.h>

int main() {
  int is, ie, js, je, sta, addc, b, tr, tc, i, j;

  printf("輸入列起始-->");
  scanf("%d", &is);

  printf("輸入列結束-->");
  scanf("%d", &ie);

  printf("輸入行起始-->");
  scanf("%d", &js);

  printf("輸入行結束-->");
  scanf("%d", &je);

  printf("輸入單位佔的空間-->");
  scanf("%d", &b);

  while (b != 0) {
    printf("輸入起始位置");
    scanf("%d", &sta);

    tr = ie - is + 1; // 計算行數
    tc = je - js + 1; // 計算列數

    printf("輸入計算列-->");
    scanf("%d", &i);

    printf("輸入計算欄-->");
    scanf("%d", &j);

    // row major
    addc = sta + ((i - is) * tc + (j - js)) * b;
    printf("[%d][%d]列為主位址%d\n", i, j, addc);

    // col major
    addc = sta + ((j - js) * tr + (i - is)) * b;
    printf("[%d][%d]行為主位址%d\n", i, j, addc);

    printf("輸入列起始-->");
    scanf("%d", &is);

    printf("輸入列結朿-->");
    scanf("%d", &ie);

    printf("輸入行起始-->");
    scanf("%d", &js);

    printf("輸入行結束-->");
    scanf("%d", &je);

    printf("輸入單位佔的空間-->");
    scanf("%d", &b);
  }
  return 0;
}
