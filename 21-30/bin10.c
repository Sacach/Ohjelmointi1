#include <stdio.h>
#include <math.h>

void tyhjennapuskuri(void);
int lueint(void);

int main(void){
    int bin, dec = 0, temp, i, numero;

    bin = lueint();

    if (bin >= 0 && bin <= 11111){
        for (i = 4; i > -1 ; --i){
            temp = bin / pow(10, i);
            bin = bin - temp * pow(10, i);
            dec = dec + temp * pow(2, i);
            //printf("dec: %d\n", dec);
        }
        printf("%d", dec);
    }
    else{
        printf("Syote ei ole viisinumeroinen binaariluku\n");
    }

}

void tyhjennapuskuri(void){
    while(fgetc(stdin) != '\n');
}

int lueint(void){
    int luku;
    int result;
    char merkki;

    //printf("Anna viisinumeroinen binaariluku: \n");

    while((result=scanf("%d%c", &luku, &merkki))<= 0 || result == 2 && merkki != '\n'){
        tyhjennapuskuri();
        //printf("%lf\n", luku);
        printf("Ei ollut binaariluku\n");
    }
    return luku;
}
