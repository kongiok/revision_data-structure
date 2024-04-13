#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int prime(int x1) {
  if (x1 < 2)
    return 1;
  int i;
  for (i = 2; i < x1; i++) {
    if (x1 % i == 0)
      return 1;
  }
  return 0;
}

int prime1(int x1) {
  if (x1 < 2)
    return 1;
  int i, qq = (int)sqrt(x1);
  for (i = 2; i <= qq; i++) {
    if (x1 % i == 0)
      return 1;
  }
  return 0;
}

void all_p(int x1) {
  int i;
  for (i = 2; i <= x1; i++) {
    if (prime(i) == 0)
      printf("%d ", i);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int x;
  while (1) {
    printf("Enter a number (0 to exit): ");
    scanf("%d", &x);
    if (x == 0)
      break;
    if (prime(x) == 0)
      printf("%d is prime.\n", x);
    else
      printf("%d is not prime.\n", x);
    if (prime1(x) == 0)
      printf("%d is prime (optimized).\n", x);
    else
      printf("%d is not prime (optimized).\n", x);
    all_p(x);
  }
  return 0;
}
