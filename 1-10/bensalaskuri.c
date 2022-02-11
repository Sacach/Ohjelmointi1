#include <stdio.h>
#include <math.h>

int main(void){
    double keskikulutus, bensa, km, kokonaisbensa, kokonaiskm;

    while (1){

        printf("Anna tankatun bensiinin maara (-1 lopettaa ) > ");
        scanf("%lf", &bensa);
        if (bensa == -1){
            break;
        }
        kokonaisbensa = kokonaisbensa + bensa;

        printf("Ajetut kilometrit > ");
        scanf("%lf", &km);
        kokonaiskm = kokonaiskm + km;

        keskikulutus = bensa / (km / (float)100);
        printf("Keskikulutus talla tankkauksella on %.3fl litraa satasella\n", keskikulutus);
    }
    keskikulutus = kokonaisbensa / (kokonaiskm / (float)100);
    printf("Kokonaiskeskikulutus on %.3fl litraa satasella\n", keskikulutus);
}
