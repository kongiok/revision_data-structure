#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int startNum, size, startAddress, locationNum, targetAddress;

  while (1) {
    printf("請輸入起始編號（輸入 0 結束）：");
    scanf("%d", &startNum);
    if (startNum == 0)
      break;

    printf("請輸入每個項目的大小：");
    scanf("%d", &size);

    printf("請輸入起始記憶體地址（十六進位）：");
    scanf("%x", &startAddress);

    printf("請輸入目標項目的編號：");
    scanf("%d", &locationNum);

    targetAddress = startAddress + (locationNum - startNum) * size;
    printf("編號 %d 的項目地址為：0x%X\n", locationNum, targetAddress);
  }

  return 0;
}
