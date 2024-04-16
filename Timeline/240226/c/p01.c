#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int staticArray[10] = {1, 2, 3, 4}, *pointer, number, *dynamicArray;
  pointer = staticArray;
  printf("%d %d\n", staticArray[0], *pointer);
  printf("%p %p\n", &staticArray[0], pointer);

  int i;
  for (i = 0; i < 10; i++) {
    printf("%d", staticArray[i]);
  }
  printf("\n");

  for (i = 0; i < 10; i++) {
    printf("%d", *(pointer + i));
  }
  printf("\n");

  while (1) {
    printf("請輸入動態陣列大小-->");
    scanf("%d", &number);
    if (number == 0)
      break;

    dynamicArray = (int *)malloc(sizeof(int) * number);
    for (i = 0; i < number; i++) {
      printf("輸入第 %d 個數字-->", i + 1);
      scanf("%d", &dynamicArray[i]);
    }

    for (i = 0; i < number; i++) {
      printf("%d ", *(dynamicArray + i));
    }
    printf("\n");

    free(dynamicArray);
  }
  return 0;
}
