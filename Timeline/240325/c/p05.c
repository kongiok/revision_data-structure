#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeEmp {
  int num;
  char name[10];
  int sal;
  struct nodeEmp *linkRight;
  struct nodeEmp *linkLeft;
} nodeEmp, *linkEmp;
linkEmp find_node(linkEmp head, int num);
linkEmp createEmployee(int num, char *name, int sal);
linkEmp insert_node(linkEmp head, linkEmp ptr, int num, int sal, char name[10]);
linkEmp delete_node(linkEmp head, linkEmp del);

int main() {
  linkEmp head = NULL, newNode, left, ptr, temp;
  int pos, newNum, newSal;
  int data[12][2] = {1001, 32367, 1002, 24388, 1003, 27556, 1007, 31299,
                     1012, 42660, 1014, 25676, 1018, 44145, 1043, 52182,
                     1031, 32769, 1037, 21100, 1041, 32196, 1046, 25576};
  char newName[10];
  char nameData[12][10] = {{"Allen"},  {"Scott"}, {"Marry"}, {"John"},
                           {"Mark"},   {"Ricky"}, {"Lisa"},  {"Jasica"},
                           {"Hanson"}, {"Amy"},   {"Bob"},   {"Jack"}};

  // Initialize the doubly linked list
  head = createEmployee(data[0][0], nameData[0], data[0][1]);
  if (head == NULL)
    return 1; // Allocation failed
  left = head;

  // Populate the list with remaining data
  for (int i = 1; i < 12; i++) {
    newNode = createEmployee(data[i][0], nameData[i], data[i][1]);
    if (newNode == NULL) {
      // Free all allocated nodes in case of allocation failure
      while (head != NULL) {
        temp = head;
        head = head->linkRight;
        free(temp);
      }
      return 1;
    }
    left->linkRight = newNode;
    newNode->linkLeft = left;
    left = newNode;
  }

  // Displaying the list
  printf("\n\t員工編號\t姓名\t薪水\n");
  printf("==================================================\n");
  ptr = head;
  while (ptr != NULL) {
    printf("\t[%2d]\t[%-10s]\t[%3d]\n", ptr->num, ptr->name, ptr->sal);
    ptr = ptr->linkRight;
  }

  do {
    printf("請輸入要刪除的員工編號，\n");
    printf("輸入 [-1] 以結束插入過程：");
    scanf("%d", &pos);
    if (pos == -1)
      break;
    ptr = find_node(head, pos);
    if (ptr == NULL) {
      printf("找不到，請重新輸入。");
      continue;
    }
    printf("已刪除第 %d 號員工 姓名： %s 薪資：%d\n", ptr->num, ptr->name,
           ptr->sal);
    head = delete_node(head, ptr);
    printf("\n\t員工編號\t姓名\t薪水\n");
    printf("=========================");
    ptr = head;
    while (ptr != NULL) {
      printf("\t[%2d]\t[ %-10s]\t[%3d]\n", ptr->num, ptr->name, ptr->sal);
      ptr = ptr->linkRight;
    }
  } while (1);
  return 0;
}

linkEmp find_node(linkEmp head, int num) {
  linkEmp ptr = head;
  while (ptr != NULL) {
    if (ptr->num == num) {
      return ptr;
    }
    ptr = ptr->linkRight;
  }
  return NULL;
}

linkEmp insert_node(linkEmp head, linkEmp ptr, int num, int sal,
                    char name[10]) {
  linkEmp newNode = (linkEmp)malloc(sizeof(nodeEmp));
  newNode->linkLeft = newNode->linkRight = NULL;
  newNode->num = num;
  newNode->sal = sal;
  strcpy(newNode->name, name);
  if (head == NULL)
    return newNode;
  if (ptr == head) {
    head->linkLeft = newNode;
    newNode->linkRight = head;
    head = newNode;
    return head;
  }
  if (ptr->linkRight == NULL) {
    ptr->linkRight = newNode;
    newNode->linkLeft = ptr;
    return head;
  }
  newNode->linkRight = ptr->linkRight;
  ptr->linkRight->linkLeft = newNode;
  ptr->linkRight = newNode;
  newNode->linkLeft = ptr;
  return head;
}

linkEmp createEmployee(int num, char *name, int sal) {
  linkEmp node = (linkEmp)malloc(sizeof(nodeEmp));
  if (node == NULL) {
    fprintf(stderr, "Error at Memory Allocation!\n");
    return NULL;
  }
  memset(node, 0, sizeof(nodeEmp));
  node->num = num;
  strcpy(node->name, name);
  node->sal = sal;
  node->linkLeft = NULL;
  node->linkRight = NULL;
  return node;
}

linkEmp delete_node(linkEmp head, linkEmp del) {
  if (head == NULL) {
    printf("[List] 串列是空的\n");
    return NULL;
  }
  if (del == NULL) {
    printf("[List] 不是串列中的節點\n");
    return NULL;
  }
  if (del == head) {
    head = head->linkRight;
    head->linkLeft = NULL;
    free(del);
    return head;
  }
  if (del->linkRight == NULL) {
    del->linkLeft->linkRight = NULL;
  } else {
    del->linkLeft->linkRight = del->linkRight;
    del->linkRight->linkLeft = del->linkLeft;
  }
  free(del);
  return head;
}
