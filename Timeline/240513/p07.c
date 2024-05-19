
#include <stdio.h>
#include <stdlib.h>

struct tree {
  int data;
  struct tree *left, *right;
};
typedef struct tree node;
typedef node *btree;
btree create_tree(char seq[100], int index, int size);
int cond(char operator, int operandFirst, int operandSecond);
void preOrder(btree root);
void inOrder(btree root);
void postOrder(btree root);
int answer(btree root);

int main(void) {
  char inf1[] = {' ', '+', '*', '%', '6', '3', '9', '5'};
  char inf2[] = {' ', '+', '+', '+', '*', '%', '/', '*',
                 '1', '2', '3', '2', '6', '3', '2', '2'};
  btree root = (btree)malloc(sizeof(node));
  btree root2 = (btree)malloc(sizeof(node));
  root = create_tree(inf1, 1, 8);
  printf("=====二元運算數值運算範例 1 ：=====\n=========================\n");
  printf("前序遍歷：");
  preOrder(root);
  printf("\n中序遍歷：");
  inOrder(root);
  printf("\n後序遍歷：");
  postOrder(root);
  printf("\n運算結果：%d\n", answer(root));
  root2 = create_tree(inf2, 1, 16);
  printf("=====二元運算數值運算範例 2 ：=====\n=========================\n");
  printf("前序遍歷：");
  preOrder(root2);
  printf("\n中序遍歷：");
  inOrder(root2);
  printf("\n後序遍歷：");
  postOrder(root2);
  printf("\n運算結果：%d\n", answer(root2));
  return 0;
}

btree create_tree(char seq[100], int index, int size) {
  btree temp;
  if (seq[index] == 0 || index >= size) {
    return NULL;
  }
  temp = (btree)malloc(sizeof(node));
  temp->data = (int)seq[index];
  temp->left = NULL;
  temp->right = NULL;
  temp->left = create_tree(seq, 2 * index, size);
  temp->right = create_tree(seq, 2 * index + 1, size);
  return temp;
}

int cond(char operator, int operandFirst, int operandSecond) {
  switch (operator) {
  case '+':
    return operandFirst + operandSecond;
  case '-':
    return operandFirst - operandSecond;
  case '*':
    return operandFirst * operandSecond;
  case '/':
    return operandFirst / operandSecond;
  case '%':
    return operandFirst % operandSecond;
  default:
    return -1;
  }
}

void preOrder(btree root) {
  if (root == NULL) {
    return;
  }
  printf("%c", (char)root->data);
  preOrder(root->left);
  preOrder(root->right);
}
void inOrder(btree root) {
  if (root == NULL) {
    return;
  }
  inOrder(root->left);
  printf("%c", (char)root->data);
  inOrder(root->right);
}
void postOrder(btree root) {
  if (root == NULL) {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  printf("%c", (char)root->data);
}

int answer(btree root) {
  int first = 0, sec = 0;
  if (root->left == NULL && root->right == NULL) {
    return root->data - 48;
  }
  first = answer(root->left);
  sec = answer(root->right);
  return cond((char)root->data, first, sec);
}
