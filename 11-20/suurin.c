#include <stdio.h>

int main(void){
    int luku, i, x = 0;

    for(i=0; i < 10; ++i){
        scanf("%d", &luku);

        if(luku > x){
            x = luku;
        }
    }
    printf("Suurin syottamasi luku oli %d", x);

}
