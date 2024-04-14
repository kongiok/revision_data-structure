#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode {
  int data;
  struct stackNode *next;
} stn;

typedef stn *ln_s;
ln_s top_1 = NULL;
int isEmpty() {
  if (top_1 == NULL)
    return 1;
  return 0;
}

void pushItemToStack(int data) {
  ln_s newNode = (ln_s)malloc(sizeof(stn));
  newNode->data = data;
  newNode->next = top_1;
  top_1 = newNode;
}

int popItemFromStack() {
  if (isEmpty()) {
    printf("Stack Underflow\n");
    return -1;
  }
  ln_s temp = top_1;
  top_1 = top_1->next;
  int popped = temp->data;
  free(temp);
  return popped;
}

int main() {
  int val, i;
  do {
    printf("輸入 [1] 以推入 Stack ，輸入 [0] 以彈出，輸入 [-1] 以結束。");
    scanf("%d", &i);
    switch (i) {
    case -1:
      break;
    case 1:
      printf("輸入一個數字: ");
      scanf("%d", &val);
      pushItemToStack(val);
      break;
    case 0:
      printf("彈出的數字: %d\n", popItemFromStack());
      break;
    }
  } while (i != -1);
  printf("\n=========================\n");
  while (!isEmpty()) {
    printf("\n從 Stack 彈出 %d", popItemFromStack());
  }
  printf("\n=========================\n");
}
