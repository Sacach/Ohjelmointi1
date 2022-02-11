#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lisaa_arvo(int lista[], int sijainti);
int tarkista(int luku, int lista[], int sijainti);
void arvo_numerot(int oikearivi[]);

int main(){
    int numero, i, j = 0, k, oikein, lisanro,
    oikearivi[10],
    maara,
    rivit[5][7],
    randrivi[7],
    flag;

    srand(time(NULL));
    printf("Montako rivia haluat syottaa (max 5 rivia ) > ");
    scanf("%d", &maara);
    for(i = 0; i < maara; i++){
        for(j = 0; j < 7; j++){
            printf("Anna %d rivin %d. numero > ", i+1, j+1);
            scanf("%d", &numero);
            rivit[i][j] = numero;
        }
    }

    for(i = maara; i < 5; i++){
        j = 0;
        while(j < 7){
            flag = lisaa_arvo(randrivi, j);
            if (flag == 1){
                j = j + 1;
            }
        }
        for(k = 0; k < 7; k++){
            rivit[i][k] = randrivi[k];
        }
    }
    printf("Lottorivit:\n\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 7; j++){
            printf("%3d ", rivit[i][j]);
        }
        printf("\n");
    }

    arvo_numerot(oikearivi);
    printf("Oikea rivi: ");
    for(i = 0; i < 7; i++){
        printf("%3d ", oikearivi[i]);
    }
    printf("lisanumerot: ");
    for(i = 7; i < 10; i++){
        printf("%3d ", oikearivi[i]);
    }
    printf("\n");

    for(i = 0; i < 5; i++){
        oikein = 0;
        lisanro = 0;
        for(j = 0; j < 7; j++){
            for(k = 0; k < 7; k++){
                //printf("Oikea rivi: %3d \n", oikearivi[j]);
                if(oikearivi[j] == rivit[i][k]){
                    oikein = oikein + 1;
                }
            }
        }
        for(j = 7; j < 10; j++){
             for(k = 0; k < 7; k++){
                //printf("lisanumerot: %3d \n", oikearivi[j]);
                //printf("lisanumerot: %3d \n", oikearivi[j]);
                if(oikearivi[j] == rivit[i][k]){
                    lisanro = lisanro + 1;
                }
            }
        }
        printf("Rivilla %d. on %d oikein ja %d lisanumeroa\n", i+1, oikein, lisanro);
    }

}

void arvo_numerot(int oikearivi[]){
    int i = 0, flag;
    while(i < 10){
        flag = lisaa_arvo(oikearivi, i);
        if (flag == 1){
            i = i + 1;
        }
    }
}

int lisaa_arvo(int lista[], int sijainti){
    int luku, flag;
    luku = rand() % 40 + 1;
    flag = tarkista(luku, lista, sijainti);
    if (flag == 1){
        lista[sijainti] = luku;
        return 1;
    }
    return 0;
}

int tarkista(int luku, int lista[], int sijainti){
    int i;
    for (i = 0; i < sijainti; i++){
        if(luku == lista[i]){
            return 0;
        }
    }
    return 1;
}
