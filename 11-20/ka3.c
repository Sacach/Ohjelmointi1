#include <stdio.h>

int main(void){
    double luku, ka, i = 1, j, summa;
    scanf("%lf", &luku);

    for(j = 0; j + luku >= 0;){
        summa = summa + luku;
        i = i + 1;
        scanf("%lf", &luku);
    }


    i = i - 1;
    ka = summa / i;
    printf("%.2lf", ka);
}
