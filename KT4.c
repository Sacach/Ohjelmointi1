#include <stdio.h>
//globaalit muuttujat
double Saldo = 1000;
//Funktioiden alustus
void tyhjennapuskuri(void);
int lueint(void);
int otto(void);
int liit_lataus(void);
void saldo(void);
int mainloop(void);
int rahojen_jako(int nosto);
/*
main funktio, jossa kysytään kortin numero ja tunnusluku käyttäjältä
tämän jälkeen mennäään mainooppiin, josta poistuttaessa kiitetään käyttäjää ja kehotetaan ottamaan kortti
*/
int main(void){
    int kortti,
    tluku;

    printf("Anna kortin numero:\n");
    kortti = lueint();
    printf("Anna tunnusluku:\n");
    tluku = lueint();
    mainloop();

    return 1;
}
/*
rahojen_jako funktio sisältää algoritmin jolla selvitetään montako 50e ja 20e seteliä käyttäjälle täytyy antaa
*/
int rahojen_jako(int nosto){
    int isotsetelit, setelit, nostosumma;
    while (nosto){
        if (nosto > 1000){
            printf("Nostoraja on 1000 euroa\nAnna pienempi nostosumma\n");
            nosto = lueint();
        }
        else{
            switch((nosto - 50) % 50){
                case 0:
                    isotsetelit = nosto / 50;
                    //printf("isotsetelit: %d\n", isotsetelit);
                    setelit = 0;
                    nostosumma = nosto;
                    nosto = 0;
                    break;

                case 10:
                    isotsetelit = nosto / 50 - 1;
                    //printf("isotsetelit: %d\n", isotsetelit);
                    setelit = 3;
                    nostosumma = nosto;
                    nosto = 0;
                    break;

                case 20:
                    isotsetelit = nosto / 50;
                    //printf("isotsetelit: %d\n", isotsetelit);
                    setelit = 1;
                    nostosumma = nosto;
                    nosto = 0;
                    break;

                case 30:
                    isotsetelit = nosto / 50 - 1;
                    //printf("isotsetelit: %d\n", isotsetelit);
                    setelit = 4;
                    nostosumma = nosto;
                    nosto = 0;
                    break;

                case 40:
                    isotsetelit = nosto / 50;
                    //printf("isotsetelit: %d\n", isotsetelit);
                    setelit = 2;
                    nostosumma = nosto;
                    nosto = 0;
                    break;

                default:
                    if (nosto == 20 || nosto == 40){
                        isotsetelit = 0;
                        setelit = nosto / 20;
                        nostosumma = nosto;
                        nosto = 0;
                    }
                    else{
                        printf("Kyseistä nostosummaa ei voi jakaa 50 euron ja 20 euron seteleihin\nAnna uusi nostosumma\n");
                        nosto = lueint();
                    }
            }

        }
    }
    printf("Rahat tulossa\n");
    printf("%d euroa\n", nostosumma);
    printf("%d kpl 50e seteliä ja %d kpl 20e seteliä\n", isotsetelit, setelit);
    Saldo = Saldo - nostosumma;

}
/*
otto käsittelee tapahtuman kun käyttäjä valitsee oton
funktiossa valitaan nostettava summa näppäimistön syötteenä
tai palataan päävalikkoon
*/
int otto(void){
    int valinta;

    while(valinta != -2){
        printf("Valitse 20, 40, 60, 90, 140, 240, Muu(-1), palaa(-2)\n");
        valinta = lueint();
        if (valinta == 20 || valinta == 40 || valinta == 60 || valinta == 90 || valinta == 140 || valinta == 240){

            rahojen_jako(valinta);

            printf("Valitse Kuitti(1), Naytolle(2), Ei kiitos(3)\n");
            valinta = lueint();
            printf("Ota rahat\n");
            return 0;
        }
        else if (valinta == -1){
            printf("Anna summa\n");
            valinta = lueint();

            rahojen_jako(valinta);

            printf("Valitse Kuitti(1), Naytolle(2), Ei kiitos(3)\n");
            valinta = lueint();
            printf("Ota rahat\n");
            return 0;
        }

        else{
            if (valinta == -2){
                return 1;
            }
            else{
                printf("virheellinen syote\n");
            }
        }
    }
}
/*
liit_lataus käsittelee tapahtuman kun käyttäjä valitsee ladata rahaa liittymäänsä
funktiossa valitaan puhelinnumero jolle ladataan varoja ja ladattava summa näppäimistön syötteenä
*/
int liit_lataus(void){
    int valinta, puhelin;
    printf("Valitse Alkuun(1), Saunalahti(2), dna Go mobile(3)\n");
    valinta = lueint();
    if (valinta == 1){
    }
    else{
        printf("Anna puh.numero ja paina enter\n");
        puhelin = lueint();
        printf("Anna summa tai palaa alkuun(-1)\n");
        valinta = lueint();
        if (valinta == -1){
        }
        else if (valinta > 0){
            Saldo = Saldo - valinta;
            printf("maksu suoritettu vahvistus tekstiviestilla\n");
        }
        else{
            printf("toiminto keskeytetty\n");
        }
    }
    return 1;
}
/*
saldo funktio näyttää saldon ja lopettaa kun käyttäjä antaa jonkin syötteen
*/
void saldo(void){
    char syote[8];
    printf("Saldo: %.2lf euroa\n", Saldo);
    printf("lopeta(anna jokin syote)\n");
    scanf("%s", &syote);
}
/*
päälooppi, jossa pysytään kunnes nosto on suoritettu tai käyttäjä valitsee stop vaihtoehdon

*/
int mainloop(void){
    int valinta;


    while (valinta != 5){
        printf("Valitse Otto(1), Saldo(2), Tapahtumat(3), Liittyman lataus(4) tai Stop(5)\n");
        valinta = lueint();

        if (valinta == 1){
            otto();

        }
        else if (valinta == 2){
            saldo();
        }

        else if (valinta == 3){
           printf("Valitse Naytolle(1), Kuitille(2)\n");
           valinta = lueint();
           printf("Tapahtumat:\n");
           printf("300 euroa      matkapuhelin\n");
           printf("30 euroa       liittyman lataus\n");
        }

        else if (valinta == 4){
            liit_lataus();
        }

        else if (valinta == 5){
            printf("Kiitos kaynnista\n");
            printf("Ota kortti\n");
        }

        else{
             printf("virheellinen syote\n");
        }

    }
    return 1;
}



void tyhjennapuskuri(void){
    while(fgetc(stdin) != '\n');
}
int lueint(void){
    int luku;
    int result;
    char merkki;

    //printf("Anna kokonaisluku > \n");

    while((result=scanf("%d%c", &luku, &merkki))<= 0 || result == 2 && merkki != '\n'){
        tyhjennapuskuri();
        printf("virheellinen syote\n");
    }
    return luku;
}
