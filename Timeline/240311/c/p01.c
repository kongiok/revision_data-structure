#include <stdio.h>
#include <stdlib.h>

struct student
{
  char name[50];
  int math, english;
  char no[10];
  struct student *next;
};
typedef struct student s_data;
s_data *head;
s_data *ptr;
s_data *new_1;

int main(){ 
  head = (s_data *)malloc(sizeof(s_data) * 1);
  head->next = NULL; ptr = head; int sel, num, Msum, Esum;
  do
  {
    printf("1. Add 2. Exit : "); scanf("%d", &sel);
    if (sel == 2) break;
    new_1 = (s_data *)malloc(sizeof(s_data) * 1);
    printf("姓名\t學號\t數學\t英文\n");
    scanf("%s %s %d %d", new_1->name, new_1->no, &new_1->math, &new_1->english);
    ptr->next = new_1; new_1->next = NULL; ptr = ptr->next;
  } while (sel == 1);
  ptr = head->next;
  putchar('\n');
  num = Msum=Esum=0;
  while (ptr != NULL)
  {
    printf("姓名%s\t學號%s\t數學成績%d\t英文成績%d\n", ptr->name, ptr->no, ptr->math, ptr->english);
    Msum += ptr->math; Esum += ptr->english; num++;
    ptr = ptr->next;
  }
  printf("---------------------------------------\n%d %d %d\n", num, Esum, Msum);
  printf("數學平均%.2f\t英文平均%.2f\n", (float)Msum*1.0 / num, (float)Esum*1.0 / num);
  return 0;
}