#include <stdio.h>

int palkka, tunnit, brutto;

int main(void){
    printf("Anna tuntipalkka > ");
    scanf("%d", &palkka);
    printf("Tehdyt tunnit > ");
    scanf("%d", &tunnit);
    brutto = palkka * tunnit;
    printf("Bruttopalkkasi on %d euroa", brutto);
}
