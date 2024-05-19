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
void inOrder(btree ptr);
btree delete_tree(btree root, int val);
btree findMin(btree root);
btree findMax(btree root);

int main() {
  int i, data[] = {7, 1, 4, 2, 8, 13, 12, 11, 15, 9, 5}, val;
  btree root = NULL, ptr = NULL;
  printf("原始陣列內容：\n");
  for (i = 0; i < 11; i++) {
    ptr = create_tree(ptr, data[i]);
    printf("[%2d] ", data[i]);
  }
  printf("\n");
  while (1) {
    inOrder(ptr);
    printf("\n");
    printf("請輸入刪除值：");
    scanf("%d", &val);
    if (val == -1) {
      break;
    }
    ptr = delete_tree(ptr, val);
    if (ptr == NULL) {
      printf("找不到 %d\n", val);
      continue;
    }
    printf("已刪除！\n");
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
      printf("找不到 %d，正在加入⋯⋯\n", val);
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

void inOrder(btree ptr) {
  if (ptr == NULL) {
    return;
  }
  inOrder(ptr->left);
  printf("[%2d] ", ptr->data);
  inOrder(ptr->right);
}

btree delete_tree(btree root, int val) {
  if (root == NULL) {
    return root;
  }
  if (root->left == NULL) {
    btree temp = root->right;
    free(root);
    return temp;
  }
  if (root->right == NULL) {
    btree temp = root->left;
    free(root);
    return temp;
  }
  btree temp = findMin(root->right);
  root->data = temp->data;
  root->right = delete_tree(root->right, temp->data);
  return root;
}

btree findMin(btree root) {
  if (root == NULL) {
    return NULL;
  }
  if (root->left == NULL) {
    return root;
  }
  return findMin(root->left);
}
btree findMax(btree root) {
  if (root == NULL) {
    return NULL;
  }
  if (root->right == NULL) {
    return root;
  }
  return findMax(root->right);
}
