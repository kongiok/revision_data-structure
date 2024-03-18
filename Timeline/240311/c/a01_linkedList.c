#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int data);
Node *createMultipleNodes(int indexStart, int length);
void printNodes(Node *head);
void freeNodes(Node *head);
Node *getNode(Node *start, int data);

int main() {
  Node *head = createMultipleNodes(1, 5);
  printNodes(head);
  Node *X = getNode(head, 3);
  Node *Y = createNode(87);
  Y->next = X->next;
  X->next = Y;
  printf("=======================\nAfter Changed.\n");
  printNodes(head);
  freeNodes(head);
}

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

Node *createMultipleNodes(int indexStart, int length) {
  Node *head = NULL;
  Node *current = NULL;
  for (int i = indexStart; i < length; i++) {
    Node *newNode = createNode(i);
    if (current == NULL) {
      head = newNode;
      current = head;
    } else {
      current->next = newNode;
      current = newNode;
    }
  }
  return head;
}

void printNodes(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
}

void freeNodes(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
}

Node *getNode(Node *start, int data) {
  Node *current = start;
  while (current != NULL) {
    if (current->data == data) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}
