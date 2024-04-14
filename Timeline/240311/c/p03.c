#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[20];
    char no[10]; 
    int Math;
    int Eng;
    struct student *next;
};

typedef struct student s_data;

int main() {
    s_data *ptr;  // 學生資料指標
    s_data *head; // 頭節點，用來指向鏈結列表的開始
    s_data *new1; // 用於創建並添加新的學生資料

    head = (s_data*) malloc(sizeof(s_data));
    head->next = NULL;
    ptr = head;

    int sel, num = 0, Msum = 0, Esum = 0;

    do {
        printf("(1)新增學生資料 (2)結束輸入 => ");
        scanf("%d", &sel);
        
        if (sel != 2) {
            printf("請輸入 姓名 學號 數學成績 英文成績：");
            new1 = (s_data*) malloc(sizeof(s_data));
            scanf("%s %s %d %d", new1->name, new1->no, &new1->Math, &new1->Eng);
            ptr->next = new1;
            new1->next = NULL;
            ptr = ptr->next;
            num++;
        }
    } while (sel != 2);

    ptr = head->next;
    putchar('\n');

    while (ptr != NULL) {
        printf("姓名:%s\t 學號:%s\t 數學成績:%d\t 英文成績:%d\n", ptr->name, ptr->no, ptr->Math, ptr->Eng);
        Msum += ptr->Math;
        Esum += ptr->Eng;
        ptr = ptr->next;
    }
        printf("..................................................\n");
        printf("數學平均成績:%.2f 英文平均成績:%.2f\n", Msum * 1.0 / num, Esum * 1.0 / num);

    return 0;
}