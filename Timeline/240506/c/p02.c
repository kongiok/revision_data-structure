#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct QueueNode {
  int data;
  struct QueueNode *next;
} QueueNode;
typedef QueueNode *QueueLink;
QueueLink front = NULL, rear = NULL;

void enqueue(int value);
int dequeue(int ac);
void printQueue();
int main() {
  int temp, item, ch = 0;
  printf("以鏈結串列實作佇列\n");
  printf("=========================");
  do {
    if (ch != 0) {
      printQueue();
    }
    printf("[1]以加入\t[2]以取出\t[-1]以退出。\n");
    scanf("%d", &ch);
    if (ch == -1) {
      break;
    }
    if (ch != 1 && ch != 2) {
      printf("輸入錯誤，請重新輸入\n");
      continue;
    }
    if (ch == 1) {
      printf("請輸入一個數字：");
      scanf("%d", &item);
      enqueue(item);
      continue;
    }
    if (ch == 2) {
      temp = dequeue(1);
      printf("從雙向佇列前端取出的數字是：%d\n", temp);
      temp = dequeue(2);
      printf("從雙向佇列後端取出的數字是：%d\n", temp);
    }
  } while (ch != -1);

  return 0;
}

void enqueue(int value) {
  QueueLink temp;
  temp = (QueueLink)malloc(sizeof(QueueNode));
  temp->data = value;
  temp->next = NULL;
  if (rear == NULL) {
    front = temp;
  } else {
    rear->next = temp;
  }
  rear = temp;
}

int dequeue(int ac) {
  int value;
  QueueLink temp, start, prev;
  if (ac == 1) {
    if (front == NULL) {
      return -1;
    }
    if (front == rear) {
      rear = NULL;
    }
    value = front->data;
    front = front->next;
    return value;
  }
  if (ac == 2) {
    if (rear == NULL) {
      return -1;
    }
    start = front;
    value = rear->data;
    // 找尋最尾端節點的前一個節點。
    temp = front;
    while (temp != rear) {
      prev = temp;
      temp = temp->next;
    }
    free(temp);
    rear = prev;
    rear->next = NULL;
    if ((front->next == NULL) || (rear->next == NULL)) {
      front = rear = NULL;
    }
    return value;
  }
  return -1;
}

void printQueue() {
  QueueLink temp;
  temp = front;
  printf("Queue: \n");
  while (temp != NULL) {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
