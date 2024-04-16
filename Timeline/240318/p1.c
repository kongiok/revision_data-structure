#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int n, m;
    int k1, k2, pt;
    int i, j;

    printf("輸入學生人數直到-1停止-->"); 
    scanf("%d", &n); 
    printf("輸入學生科目直到-1停止-->"); 
    scanf("%d", &m);

    int *stu1 = (int *)malloc(sizeof(int) * n * (m + 2)), *ptr; 
    ptr = stu1; 
    srand(time(NULL));

    while (n != -1 && m != -1) {
        for (i = 0; i < m; i++) 
            printf("成績%d ", i + 1); 
        printf("平均  名次\n");

        for (i = 0; i < n; i++) {
            int s = 0;
            for (j = 0; j < m; j++) {
                k1 = i * (m + 2) + j; 
                s += *(stu1 + k1) = rand() % 101; 
                printf("%5d ", *(stu1 + k1)); 
            }
            pt = ++k1; 
            *(stu1 + pt) = (int)s / m; 
            k1++; 
            *(stu1 + k1) = i; 
            printf("%5d %5d\n", *(stu1 + pt), *(stu1 + k1));
        }

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                k1 = m + (m + 2) * i; 
                k2 = m + (m + 2) * j;
                if (*(ptr + k1) > *(ptr + k2)) 
                    *(ptr + k2 + 1) = *(ptr + k2 + 1) + 1;
                else if (*(ptr + k1) < *(ptr + k2)) 
                    *(ptr + k1 + 1) = *(ptr + k1 + 1) + 1;
            }
        }

        for (i = 0; i < m; i++) 
            printf("成績%d ", i + 1); 
        printf("平均  名次\n");

        for (i = 0; i < n; i++) {
            for (j = 0; j < m + 2; j++) {
                k1 = i * (m + 2) + j; 
                printf("%5d", *(stu1 + k1));
            }
            printf("\n");
        }
        
        free(stu1);
        stu1 = (int *)malloc(sizeof(int) * n * (m + 2));

        printf("輸入學生人數直到-1停止-->"); 
        scanf("%d", &n); 
        printf("輸入學生科目直到-1停止-->"); 
        scanf("%d", &m);
    }

    return 0;
}

