#include <stdio.h>

int main() {
  int rowStart, rowEnd, colStart, colEnd, byteSize, baseAddress, targetRow,
      targetCol;

  printf("請輸入起始列：");
  scanf("%d", &rowStart);

  printf("請輸入終止列：");
  scanf("%d", &rowEnd);

  printf("請輸入起始行：");
  scanf("%d", &colStart);

  printf("請輸入終止行：");
  scanf("%d", &colEnd);

  printf("請輸入每個元素的字節大小：");
  scanf("%d", &byteSize);

  while (byteSize != 0) {
    printf("請輸入基址：");
    scanf("%d", &baseAddress);

    int totalRows = rowEnd - rowStart + 1; // 總列數
    int totalCols = colEnd - colStart + 1; // 總行數

    printf("請輸入目標列：");
    scanf("%d", &targetRow);

    printf("請輸入目標行：");
    scanf("%d", &targetCol);

    // 行優先（Row major）
    int address = baseAddress + ((targetRow - rowStart) * totalCols +
                                 (targetCol - colStart)) *
                                    byteSize;
    printf("[%d][%d] 的記憶體地址為： %d\n", targetRow, targetCol, address);

    // 列優先（Column major）
    address = baseAddress +
              ((targetCol - colStart) * totalRows + (targetRow - rowStart)) *
                  byteSize;
    printf("[%d][%d] 的記憶體地址為： %d\n", targetRow, targetCol, address);

    printf("請輸入起始列：");
    scanf("%d", &rowStart);

    printf("請輸入終止列：");
    scanf("%d", &rowEnd);

    printf("請輸入起始行：");
    scanf("%d", &colStart);

    printf("請輸入終止行：");
    scanf("%d", &colEnd);

    printf("請輸入每個元素的字節大小：");
    scanf("%d", &byteSize);
  }
  return 0;
}
