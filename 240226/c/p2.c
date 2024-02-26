#include <stdlib.h>
#include <stdio.h>

int main(){
  int n, s, st, loc, addr;
  while (1)
  {
    printf("陣列位置： "); scanf("%d", &n); if(n == 0) break;// 500
    printf("元素大小： "); scanf("%d", &s);// 4
    printf("陣列基本位置： "); scanf("%x", &st);// 0x1000
    printf("陣列計算位置： "); scanf("%d", &loc);// 100
    addr=st+(loc-n)*s; printf("陣列位置 %d 的記憶體位置是 %d\n", loc, addr);
  }
}