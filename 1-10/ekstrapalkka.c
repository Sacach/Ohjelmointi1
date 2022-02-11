#include <stdio.h>

int main(void){
    double palkka,
    tunnit,
    verop,
    brutto,
    v,
    tt;


    scanf("%lf", &palkka);

    scanf("%lf", &tunnit);

    scanf("%lf", &verop);

    brutto = palkka * tunnit;

    if (tunnit > 40){
        brutto = brutto + (tunnit - 40) * palkka * 0.5;

    }
    v = (verop/(float)100) * brutto;
    tt = brutto - v;

    printf("Nettopalkkasi on %.2lf euroa josta veron osuus on %.2lf euroa", tt, v);
}
