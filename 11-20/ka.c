#include <stdio.h>

int main(void){
    double luku, ka, i = 1, summa;
    scanf("%lf", &luku);

    while (luku >= 0){
        summa = summa + luku;
        i = i + 1;
        scanf("%lf", &luku);
    }
    i = i - 1;
    ka = summa / i;
    printf("%lf", ka);
}
