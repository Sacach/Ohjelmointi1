#include <stdio.h>
#include <string.h>
int TT_MAARA = 5,
RY_MAARA = 9,
RY_NIMARVOT[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

void kysypalkat(int lista[]);
void tulosta_ry(void);
void laskerahat(int raha, int rahalista[]);
void tulosta_palkat(int palkat[]);

int main(){
    int palkat[TT_MAARA];
    kysypalkat(palkat);
    tulosta_ry();
    tulosta_palkat(palkat);
    return 0;
}
void kysypalkat(int lista[]){
    int i, palkka;
    for(i = 0; i < TT_MAARA; i++){
        printf("Anna %d. tyontekijan palkka > \n", i+1);
        scanf("%d", &palkka);
        lista[i] = palkka;
    }
}
void tulosta_ry(void){
    int i;
    printf("Palkka");
    for(i = RY_MAARA - 1; i > -1; i--){
        printf("%4d €", RY_NIMARVOT[i]);
    }
    printf("\n");
}

void laskerahat(int raha, int rahalista[]){
    int i = RY_MAARA - 1;
    if (raha == 0){
        for(i = 0; i < RY_MAARA; i++){
            rahalista[i] = 0;
        }
    }
    while(raha > 0){
        rahalista[i] = raha / RY_NIMARVOT[i];
        raha = raha % RY_NIMARVOT[i];
        i--;
    }
}
void tulosta_palkat(int palkat[]){
    int i, j, rahalista[RY_MAARA], kaikkirahat[RY_MAARA];
    memset(kaikkirahat, 0, RY_MAARA*sizeof(int));
    for(i = 0; i < TT_MAARA; i++){
        printf("%6d", palkat[i]);
        laskerahat(palkat[i], rahalista);

        for(j = RY_MAARA - 1; j > -1; j--){
            printf("%6d", rahalista[j]);
            kaikkirahat[j] = kaikkirahat[j] + rahalista[j];
            rahalista[j] = 0;
        }

        printf("\n");
    }
    printf("  YHT:");
    for(i = RY_MAARA - 1; i > -1; i--){
        printf("%6d", kaikkirahat[i]);
    }
    printf("\n");
}
