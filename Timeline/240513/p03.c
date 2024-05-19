#include <stdio.h>
#include <stdlib.h>
struct tree {
  int data;
  struct tree *left, *right;
};
typedef struct tree node;
typedef node *btree;
btree creat_tree(btree root, int val) {
  btree newnode, current, backup;
  newnode = (btree)malloc(sizeof(node));
  newnode->data = val;
  newnode->left = NULL;
  newnode->right = NULL;
  if (root == NULL) {
    root = newnode;
    return root;
  } else {
    for (current = root; current != NULL;) {
      backup = current;
      if (current->data > val)
        current = current->left;
      else
        current = current->right;
    }
    if (backup->data > val)
      backup->left = newnode;
    else
      backup->right = newnode;
  }
  return root;
}
void inorder(btree ptr) {
  if (ptr != NULL) {
    inorder(ptr->left);
    printf("[%2d]", ptr->data);
    inorder(ptr->right);
  };
}
void preorder(btree ptr) {
  if (ptr != NULL) {
    printf("[%2d]", ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
  };
}
void postorder(btree ptr) {
  if (ptr != NULL) {
    postorder(ptr->left);
    postorder(ptr->right);
    printf("[%2d]", ptr->data);
  };
}
int main() {
  int i, data[] = {5, 6, 24, 8, 12, 3, 17, 1, 9};
  btree ptr = NULL, root = NULL;
  for (i = 0; i < 9; i++)
    ptr = creat_tree(ptr, data[i]);
  printf("=======================\n");
  printf("中序走訪(完成排序):\n");
  inorder(ptr);
  printf("\n");
  printf("=======================\n");
  printf("前序走訪:\n");
  preorder(ptr);
  printf("\n");
  printf("=======================\n");
  printf("後序走訪:\n");
  postorder(ptr);
  printf("\n");
  system("pause");
  return 0;
}
