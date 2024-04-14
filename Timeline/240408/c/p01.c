#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int stack[MAX];
int top = -1;

int stackIsEmpty() {
  if (top == -1) {
    return 1;
  }
  return 0;
}

int pushItemToStack(int data) {
  if (top >= MAX) {
    printf("Stack Overflow\n");
    return 0;
  }
  stack[++top] = data;
  return 1;
}

int popItemFromStack() {
  if (stackIsEmpty()) {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack[top--];
}

void swapBetweenTwoNumbers(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void pushItemToStackWithArray(int sk[], int ca_max, int val) {
  if (top >= ca_max - 1) {
    printf("Stack Overflow\n");
    return;
  }
  ++top;
  sk[top] = val;
}

int main() {
  int val, i;
  do {
    printf("輸入 [1] 來推入堆疊，輸入 [0] 來彈出堆疊，輸入 [-1] 來停止操作");
    scanf("%d", &i);
    switch (i) {
    case -1:
      break;
    case 0:
      printf("彈出了數字: %d\n", popItemFromStack());
      break;
    case 1:
      printf("輸入要推入的數字: ");
      scanf("%d", &val);
      pushItemToStack(val);
      break;
    }
  } while (i != -1);
  printf("\n=========================\n");
  while (!stackIsEmpty()) {
    printf("彈出了 %d\n", popItemFromStack());
  }
  printf("\n=========================\n");
}
