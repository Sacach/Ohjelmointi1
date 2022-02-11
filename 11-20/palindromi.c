#include <stdio.h>
#include <math.h>

int main(void){
    int luku, uusi_luku = 0, temp, i, numero;
    printf("Anna viisinumeroinen positiivinen kokonaisluku: \n");
    scanf("%d", &luku);


    if (luku >= 10000 && luku <= 99999){
        temp = luku;
        for (i = 4; i > -1 ; --i){
            numero = temp / pow(10, i);
            temp = temp - numero * pow(10, i);
            uusi_luku = uusi_luku + numero * pow(10, 4-i);
            //printf("uusi_luku: %d\n", uusi_luku);
        }
        if (uusi_luku == luku){
            printf("Luku %d on palindromi\n", luku);
        }
        else{
            printf("Luku %d ei ole palindromi\n", luku);
        }
    }
    else{
        printf("Syote ei ole viisinumeroinen positiivinen kokonaisluku\n");
    }

}
