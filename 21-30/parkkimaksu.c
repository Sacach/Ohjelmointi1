#include <stdio.h>

double laskeParkkiMaksu(double tunnit);
void tyhjennapuskuri(void);
double luedouble(void);

int main(){
    double tunnit[3], veloitus[3], koktunnit, kokveloitus;
    int i;
    for(i = 0; i < 3; i++){
        tunnit[i] = luedouble();
        veloitus[i] = laskeParkkiMaksu(tunnit[i]);
    }
    printf("    Asiakas      Tunnit    Veloitus\n");
    for(i = 0; i < 3; i++){
        printf("%11d %11.2lf %11.2lf\n", i+1, tunnit[i], veloitus[i]);
    }
    koktunnit = tunnit[0] + tunnit[1] + tunnit[2];
    kokveloitus = veloitus[0] + veloitus[1] + veloitus[2];
    printf("   YHTEENSA %11.2lf %11.2lf\n", koktunnit, kokveloitus);
}

void tyhjennapuskuri(void){
    while(fgetc(stdin) != '\n');
}
double luedouble(void){
    double luku;
    int result;
    char merkki;

    printf("Anna tunnit > \n");

    while((result=scanf("%lf%c", &luku, &merkki))<= 0 || result == 2 && merkki != '\n'){
        tyhjennapuskuri();
        printf("%lf\n", luku);
        printf("Ei ollut reaaliluku\n");
    }
    return luku;
}

double laskeParkkiMaksu(double tunnit){
    if (tunnit <= 3){
        return 2;
    }
    else if (tunnit > 3 && tunnit <= 19){
        return 2 + (tunnit - 3) * 0.5;
    }
    else{
        return 10;
    }
}
