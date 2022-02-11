#include <stdio.h>
int Taulukko[10];
int Suurin[2];

int lueluvut(int maara);
void tulostus(int koko);
double keskiarvo(int koko);
int haesuurin(int koko);

int main(){
    int suurin;
    double ka;
    lueluvut(10);
    tulostus(10);
    haesuurin(10);
    ka = keskiarvo(10);
    printf("Suurin arvo on %d, ja se sijaitsee paikassa %d\n", Suurin[0], Suurin[1]);
    printf("Taulukon arvojen keskiarvo on %.3lf", ka);
}

int lueluvut(int maara){
    int i = 0, luku;

    while(i < maara){
        printf("Anna %d. kokonaisluku > \n", i+1);
        scanf("%d", &luku);
        if(luku >= 0 && luku <= 100){
            //printf("Luku: %d\n", luku);
            Taulukko[i] = luku;
            //printf("Taulukko: %d \n", Taulukko[i]);
            i = i + 1;
        }
    }
}

void tulostus(int koko){
    int i;
    //printf("Taulukon:\n");
    for(i = 0; i < koko; i++){
        printf("%d ", Taulukko[i]);
    }
    printf("\n");
}

double keskiarvo(int koko){
    double ka;
    int i, summa = 0;
    for(i = 0; i < koko; i++){
        summa = summa + Taulukko[i];
    }
    ka = (double)summa / (double)koko;
    //printf("ka: %d \n", ka);
    return ka;
}

int haesuurin(int koko){
    int suurin[2], i;
    Suurin[0] = Taulukko[0];
    Suurin[1] = 0;
    for(i = 0; i <= koko; i++){
        if(Suurin[0] < Taulukko[i]){
            Suurin[0] = Taulukko[i];
            Suurin[1] = i;
        }
    }
}
