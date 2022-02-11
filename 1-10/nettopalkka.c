#include <stdio.h>

int main(void){
    double tyontekija = 0.0,
    verottaja = 0.0,
    verop,
    palkka,
    tunnit,
    brutto;

    //printf("Tehdyt tunnit > ");
    scanf("%lf", &tunnit);

    //printf("Anna tuntipalkka > ");
    scanf("%lf", &palkka);

    //printf("Veroprosentti > ");
    scanf("%lf", &verop);

    brutto = palkka * tunnit;
    //printf("Bruttopalkkasi on %d euroa\n", brutto);

    //printf("verop on %lf\n", verop);
    verottaja = (verop / (float)100) * brutto;
    //printf("verottaja on %lf\n", verottaja);
    tyontekija = brutto - verottaja;
    printf("Nettopalkkasi on %.2lf euroa josta veron osuus on %.2lf euroa", tyontekija, verottaja);
}
