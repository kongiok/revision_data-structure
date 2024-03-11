#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  int is, ie, js, je, ks, ke, ms, me, sta, addc, b, tr2, tc2, tr3, tc3, tr1, tc1, i, j, k, m, n;
  while (1)
  {
    printf("列開始："); scanf("%d", &is); printf("列結束："); scanf("%d", &ie);
    printf("行開始："); scanf("%d", &js); printf("行結束："); scanf("%d", &je);
    printf("層開始："); scanf("%d", &ks); printf("層結束："); scanf("%d", &ke);
    printf("四維開始："); scanf("%d", &ms); printf("四維結束："); scanf("%d", &me);
    printf("所佔空間："); scanf("%d", &b); if (b<1) break;
    tr3 = (je-js+1)*(ke-ks+1)*(me-ms+1); tr2=(me-ms+1)*(ke-ks+1); tc3=(ke-ks+1)*(je-js+1)*(ie-is+1); tc2=(je-js+1)*(ie-is+1); tc1=(ie-is+1); tr1=(me-ms+1);
    printf("tr3: %d, tr2: %d, tc3: %d, tc2: %d, tc1: %d, tr1: %d\n", tr3, tr2, tc3, tc2, tc1, tr1);
    printf("計算列："); scanf("%d", &i); printf("計算欄："); scanf("%d", &j);
    printf("計算層："); scanf("%d", &k); printf("計算四維："); scanf("%d", &m);
    // row majora
    addc=sta+((i-is)*tr3+(j-js)*tr2+(k-ks)*tr1+(m-ms))*b;
    printf("Row Major:\t[%d][%d][%d][%d]\t地址：%d\n", i, j, k, m, addc);
    // column major
    addc=sta+((m-ms)*tc3+(k-ks)*tc2+(j-js)*tc1+i-is)*b;
    printf("Column Major:\t[%d][%d][%d][%d]\t地址：%d\n", i, j, k, m, addc);
  }
  return 0;
}
