#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define NIMEN_PITUUS 256

typedef struct {
   char nimi[NIMEN_PITUUS];
   char ajat[4][48];
   double pisteet;
} LuistelijanTiedot;

void lajittele(int * taulukko, int n);
LuistelijanTiedot lueLuistelijanTiedot(void);
void lueRoskat(void);
double MuutaAika(char * aika);

int main(){
    int maara, i;
    char luku[48];
    printf("Anna luistelijoiden maara: \n");
    fgets(luku, 48, stdin);
    luku[strcspn(luku, "\n")] = 0;
    maara = atoi(luku);
    LuistelijanTiedot lista[maara];

    for (i = 0; i < maara; i++){
        lista[i] = lueLuistelijanTiedot();

    }
    //lajittele(lista, maara);

    for(i = 0; i < maara; i++){
        printf("%d. %s    %10.3lf\n", i+1, lista[i].nimi, lista[i].pisteet );
    }
    return 0;
}

LuistelijanTiedot lueLuistelijanTiedot(void){
    LuistelijanTiedot jt;
    int i, matkat[4] = {500, 1500, 5000, 10000}, len;
    double pisteenlasku[4] = {1,3,10,20}, sekunnit;
    char henk[48];
    printf("\nAnna Luistelijan Etu- ja Sukunimi  > \n");
    fgets(jt.nimi, sizeof(jt.nimi), stdin);
    jt.nimi[strcspn(jt.nimi, "\n")] = 0;

    jt.pisteet = 0;
    for (i = 0; i < 4; i++){
        printf("\nAnna aika %d m matkalle > \n", matkat[i]);
        fgets(jt.ajat[i], 48, stdin);
        jt.ajat[i][strcspn(jt.ajat[i], "\n")] = 0;
        sekunnit = MuutaAika(jt.ajat[i]);
        jt.pisteet = jt.pisteet + (double)sekunnit / pisteenlasku[i];
    }

    return(jt);
}
double MuutaAika(char * aika){
    const char piste[2] = ".";
    char *luku;
    double sekunnit = 0.0;
    int i;
    luku = strtok(aika, piste);
     for(i = 0; i < 3; i++){
        switch(i){
            case 0:
                sekunnit = sekunnit + atoi(luku) * 60;
                break;
            case 1:
                sekunnit = sekunnit + atoi(luku);
                break;
            case 2:
                sekunnit = sekunnit + (double)atoi(luku)/(double)100;
                break;
        }
        luku = strtok(NULL, piste);
     }

    return sekunnit;
}
void lajittele(int * taulukko, int n){
    int temp, paikka, i, j;

    for(i = 0; i < n; i++){
        paikka = i;
        for(j = i+1; j < n; j++){
            if(taulukko[j] < taulukko[paikka]){
                paikka = j;
            }
        }
        if(paikka != i){
            temp = taulukko[paikka];
            taulukko[paikka] = taulukko[i];
            taulukko[i] = temp;
        }
    }
}
void lueRoskat(void){

   // Tyhjennetään puskuri
   while( fgetc(stdin) != '\n');
}
