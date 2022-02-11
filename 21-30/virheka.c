#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int virhe = 0;
double lueluku(void);

int main(void){
    double luku, ka, i = 1, summa;
    printf("Anna reaaliluku ( negat arvo lopetaa ) > ");
    luku = lueluku();


    while (luku >= 0){

        summa = summa + luku;
        i = i + 1;
        luku = lueluku();
        //printf("%lf", luku);
    }
    if (virhe == 3){
        printf("\nVirheellinen syote kolme kertaa. Ohjelma lopetetaan");
    }
    else{
        i = i - 1;
        ka = summa / i;
        printf("%lf\n", ka);
    }
}

double lueluku(void){
    char luku[30];
    char *ptr;
    int i;
    double numero;
    int flag = 0;
    while (1){
        scanf("%s", &luku);
        for (i = 0; i < strlen(luku); i++){
            //printf("%d\n", luku[i]);
            if ((luku[i] < 58 && luku[i] > 47) || luku[i]  == 46 || luku[i]  == 45){
                //printf("oli reaaliluku\n");
            }

            else{
                printf("Ei ollut reaaliluku\n");
                flag = 1;
            }
        }

        if (flag == 1){
            virhe = virhe + 1;
            printf("Virheellinen syote numero %d\n", virhe);
            if (virhe == 3){
                return -1;
            }
            printf("Ei kelpaa, yrita uudelleen! > ");
            flag = 0;
        }
        else{
            numero = strtod(luku, &ptr);
            //printf("%lf", numero);
            return numero;
        }
    }
}
