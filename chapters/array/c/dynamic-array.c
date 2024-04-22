#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr = (int *)malloc(sizeof(int));
  int capacity = 0;
  printf("輸入 Array 的大小：");
  scanf("%d", &capacity);
  arr = (int *)realloc(arr, capacity * sizeof(int));
  for (int i = 0; i < capacity; i++) {
    printf("輸入第 %d 個元素：", i);
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < capacity; i++) {
    printf("%d ", arr[i]);
  }
  free(arr);
  return 0;
}
