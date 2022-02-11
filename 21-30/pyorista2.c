#include <stdio.h>
#include <math.h>

int pyoristaKokonaisluvuksi(double luku);
double pyoristaKymmenesosat(double luku);
double pyoristaSadasosat(double luku);
double pyoristaTuhannesosat(double luku);

void tyhjennapuskuri(void);
double luedouble(void);


int main(void){
    int i, j;
    double x[5];
    for (i = 0; i < 5; i++){
        x[i] = luedouble();
        //printf("%8lf\n", x[i]);
    }

    for (j = 0; j < 5; j++){

        printf("%8lf, %5d\n", x[j], pyoristaKokonaisluvuksi(x[j]));
        printf("%8lf, %5.1lf\n", x[j], pyoristaKymmenesosat(x[j]));
        printf("%8lf, %5.2lf\n", x[j], pyoristaSadasosat(x[j]));
        printf("%8lf, %5.3lf\n", x[j], pyoristaTuhannesosat(x[j]));
    }
    return 0;
}

int pyoristaKokonaisluvuksi(double luku){

    return floor(luku + 0.5);
}
double pyoristaKymmenesosat(double luku){

    return floor(luku * 10 + 0.5) / 10;
}
double pyoristaSadasosat(double luku){

    return floor(luku * 100 + 0.5) / 100;
}
double pyoristaTuhannesosat(double luku){

    return floor(luku * 1000 + 0.5) / 1000;
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
