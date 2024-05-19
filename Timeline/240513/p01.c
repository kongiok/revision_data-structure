#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

struct tree {
  int data;
  struct tree *left, *right;
};
typedef struct tree node;
typedef node *btree;
btree create_tree(btree root, int val);
void print_tin(btree r);
void print_pre(btree r);
int main() {
  int i, data[] = {5, 6, 24, 8, 12, 3, 17, 1, 9};
  btree root = NULL, ptr = NULL;
  for (i = 0; i < 9; i++) {
    ptr = create_tree(ptr, data[i]);
  }
  printf("左子樹：\n");
  root = ptr->left;
  while (root != NULL) {
    printf("%d\n", root->data);
    root = root->left;
  }
  printf("-------------------------\n");
  printf("右子樹：\n");
  root = ptr->right;
  while (root != NULL) {
    printf("%d\n", root->data);
    root = root->right;
  }
  printf("-------------------------\n");
  return 0;
}

btree create_tree(btree root, int val) {
  btree newNode, current, back;
  newNode = (btree)malloc(sizeof(node));
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;
  if (root == NULL) {
    root = newNode;
    return root;
  }
  for (current = root; current != NULL;) {
    back = current;
    if (val < current->data)
      current = current->left;
    else
      current = current->right;
  }
  if (val < back->data)
    back->left = newNode;
  else
    back->right = newNode;
  return root;
}

void print_tin(btree r) {
  if (r == NULL)
    return;
  print_tin(r->left);
  printf("%d ", r->data);
  print_tin(r->right);
}
void print_pre(btree r) {
  if (r == NULL) {
    return;
  }
  printf("%d ", r->data);
  print_pre(r->left);
  print_pre(r->right);
}
