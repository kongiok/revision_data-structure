#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float powNum(int x, int y){
    float result=1;
    int i;
    for(i=1; i<=y; i++) result*=x;
    return result;
}

int main(){
    int x, y;
    while (1)
    {
        printf("Give me two number: "); scanf("%d %d", &x, &y);
        if(x == 0) break;
        printf("%d^%d=%f \n", x, y, powNum(x,y));
        printf("%d^%d=%f", x, y, pow(x,y));
    }
}