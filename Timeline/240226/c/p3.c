#include <stdio.h>
#include <string.h>

int main() {
  // int y=5, *yp, i;
  // yp=&y; printf("%d %d %p %p\n", y, *yp, &y, yp);// %p for address of
  // pointer. int a[15]={5,6,7,8,9}; printf("陣列a的位置：%p\n", a);
  // printf("陣列a[4]的位置：%p\n", &a[4]);
  // printf("%ld\n", (long)(&a[4] - &a[0])); // 4
  char s1[] = "Today is a sunny day.", s2[] = "This is a book.", s3[30], s4[40];
  strcpy(s3, s1);
  strcpy(s4, s2);
  printf("%s | %s | %s | %s\n", s1, s2, s3, s4);
  return 0;
}
