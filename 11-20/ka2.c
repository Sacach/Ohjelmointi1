#include <stdio.h>

int main(void){
    double luku, ka, i = 1, summa;
    scanf("%lf", &luku);

    do{
        summa = summa + luku;
        i = i + 1;
        scanf("%lf", &luku);

    } while (luku >= 0);
    i = i - 1;
    ka = summa / i;
    printf("%.2lf", ka);
}
