#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int is, ie, js, je, ks, ke, ms, me, sta, addc, b, tr2, tc2, tr3, tc3, tr1,
      tc1, i, j, k, m, n;
  while (1) {
    printf("列開始：");
    scanf("%d", &is);
    printf("列結束：");
    scanf("%d", &ie);
    printf("行開始：");
    scanf("%d", &js);
    printf("行結束：");
    scanf("%d", &je);
    printf("層開始：");
    scanf("%d", &ks);
    printf("層結束：");
    scanf("%d", &ke);
    printf("所佔空間：");
    scanf("%d", &b);
    if (b < 1)
      break;
    printf("起始位置：");
    scanf("%d", &sta);
    tr2 = (je - js + 1) * (ke - ks + 1);
    tc2 = (je - js + 1) * (ie - is + 1);
    printf("計算列：");
    scanf("%d", &i);
    printf("計算欄：");
    scanf("%d", &j);
    printf("計算層：");
    scanf("%d", &k);
    // row major
    addc = sta + ((i - is) * tr2 + (j - js) * (ke - ks + 1) + k - ks) * b;
    printf("Row Major:\t[%d][%d][%d]\tAddress: %d\n", i, j, k, addc);
    // column major
    addc = sta + ((k - ks) * tc2 + (j - js) * (ie - is + 1) + i - is) * b;
    printf("Column Major:\t[%d][%d][%d]\tAddress:%d\n", i, j, k, addc);
  }
  return 0;
}
