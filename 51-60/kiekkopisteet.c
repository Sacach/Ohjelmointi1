#include <stdio.h>
#include <string.h>
#define NIMEN_PITUUS 256

typedef struct {
   char nimi[NIMEN_PITUUS];
   int voitot;
   int haviot;
} JoukkueTiedot;

void lajittele( JoukkueTiedot lista[], int n );
JoukkueTiedot lueJoukkueenTiedot(void);
void tulostaJoukkue(JoukkueTiedot jt, int sija);
void lueRoskat(void);

int main() {

    int maara, i;
    printf("Anna joukkueiden maara:\n");
    scanf("%d", &maara);

    JoukkueTiedot joukkueet[maara];

    for(i = 0; i < maara; i++){
        joukkueet[i] = lueJoukkueenTiedot();
    }
    lajittele(joukkueet, maara);
    printf("\n****************************************\n");
    printf("         TULOSLISTA");
    printf("\n****************************************\n");

    for(i = 0; i < maara; i++){
        tulostaJoukkue(joukkueet[i], i+1);
    }
    return 0;
}
JoukkueTiedot lueJoukkueenTiedot(void){
    JoukkueTiedot jt;
    lueRoskat();
    printf("Anna joukkueen nimi:\n");
    fgets(jt.nimi, sizeof(jt.nimi), stdin);
    jt.nimi[strcspn(jt.nimi, "\n")] = 0;

    printf("Anna joukkueen voitot:\n");
    scanf("%d", &jt.voitot);

    printf("Anna joukkueen haviot:\n");
    scanf("%d", &jt.haviot);

    return(jt);
}

void tulostaJoukkue(JoukkueTiedot jt, int sija){
    printf("%d. joukkue:          ", sija);
    printf("%s tilanne: ", jt.nimi);
    printf("%d voittoa ja ", jt.voitot);
    printf("%d tappiota\n", jt.haviot);

}

void lajittele(  JoukkueTiedot lista[], int n ){
    int paikka, i, j, vh1, vh2;
    JoukkueTiedot temp;
    for(i = 0; i < n; i++){
        paikka = i;
        for(j = i+1; j < n; j++){
            vh1 = lista[paikka].voitot - lista[paikka].haviot;
            vh2 = lista[j].voitot - lista[j].haviot;
            if(vh1 < vh2){
                paikka = j;
            }
        }
        if (paikka != i){
            temp = lista[paikka];
            lista[paikka] = lista[i];
            lista[i] = temp;
        }

    }

}
void lueRoskat(void){

   // Tyhjennetään puskuri
   while( fgetc(stdin) != '\n');
}
