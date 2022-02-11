#include <stdio.h>

int main(void){
    int i, j, luku, tyhja;
    for (i = 1; i <= 10; i++){
        for (tyhja = 10 - i; tyhja > 0; tyhja--){
            printf(" ");
        }
        j = 2 * i - 1;
        for (luku = i; luku <= j; luku++){
            if (luku < 10){
                printf("%d", luku);
            }
            else{
                printf("%d", luku - 10);
            }
        }
        for (j = 2 * i - 1; j > i; j--){
            if (j < 11){
                printf("%d", j-1);
            }
            else{
                printf("%d", j - 11);
            }
        }


        printf("\n");
    }
}
