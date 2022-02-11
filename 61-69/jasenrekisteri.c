#include <stdio.h>
#include <string.h>
#define NIMEN_PITUUS 256

typedef struct {
   char etunimi[NIMEN_PITUUS];
   char sukunimi[NIMEN_PITUUS];
   int jnro;
   int lvuosi;
   int maksut[5];
} JasenTiedot;

void lajittele( JasenTiedot lista[], int n );
JasenTiedot lueJasenenTiedot(void);
void tulostaJasen(JasenTiedot jt);
void lueRoskat(void);
void poistaJasen(JasenTiedot lista[], int nro, int jasenmaara);
void paivitaTiedot(JasenTiedot lista[], int nro, int jasenmaara);
void haejasen(JasenTiedot lista[], int nro, int jasenmaara);

int main() {
    JasenTiedot jasenet[100];
    int valinta = 0, i, jasenmaara = 0;
    while(valinta != 7){
        printf("\n1 Uuden jasenen lisaaminen\n");
        printf("2 Jasenen tietojen poisto\n");
        printf("3 Jasenen tietojen muuttaminen\n");
        printf("4 Tulosta jasen\n");
        printf("5 Tulosta rekisteri\n");
        printf("6 Haku\n");
        printf("7 Lopetus\n\n");

        printf("Valintasi > \n");
        scanf("%d", &valinta);

        switch(valinta){
            case 1:
                jasenet[jasenmaara] = lueJasenenTiedot();
                jasenmaara++;
                break;
            case 2:
                printf("\nAnna poistettavan jasenen jasennumero > \n");
                scanf("%d", &valinta);
                poistaJasen(jasenet, valinta, jasenmaara);
                jasenmaara--;
                break;
            case 3:
                printf("\nAnna muutettavan jasenen jasennumero > \n\n");
                scanf("%d", &valinta);
                paivitaTiedot(jasenet, valinta, jasenmaara);
                break;
            case 4:
                printf("\nAnna jasennumero > \n");
                scanf("%d", &valinta);
                for(i = 0; i < jasenmaara; i++){
                    //tulostaJasen(jasenet[i]);
                    //printf("jasenet[i].jnro: %d \n", jasenet[i].jnro);
                    //printf("jasenmaara: %d\n", jasenmaara);
                    if (valinta == jasenet[i].jnro){
                        tulostaJasen(jasenet[i]);
                        i = jasenmaara;
                    }

                }

                break;
            case 5:
                for(i = 0; i < jasenmaara; i++){
                    tulostaJasen(jasenet[i]);
                }
                break;
            case 6:
                printf("1 Haku etunimella\n");
                printf("2 Haku sukunimella\n");
                printf("3 Haku jasennumerolla\n");
                printf("4 Haku liittymisvuodella\n");
                printf("5 Tulosta rekisteri\n");
                printf("5 Haku jasenmaksurastien perusteella\n");

                printf("Valintasi > \n");
                scanf("%d", &valinta);
                haejasen(jasenet, valinta, jasenmaara);
                break;
            case 7:
                //printf("Ohjelma sulkeutuu\n");
                break;
            default:
                printf("Anna syote valilta 1-7\n");
                break;
        }

    }
    return 0;
}
void haejasen(JasenTiedot lista[], int nro, int jasenmaara){
    int i, j;
    char nimi[256];
    switch(nro){
            case 1:
                printf("Anna etunimi > \n");
                scanf("%s", nimi);
                for(i = 0; i < jasenmaara; i++){
                    if (nimi == lista[i].etunimi){
                        tulostaJasen(lista[i]);
                        i = jasenmaara;
                    }
                }
                break;
            case 2:
                printf("Anna sukunimi > \n");
                scanf("%s", nimi);
                for(i = 0; i < jasenmaara; i++){
                    if (nimi == lista[i].sukunimi){
                        tulostaJasen(lista[i]);
                        i = jasenmaara;
                    }
                }
                break;
            case 3:
                printf("Anna jasennumero > \n");
                scanf("%d", nro);
                for(i = 0; i < jasenmaara; i++){
                    if (nro == lista[i].jnro){
                        tulostaJasen(lista[i]);
                        i = jasenmaara;
                    }
                }
                break;
            case 4:
                printf("Anna liittymisvuosi > \n");
                scanf("%d", nro);
                for(i = 0; i < jasenmaara; i++){
                    if (nro == lista[i].lvuosi){
                        tulostaJasen(lista[i]);
                        i = jasenmaara;
                    }
                }
                break;
            case 5:
                for(i = 0; i < jasenmaara; i++){
                    for (j = 0; j < 5; j++){
                        if (lista[i].maksut[j] == 0){
                            tulostaJasen(lista[i]);
                            i = jasenmaara;
                        }
                    }
                }
                break;
    }
}
void paivitaTiedot(JasenTiedot lista[], int nro, int jasenmaara){
    int i, j, valinta;
    printf("1 Muuta etunimi\n");
    printf("2 Muuta sukunimi\n");
    printf("3 Muuta jasennumero\n");
    printf("4 Muuta liittymisvuosi\n");
    printf("5 Muuta jasenmaksutietoja\n\n");
    printf("Valintasi > \n");
    scanf("%d", &valinta);

    for(i = 0; i < jasenmaara; i++){
        if (nro == lista[i].jnro){
            switch(valinta){
                case 1:
                    printf("\nAnna uusi etunimi  > \n");
                    scanf("%s", lista[i].etunimi);
                    //tulostaJasen(lista[i]);
                    break;
                case 2:
                    printf("\nAnna uusi sukunimi  > \n");
                    scanf("%s", lista[i].sukunimi);
                    break;
                case 3:
                    printf("\nAnna uusi jasennumero > \n");
                    scanf("%d", &lista[i].jnro);
                    break;
                case 4:
                    printf("\nAnna uusi liittymisvuosi > \n");
                    scanf("%d", &lista[i].lvuosi);
                    break;
                case 5:
                    for (j = 0; j < 5; j++){
                        printf("\nAnna vuoden %d jasenmaksu > \n", j + 2016);
                        scanf("%d", &lista[i].maksut[j]);
                    }
                    break;
            }
            i = jasenmaara;
        }
    }
}
void poistaJasen(JasenTiedot lista[], int nro, int jasenmaara){
    int i, j;
    JasenTiedot temp;
    for(i = 0; i < jasenmaara; i++){
        if (nro == lista[i].jnro){
            lista[i] = lista[i+1];
            for (j = i+1; j < jasenmaara; j++){
                lista[j] = lista[j+1];
            }
            i = jasenmaara;
        }
    }
}
JasenTiedot lueJasenenTiedot(void){
    JasenTiedot jt;
    int i;
    lueRoskat();
    printf("\nAnna Jasenen Etu- ja Sukunimi  > \n");
    scanf("%s %s", jt.etunimi, jt.sukunimi);


    printf("\nAnna jasennumero > \n");
    scanf("%d", &jt.jnro);


    printf("\nAnna liittymisvuosi > \n");
    scanf("%d", &jt.lvuosi);

    for (i = 0; i < 5; i++){
        printf("\nAnna vuoden %d jasenmaksu > \n", i + 2016);
        scanf("%d", &jt.maksut[i]);
    }
    return(jt);
}

void tulostaJasen(JasenTiedot jt){
    printf("\n   ETUNIMI: %s\n", jt.etunimi);
    printf("  SUKUNIMI: %s\n", jt.sukunimi);
    printf("  JASENNRO: %d\n", jt.jnro);
    printf("LIITTVUOSI: %d\n", jt.lvuosi);
    printf("\n\n");
}

void lueRoskat(void){

   // Tyhjennet‰‰n puskuri
   while( fgetc(stdin) != '\n');
}
