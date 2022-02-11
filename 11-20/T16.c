#include <stdio.h>

int main(void){
    int i, j;
    for (i = 1; i < 9; i++){
        for (j = 8; j > 1; j--){
            if(j <= i){
                printf("a");
            }
            else{
                printf(" ");
            }
        }
        printf("a\n");
    }
}
