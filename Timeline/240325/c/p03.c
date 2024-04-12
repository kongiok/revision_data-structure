
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  char name[20], number[10];
  int scoreMath, scoreEnglish;
  struct student *linkRight, *linkLeft;
};

typedef struct student s_data;

void print_link(s_data *data);
void print_all_links(s_data *head);

int main() {
  int select = 0;
  char name[20], number[10];
  int scoreMath, scoreEnglish;
  s_data *head = NULL, *current = NULL;
  do {
    if (head != NULL) {
      print_all_links(head);
    }
    printf("(1)新增 \t(2)離開 =>");
    scanf("%d", &select);
    if (select == 2)
      break;
    printf("姓名、學號、數學、英文成績：");
    scanf("%s %s %d %d", name, number, &scoreMath, &scoreEnglish);

    // Initializing New Node
    s_data *newStudent = (s_data *)malloc((unsigned)sizeof(s_data));
    if (newStudent == NULL) {
      fprintf(stderr, "Memory Allocation Failed!\n");
      exit(1);
    }
    strcpy(newStudent->name, name);
    strcpy(newStudent->number, number);
    newStudent->scoreMath = scoreMath;
    newStudent->scoreEnglish = scoreEnglish;

    // check whether the program is in the start.
    if (head == NULL) {
      newStudent->linkLeft = NULL;
      newStudent->linkRight = NULL;
      head = current = newStudent;
      continue;
    }
    current->linkRight = newStudent;
    newStudent->linkRight = NULL;
    newStudent->linkLeft = current;
    current = newStudent;
  } while (select != 2);
}

void print_all_links(s_data *head) {
  s_data *current = head, *last = NULL;
  printf("向右查訪：\n");
  while (current != NULL) {
    print_link(current);
    last = current;
    current = current->linkRight;
  }
  printf("向左查訪：\n");
  current = last;
  while (current != NULL) {
    print_link(current);
    current = current->linkLeft;
  }
}

void print_link(s_data *data) {
  printf("姓名：%s\t學號：%s\t數學成績：%d\t英文成績：%d\n", data->name,
         data->number, data->scoreMath, data->scoreEnglish);
}
