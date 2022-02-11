#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int oikein = 0, vaarin = 0;

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
    printf("Sait %d vastausta oikein, ja %d meni pikkuisen pieleen\n", oikein, vaarin);
    if(oikein >= vaarin){
        printf("Arvosanasi on : \"Hyvaksytty\"\n");
    }
    else{
        printf("Arvosanasi on : \"Hylatty\"\n");
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
            oikein = oikein + 1;
        }
        else{
            printf("Väärin, yritä uudelleen > \n");
            vaarin = vaarin + 1;
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
            oikein = oikein + 1;
        }
        else{
            printf("Väärin, yritä uudelleen > \n");
            vaarin = vaarin + 1;
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
