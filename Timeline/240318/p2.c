#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
    int num;
    char name[10];
    int salary;
    struct node *next;
} *link;

link insertnode(link head, link ptr, int new_num, int new_salary, char *new_name) {
    link newnode = (link)malloc(sizeof(struct node));
    newnode->num = new_num;
    strcpy(newnode->name, new_name);
    newnode->salary = new_salary;
    newnode->next = NULL;

    if (ptr == NULL) {
        newnode->next = head;
        head = newnode;
    } else {
        newnode->next = ptr->next;
        ptr->next = newnode;
    }

    return head;
}

link findnode(link head, int position) {
    link ptr = head;
    while (ptr != NULL) {
        if (ptr->num == position) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

int main() {
    link head1, ptr1, newnode;
    int new_num, new_salary, i, j;
    char new_name[10];
    int position = 0, find;
    int data[12][2] = {1001, 32367, 1002, 24388, 1003, 27556, 1007, 31299,
                       1012, 42660, 1014, 25676, 1018, 44145, 1043, 52182, 1031, 32769, 1037, 21100, 1041, 32196, 1046, 25776};
    char namedata[12][10] = {"Allen", "Scott", "Marry", "John", "Mark", "Ricky",
                              "Lisa", "Jasica", "Hanson", "Amy", "Bob", "Tack"};

    head1 = (link)malloc(sizeof(struct node));
    if (!head1) {
        printf("Error! 記憶體位置配置失敗!\n");
        exit(1);
    }

    head1->num = data[0][0];
    strcpy(head1->name, namedata[0]);
    head1->salary = data[0][1];
    head1->next = NULL;
    ptr1 = head1;

    for (i = 1; i < 12; i++) {
        newnode = (link)malloc(sizeof(struct node));
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]);
        newnode->salary = data[i][1];
        newnode->next = NULL;
        ptr1->next = newnode;
        ptr1 = ptr1->next;
    }

    printf("\n\t員工編號  姓名\t薪水\n");
    printf("\t==============================\n");
    link h = head1;
    while (h != NULL) {
        printf("\t[%4d]\t[ %-7s]\t[%6d]\n", h->num, h->name, h->salary);
        h = h->next;
    }

    while (1) {//新增程式 
        printf("輸入要插入其後的員工編號，如輸入的編號不在此串列中，\n");
        printf("新輸入的員工節點將視為此串列的串列首，結束插入過程請輸入-1:");
        scanf("%d", &position);
        if (position == -1)
            break;
        else {
            ptr1 = findnode(head1, position);
            printf("請輸入新的員工編號：");
            scanf("%d", &new_num);
            printf("請輸入新插入的員工薪水：");
            scanf("%d", &new_salary);
            printf("請輸入新插入的員工姓名：");
            scanf("%s", new_name);
            head1 = insertnode(head1, ptr1, new_num, new_salary, new_name);
        }
        printf("\n\t員工編號  姓名\t薪水\n");
        printf("\t==============================\n");
        link h = head1;
        while (h != NULL) {
            printf("\t[%4d]\t[ %-7s]\t[%6d]\n", h->num, h->name, h->salary);
            h = h->next;
        }
    }

    ptr1 = head1;
    printf("\n\t員工編號  姓名\t薪水\n");
    printf("\t==============================\n");
    while (ptr1 != NULL) {
        printf("\t[%4d]\t[ %-7s]\t[%6d]\n", ptr1->num, ptr1->name, ptr1->salary);
        ptr1 = ptr1->next;
    }

    return 0;
}

