#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main() {
  int front, rear, val, queue[MAX] = {0};
  front = rear = -1;
  while (rear < MAX && val != -1) {
    printf("Enter a value to add to the queue.\n");
    printf("[0] to remove a value,\t [-1] to exit\n");
    scanf("%d", &val);
    if (val == 0) {
      if (front == rear) {
        printf("Queue is full\n");
        break;
      }
      front = (front + 1) % MAX;
      printf("Got %d \n", queue[front]);
      queue[front] = 0;
    } else if (val != -1 && rear < MAX) {
      if (rear + 1 == front || (rear == MAX - 1 && front <= 0)) {
        printf("Queue is full\n");
        break;
      }
      rear = (rear + 1) % MAX;
      queue[rear] = val;
    }
  }
  if (front == -1) {
    front = rear = 0;
  } else {
    rear++;
  }
  queue[rear] = val;
}
