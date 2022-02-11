#include <stdio.h>

/*
otto k‰sittelee tapahtuman kun k‰ytt‰j‰ valitsee oton
funktiossa valitaan nostettava summa n‰pp‰imistˆn syˆtteen‰
tai palataan p‰‰valikkoon
*/
int otto(void){
    int valinta;

    while(1){
        printf("Valitse 20, 40, 60, 90, 140, 240, Muu(-1), palaa(-2)\n");
        scanf("%d", &valinta);
        if (valinta == -2){
            return 1;
        }

        else if (valinta == -1){
            printf("Anna summa\n");
            scanf("%d", &valinta);
            printf("Rahat tulossa\n");
            printf("%d euroa\n", valinta);
            printf("Valitse Kuitti(1), Naytolle(2), Ei kiitos(3)\n");
            scanf("%d", &valinta);
            printf("Ota rahat\n");
            return 0;
        }

        else{
            if (valinta == 20 || valinta == 40 || valinta == 60 || valinta == 90 || valinta == 140 || valinta == 240){
                printf("Rahat tulossa\n");
                printf("%d euroa\n", valinta);
                printf("Valitse Kuitti(1), Naytolle(2), Ei kiitos(3)\n");
                scanf("%d", &valinta);
                printf("Ota rahat\n");
                return 0;
            }
            printf("virheellinen syote\n");
        }

    }
}
/*
liit_lataus k‰sittelee tapahtuman kun k‰ytt‰j‰ valitsee ladata rahaa liittym‰‰ns‰
funktiossa valitaan puhelinnumero jolle ladataan varoja ja ladattava summa n‰pp‰imistˆn syˆtteen‰
*/
int liit_lataus(void){
    int valinta, puhelin;
    printf("Valitse Alkuun(1), Saunalahti(2), dna Go mobile(3)\n");
    scanf("%d", &valinta);
    if (valinta == 1){
    }
    else{
        printf("Anna puh.numero ja paina enter\n");
        scanf("%d", &puhelin);
        printf("Anna summa tai palaa alkuun(-1)\n");
        scanf("%d", &valinta);
        if (valinta == -1){
        }
        else{
            printf("maksu suoritettu vahvistus tekstiviestilla\n");
        }
    }
    return 1;
}
/*
p‰‰looppi, jossa pysyt‰‰n kunnes nosto on suoritettu tai k‰ytt‰j‰ valitsee stop vaihtoehdon

*/
int mainloop(void){
    int tulos,
    valinta;
    char syote;
    while (1){
        printf("Valitse Otto(1), Saldo(2), Tapahtumat(3), Liittyman lataus(4) tai Stop(5)\n");
        scanf("%d", &valinta);

        if (valinta == 1){
            tulos = otto();
            if(tulos == 0){
                break;
            }
        }
        else if (valinta == 2){
            printf("Saldo: 1000 euroa\n");
            printf("lopeta(anna jokin syote)\n");
            scanf("%s", &syote);
        }


        else if (valinta == 3){
           printf("Valitse Naytolle(1), Kuitille(2)\n");
           scanf("%d", &valinta);
           printf("Tapahtumat:\n");
           printf("300 euroa      matkapuhelin\n");
           printf("30 euroa       liittyman lataus\n");
        }

        else if (valinta == 4){
            liit_lataus();
        }

        else{
             if(valinta == 5){
                break;
             }
             printf("virheellinen syote\n");
             continue;
        }

    }
    return 1;
}
/*
main funktio, jossa kysyt‰‰n kortin numero ja tunnusluku k‰ytt‰j‰lt‰
t‰m‰n j‰lkeen menn‰‰‰n mainooppiin, josta poistuttaessa kiitet‰‰n k‰ytt‰j‰‰ ja kehotetaan ottamaan kortti
*/
int main(void){
    int kortti,
    tluku;

    printf("Anna kortin numero:\n");
    scanf("%d", &kortti);
    printf("Anna tunnusluku:\n");
    scanf("%d", &tluku);
    mainloop();

    printf("Kiitos kaynnista\n");
    printf("Ota kortti\n");
    return 1;
}
