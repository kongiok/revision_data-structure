#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct employee
{
  int num, salary;
  char name[50];
  struct employee *next;
};

typedef struct employee node;
typedef node *link;

link findNode (link head, int num);
link insertNode(link head, link ptr, int num, int salary, char *name);

int main(){
  link head, ptr, newnode;
  int new_num, new_salary;
  int i, j, position=0, find;
  char new_name[10];
  char nameData[12][10]={
    {"Allen"}, {"Scott"}, {"Marry"}, {"John"}, {"Mark"}, {"Ricky"}, {"Lisa"}, {"Jasica"}, {"Hanson"}, {"Amy"}, {"Bob"}, {"Jack"}
  };
  int data[12][2] = {
        {1001, 32367}, {1002, 24388}, {1003, 27556}, {1007, 31299},
        {1012, 42660}, {1014, 25676}, {1018, 44145}, {1043, 52182},
        {1031, 32769}, {1037, 21100}, {1041, 32196}, {1046, 25776}
    };
  head = (link)malloc(sizeof(node)); if (!head) {printf("Error，記憶體配置失敗。\n"); exit(1);}
  head->num = data[0][0]; for (j = 0; j < 10; j++) head->name[j] = nameData[0][j]; head->salary = data[0][1]; head->next = NULL; ptr = head;
  for (i = 0; i < 12; i++)
  {
    newnode = (link)malloc(sizeof(node)); if (!newnode) {printf("Error，記憶體配置失敗。\n"); exit(1);}
    newnode->num = data[i][0]; for (j = 0; j < 10; j++) newnode->name[j] = nameData[i][j]; newnode->salary = data[i][1]; newnode->next = NULL; ptr->next = newnode; ptr = ptr->next;
  }
  while (1)
  {
    printf("\n請輸入要插入其後的員工編號。\n如輸入的編號不在此串列，\n");
    printf("新輸入的員工節點將視為此串列的串列首，要結束插入過程請輸入-1："); scanf("%d", &position);
    if (position == -1) break;
    ptr = findNode(head, position);
    printf("請輸入新插入的員工編號："); scanf("%d", &new_num);
    printf("請輸入新插入的員工薪水："); scanf("%d", &new_salary);
    printf("請輸入新插入的員工姓名："); scanf("%s", new_name);
    head = insertNode(head, ptr, new_num, new_salary, new_name);
  }
  ptr = head;
  printf("\n員工編號\t員工姓名\t員工薪水\n");
  while (ptr != NULL)
  {
    printf("%d\t%s\t%d\n", ptr->num, ptr->name, ptr->salary);
    ptr = ptr->next;
  }
}
link findNode(link head, int num){
  link ptr;
  for (ptr = head; ptr != NULL; ptr = ptr->next)
    if (ptr->num == num) return ptr;
  return NULL;
}

link insertNode(link head, link ptr, int num, int salary, char *name){
  link toInsert;
  toInsert = (link)malloc(sizeof(node));
  if(!toInsert){
    return NULL;
  }
  toInsert->num = num;
  toInsert->salary = salary;
  strcpy(toInsert->name, name);
  toInsert->next = NULL;
  if (ptr == head){
    toInsert->next = head;
    head = toInsert;
  } else if (ptr->next == NULL){
    ptr->next = toInsert;
  }
  else {
    toInsert->next = ptr->next;
    ptr->next = toInsert;
  }
  return head;
}