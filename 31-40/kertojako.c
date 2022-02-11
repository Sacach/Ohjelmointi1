#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tyhjennapuskuri(void);
int lueint(void);
int kerto(int i, int j);
int jako(int i, int j);

int main(){
    int vastaus = 0, i, j, k;

    srand(time(NULL));
    while(vastaus != -1){
        i = (rand() % 9) + 1;
        j = (rand() % 9) + 1;
        k = rand() % 2;
        if (k == 1){
            vastaus = kerto(i, j);
        }
        else{
            vastaus = jako(i, j);
        }
    }

    return 0;
}

int kerto(int i, int j){
    int vastaus = 0;
    printf("Anna luku -1 lopettaaksesi\n");
    printf("Paljonko on %d kertaa %d? \n", i, j);

    while(vastaus != i * j){
        vastaus = lueint();

        if (vastaus == -1){
            return -1;
        }
        else if (vastaus == i * j){
            printf("Oikein!\n");
        }
        else{
            printf("Väärin, yritä uudelleen > \n");
        }
    }
}
int jako(int i, int j){
    int vastaus = 0;
    printf("Anna luku -1 lopettaaksesi\n");
    printf("Paljonko on %d jaettuna %d? \n", i*j, i);

    while(vastaus != j){
        vastaus = lueint();

        if (vastaus == -1){
            return -1;
        }
        else if (vastaus == j){
            printf("Oikein!\n");
        }
        else{
            printf("Väärin, yritä uudelleen > \n");
        }
    }
}


void tyhjennapuskuri(void){
    while(fgetc(stdin) != '\n');
}
int lueint(void){
    double luku;
    int result;
    char merkki;

    while((result=scanf("%lf%c", &luku, &merkki))<= 0 || result == 2 && merkki != '\n'){
        tyhjennapuskuri();
        printf("%lf\n", luku);
        printf("Ei ollut reaaliluku\n");
    }
    return luku;
}
