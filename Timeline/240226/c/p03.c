//指標、陣列和字串函式，指標與變數之間的關係、字串的複製和長度計算
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
    int y=5, *yp, i;
    yp=&y; printf("%d %d %p %p\n", y, *yp, &y, yp);

    int a[15] = {5, 6, 7, 8, 9};
    printf("陣列a的位址-->%p，", a);
    printf("陣列a[4]的位址-->%p\n", &a[4]);
    for (i=0; i<5; i++) printf("%d ", a[i]); printf("\n");

    yp=a; for (i=0; i<5; i++) printf("%d ", *(yp+i)); printf("\n");
    yp=&a[0]; for (i=0; i<5; i++) printf("%d ", *(yp+i)); printf("\n");

    char s1[]="Today is a sunny day.", s2[]="This is a book.", s3[30], s4[40];
    strcpy(s3, s1); strcpy(s4, s2);
    printf("%s | %s | %s | %s\n", s1, s2, s3, s4); printf("%d %d\n", strlen(s1), strlen(s2));

    char s5[]={'h', 'e', 'l', 'l', 'o', '\0'}, s6[]="hello";
    printf("%s | %s | %d | %d\n", s5, s6, strlen(s5), strlen(s6));
    return 0;
}
