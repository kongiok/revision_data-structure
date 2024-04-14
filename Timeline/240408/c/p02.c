#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <time.h>

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

void pushItemToStackWithArray(int sk[], int lengthStack, int val) {
  if (top >= lengthStack - 1) {
    printf("Stack Overflow\n");
    return;
  }
  ++top;
  sk[top] = val;
}
int main() {
  int card[52], stack[52] = {0}, i, st;
  char ascVal;
  srand((unsigned)time(NULL));
  for (i = 0; i < 52; i++) {
    card[i] = i + 1;
  }
  printf("[Poker] 洗牌中⋯⋯\n");
  int k = 0;
  while (k < 30) {
    for (i = 0; i < 51; i++)
      for (int j = i + 1; j < 52; j++)
        if (rand() % 52 == 2) {
          swapBetweenTwoNumbers(&card[i], &card[j]);
        }
    k++;
  }
  i = 0, top = -1;
  while (i != 52) {
    pushItemToStackWithArray(stack, 52, card[i]);
    i++;
  }
  printf("[Poker] 逆時針發牌\n");
  printf("[Poker] 顯示各家牌子\n東家\t北家\t西家\t南家\n");
  printf("=========================\n");
  while (top >= 0) {
    st = stack[top] / 13;
    switch (st) {
    case 0:
      ascVal = 'S';
      break;
    case 1:
      ascVal = 'H';
      break;
    case 2:
      ascVal = 'D';
      break;
    case 3:
      ascVal = 'C';
      break;
    }
    printf("[%c%3d]\t", ascVal, stack[top] % 13 + 1);
    if (top % 4 == 0) {
      printf("\n");
    }
    top--;
  }
}
