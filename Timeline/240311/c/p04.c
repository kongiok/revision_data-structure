#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int num, salary;
    char name[10];
    struct employee *next;
};

typedef struct employee node;
typedef node *link;

link findnode(link head, int num) {
    link ptr;
    ptr = head;
    while(ptr != NULL) {
        if(ptr->num == num)
            return ptr;
        ptr = ptr->next;
    }
    return ptr;
}

link insertnode(link head, link ptr, int num, int salary, char name[10]) {
    link InsertNode;
    InsertNode = (link)malloc(sizeof(node));
    if(!InsertNode) return NULL;
    InsertNode->num = num;
    InsertNode->salary = salary;
    strcpy(InsertNode->name, name);
    InsertNode->next = NULL;
    if(ptr == NULL) {
        InsertNode->next = head; 
        head = InsertNode;
    } 
    else {
        if(ptr->next == NULL)
            ptr->next = InsertNode;
        else {
            InsertNode->next = ptr->next;
            ptr->next = InsertNode;
        }
    }
    return head;
}

int main() {
    link head, ptr, newnode;
    int i, j, position = 0;
    int data[12][2] = {
        {1001, 32367}, {1002, 24388}, {1003, 27556}, {1007, 31299},
        {1012, 42660}, {1014, 25676}, {1018, 44145}, {1043, 52182},
        {1031, 32769}, {1037, 21100}, {1041, 32196}, {1046, 25776}
    };
    char namedata[12][10] = {
        "Allen", "Scott", "Marry", "John", "Mark", "Ricky", 
        "Lisa", "Jasica", "Hanson", "Amy", "Bob", "Jack"
    };

    printf("員工編號\t薪水\t員工編號\t薪水\t員工編號\t薪水\t員工編號\t薪水\n");
    printf("------------------------------------------------------------\n");

    for(i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("[%4d]\t$%5d\t", data[j * 3 + i][0], data[j * 3 + i][1]);
        printf("\n");
    }
    printf("------------------------------------------------------------\n");

    head = (link)malloc(sizeof(node));
    if(!head) {
        printf("錯誤！記憶體配置失敗！\n");
        exit(1);
    }

    head->num = data[0][0];
    strcpy(head->name, namedata[0]);
    head->salary = data[0][1]; 
    head->next = NULL; 
    ptr = head;

    for(i = 1; i < 12; i++) {
        newnode = (link)malloc(sizeof(node)); 
        newnode->num = data[i][0];
        strcpy(newnode->name, namedata[i]);
        newnode->salary = data[i][1]; 
        newnode->next = NULL; 
        ptr->next = newnode; 
        ptr = ptr->next;
    }

    while(1) {
        printf("\n");
        printf("請輸入要插入員工資料的編號，輸入編號後請依序輸入員工編號、薪水及姓名。\n");
        printf("若要結束請輸入-1:");
        scanf("%d", &position);
        if(position == -1)
            break;
        else {
            ptr = findnode(head, position);
            if(ptr == NULL) {
                printf("找不到指定的員工編號，將新增資料至列表末端。\n");
                ptr = head;
            }
            newnode = (link)malloc(sizeof(node)); // 需要在這裡重新分配newnode的記憶體
            printf("請輸入員工編號："); scanf("%d", &newnode->num);
            printf("請輸入薪水："); scanf("%d", &newnode->salary);
            printf("請輸入姓名："); scanf("%s", newnode->name);
            head = insertnode(head, ptr, newnode->num, newnode->salary, newnode->name);
        }
    }

    ptr = head;
    printf("\n\t員工編號  \t姓名\t薪水\n"); 
    printf("\t==============================\n");
    while(ptr != NULL) {
        printf("\t[%2d]\t[%-7s]\t[%3d]\n", ptr->num, ptr->name, ptr->salary); 
        ptr = ptr->next;
    }

    return 0;
}