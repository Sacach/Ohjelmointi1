#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lisaa_arvo(int lista[], int sijainti);
int tarkista(int luku, int lista[], int sijainti);
void tulostus(int lista[], int koko);

int main(){
    int list[20], i = 0, flag;
    srand(time(NULL));
    while(i < 20){
        flag = lisaa_arvo(list, i);
        if (flag == 1){
            i = i + 1;
        }
    }
    tulostus(list, 20);

}
void tulostus(int lista[], int koko){
    int i;
    for(i = 0; i < koko; i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int lisaa_arvo(int lista[], int sijainti){
    int luku, flag;
    luku = rand() % 20 + 1;
    flag = tarkista(luku, lista, sijainti);
    if (flag == 1){
        lista[sijainti] = luku;
        return 1;
    }
    return 0;
}
int tarkista(int luku, int lista[], int sijainti){
    int i;
    printf("luku: %d \n", luku);
    printf("sijainti %d \n", sijainti);
    for (i = 0; i < sijainti; i++){

        printf("lista %d \n", lista[i]);
        if(luku == lista[i]){
            return 0;
        }
    }
    return 1;
}
