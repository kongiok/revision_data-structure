#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int array_static[10] = {1, 2, 3, 4}, *pointer, count, *array_dynamic;
  pointer = array_static;
  printf("%d %d\n", array_static[0], *pointer);
  pointer = array_static;
  printf("%p %p\n", &array_static[0], pointer);
  int i;
  for (i = 0; i < 10; i++)
    printf("%d ", array_static[i]);
  printf("\n");
  while (1) {
    printf("\nGive me the size of array: ");
    scanf("%d", &count);
    if (count <= 0)
      break;
    // Memory allocation alias dynamic memory allocation
    array_dynamic = (int *)malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
      printf("Give me the value of a[%d]: ", i + 1);
      scanf("%d", array_dynamic + i);
    }
    for (i = 0; i < count; i++) {
      printf("%d ", *(array_dynamic + i));
    }
  }
  return 0;
}
