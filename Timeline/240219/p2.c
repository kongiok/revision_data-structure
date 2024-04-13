#include <stdio.h>
#include <stdlib.h>

int main(){
    int column, row, digit;
    while (1)
    {
        printf("Give me number: ");
        scanf("%d", &column);
        if(column == -1) break;
        int pascal[column+1][column+1];
        for(row=0; row<=column; row++){
            pascal[row][0]=1;
            for (digit = 1; digit <= row; digit++){
                pascal[row][digit]=pascal[row][digit-1]*(row-digit+1)/digit;
            } 
        }
        for (row = 0; row <= column; row++)
        {
            for (digit = 0; digit <= row; digit++) {
                printf("%d ", pascal[row][digit]);
            }
            printf("\n");
        }
        
    }
    
}