
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  char name[20];
  char number[10];
  struct student *next;
};
typedef struct student s_data;

void print_all_student(s_data *h) {
  s_data *ptr1 = h;
  while (ptr1 != NULL) {
    printf("姓名：%s\t學號：%s\n", ptr1->name, ptr1->number);
    ptr1 = ptr1->next;
  }
  printf("-------------------------\n");
}

int main() {
  int select = 0, student_no = 0;
  float Msum = 0, Esum = 0;
  char name[20];
  char number[10];
  s_data *head = NULL, *ptr = NULL;
  do {
    if (head != NULL)
      print_all_student(head);
    printf("(1) 新增\t(2) 離開 =>");
    scanf("%d", &select);
    if (select == 2)
      break;
    printf("姓名、學號：");
    scanf("%s %s", name, number);
    s_data *new_data = (s_data *)malloc(sizeof(s_data));
    strcpy(new_data->name, name);
    strcpy(new_data->number, number);
    new_data->next = NULL;
    if (head == NULL) {
      head = new_data;
      ptr = new_data;
      continue;
    }
    ptr->next = new_data;
    ptr = new_data;
  } while (select != 2);
  print_all_student(head);
}
