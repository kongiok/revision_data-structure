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
void print_post(btree r);
btree search_tree(btree ptr, int val);
int main() {
  int i, data[] = {7, 1, 4, 2, 8, 13, 12, 11, 15, 9, 5}, val;
  btree root = NULL, ptr = NULL;
  for (i = 0; i < 11; i++) {
    ptr = create_tree(ptr, data[i]);
    printf("[%2d] ", data[i]);
  }
  printf("\n");
  while (1) {
    printf("請輸入搜尋值：");
    scanf("%d", &val);
    if (val == -1) {
      break;
    }
    search_tree(ptr, val);
  }
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
void print_post(btree r) {
  if (r == NULL) {
    return;
  }
  print_post(r->left);
  print_post(r->right);
  printf("%d ", r->data);
}

btree search_tree(btree ptr, int val) {
  int i = 1;
  while (1) {
    if (ptr == NULL) {
      printf("找不到 %d\n", val);
      return NULL;
    }
    if (val == ptr->data) {
      printf("找到 %d, 找了 %3d 次\n", val, i);
      return ptr;
    }
    if (val < ptr->data)
      ptr = ptr->left;
    else
      ptr = ptr->right;
    i++;
  }
}
