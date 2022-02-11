#include <stdio.h>
#include <math.h>

int main(void){
    int luku, i, numero;

    scanf("%d", &luku);
    printf("Luku %d eroteltuna:", luku);

    for (i = 4; i > -1 ; --i){
        numero = luku / pow(10, i);
        luku = luku - numero * pow(10, i);
        printf(" %d", numero);
    }

}
