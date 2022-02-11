#include <stdio.h>
#include <math.h>

int pyorista(void);
void tyhjennapuskuri(void);
double luedouble(void);


int main(void){
    pyorista();
    return 0;
}

int pyorista(void){
    int i, y[5];
    double x[5];
    for (i = 0; i < 5; i++){
        x[i] = luedouble();
        y[i] = floor(x[i] + 0.5);
    }
    for (i = 0; i < 5; i++){
        printf("%8lf, %8d\n", x[i], y[i]);
    }
}

void tyhjennapuskuri(void){
    while(fgetc(stdin) != '\n');
}
double luedouble(void){
    double luku;
    int result;
    char merkki;

    printf("Anna reaaliluku > \n");

    while((result=scanf("%lf%c", &luku, &merkki))<= 0 || result == 2 && merkki != '\n'){
        tyhjennapuskuri();
        printf("%lf\n", luku);
        printf("Ei ollut reaaliluku\n");
    }
    return luku;
}
