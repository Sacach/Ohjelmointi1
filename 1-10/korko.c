#include <stdio.h>

int main(void){
    double lainasumma,
    lainakorko,
    kokonaiskorko,
    korko;
    int lainapaivat;

    scanf("%lf", &lainasumma);

    scanf("%lf", &lainakorko);
    korko = lainakorko / 100;

    scanf("%d", &lainapaivat);

    kokonaiskorko = lainasumma * korko * lainapaivat/365;


    printf("Lainap‰‰oman %.2lf euroa korko %d p‰iv‰lt‰ korkoprosentilla %.2lf on yhteens‰ %.2lf euroa.", lainasumma, lainapaivat, lainakorko, kokonaiskorko);
}
