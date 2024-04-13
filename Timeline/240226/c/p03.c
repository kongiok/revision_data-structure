#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int num = 5, *numPtr, i;
  numPtr = &num;
  printf("%d %d %p %p\n", num, *numPtr, &num, numPtr);

  int array[15] = {5, 6, 7, 8, 9};
  printf("陣列 array 的地址--> %p，", array);
  printf("陣列元素 array[4] 的地址--> %p\n", &array[4]);

  for (i = 0; i < 5; i++)
    printf("%d ", array[i]);
  printf("\n");
  numPtr = array;
  for (i = 0; i < 5; i++)
    printf("%d ", *(numPtr + i));
  printf("\n");
  numPtr = &array[0];
  for (i = 0; i < 5; i++)
    printf("%d ", *(numPtr + i));
  printf("\n");

  char str1[] = "今天是晴天。", str2[] = "這是一本書。", str3[30], str4[40];
  strcpy(str3, str1);
  strcpy(str4, str2);
  printf("%s | %s | %s | %s\n", str1, str2, str3, str4);
  printf("%lu %lu\n", strlen(str1), strlen(str2));

  char str5[] = {'h', 'e', 'l', 'l', 'o', '\0'}, str6[] = "hello";
  printf("%s | %s | %lu | %lu\n", str5, str6, strlen(str5), strlen(str6));
  return 0;
}
