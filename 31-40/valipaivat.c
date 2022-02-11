#include <stdio.h>
Paivat = 0;

int karkausvuosi(double vuosiluku);
int plkmKk (int kk, double vuosiluku);
int vertaapvm(int ap, int akk, int av, int lp, int lkk, int lv);
int laskepaivat(int alku, int loppu);

int main(void){
    int vuosi_a, kuukausi_a, paiva_a,
    vuosi_l, kuukausi_l, paiva_l;

    printf("Anna vuosiluku:\n");
    scanf("%d", &vuosi_a);
    printf("Anna kk:\n");
    scanf("%d", &kuukausi_a);
    printf("Anna päivä:\n");
    scanf("%d", &paiva_a);

    printf("Anna vuosiluku:\n");
    scanf("%d", &vuosi_l);
    printf("Anna kk:\n");
    scanf("%d", &kuukausi_l);
    printf("Anna päivä:\n");
    scanf("%d", &paiva_l);
    vertaapvm(paiva_a, kuukausi_a, vuosi_a, paiva_l, kuukausi_l, vuosi_l);
}

int vertaapvm(int ap, int akk, int av, int lp, int lkk, int lv){
    int temp_kk, temp_v;


    if(av > lv){
        printf("Aloitusvuosi on myohempi kuin lopetusvuosi\n");
    }
    else if(av == lv && akk > lkk){
        printf("Koska aloitusvuosi on sama kuin lopetusvuosi\n");
        printf("niin, aloituskuukausi ei voi olla suurempi kuin lopetuskuukausi!\n");
    }
    else if(av == lv  && akk == lkk && ap > lp){
        printf("Koska aloitusvuosi on sama kuin lopetusvuosi\n");
        printf("ja aloituskuukausikin on sama kuin lopetuskuukausi\n");
        printf("niin aloituspaiva ei voi olla suurempi kuin lopetuspaiva!\n");
    }
    else if(av == lv  && akk == lkk && ap == lp){
        printf("Paivaykset ovat samat!\n");
    }
    else{


        if (av == lv  && akk < lkk){
            Paivat = Paivat + plkmKk(akk, av)- ap;

            for (temp_kk = akk + 1; temp_kk < lkk; temp_kk++){
                Paivat = Paivat + plkmKk(temp_kk, lv);
            }
            Paivat = Paivat + lp;
        }

        else if(av == lv  && akk == lkk){
            Paivat = Paivat + plkmKk(akk, av)- ap;

        }
        else{
            Paivat = Paivat + plkmKk(akk, av)- ap;
            for (temp_kk = akk + 1; temp_kk < 13; temp_kk++){
                Paivat = Paivat + plkmKk(temp_kk, av);
            }

            for (temp_v = av + 1; temp_v < lv; temp_v++){
                Paivat = Paivat + karkausvuosi(temp_v);
            }
            for (temp_kk = 1; temp_kk < lkk; temp_kk++){
                Paivat = Paivat + plkmKk(temp_kk, lv);
            }
            Paivat = Paivat + lp;
        }
        printf("%d.%d.%d ja %d.%d.%d valilla on %d paivaa", av, akk, ap, lv, lkk, lp, Paivat);


    }
}



int karkausvuosi(double vuosiluku){

    if ((vuosiluku / 400) == (int)(vuosiluku / 400)){
        //printf("(vuosiluku / 400) % 1 == 0\n");
        //printf("Vuosi %d on karkausvuosi\n", (int)vuosiluku);
        return 366;
    }
    else if ((vuosiluku / 4) == (int)(vuosiluku / 4)){
        if ((vuosiluku / 100) == (int)(vuosiluku / 100)){
            //printf("(vuosiluku / 100) % 1 == 0\n");
            //printf("Vuosi %d ei ole karkausvuosi\n", (int)vuosiluku);
            return 365;
        }
        else{
            //printf("(vuosiluku / 4) % 1 == 0)\n", vuosiluku);
            //printf("Vuosi %d on karkausvuosi\n", (int)vuosiluku);
            return 366;
        }
    }
    else{
        //printf("Vuosi %d ei ole karkausvuosi\n", (int)vuosiluku);
        return 365;
    }

}
int plkmKk (int kk, double vuosiluku){
    switch(kk){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            //printf("Kuukaudessa %d on %d paivaa\n", kk, 31);
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            //printf("Kuukaudessa %d on %d paivaa\n", kk, 30);
            return 30;

        case 2:
            if(karkausvuosi(vuosiluku) == 366){
                //printf("Kuukaudessa %d on %d paivaa\n", kk, 29);
                return 29;
            }
            else{
                //printf("Kuukaudessa %d on %d paivaa\n", kk, 28);
                return 28;
            }


        default:
            printf("Kuukautta %d ei ole olemassa\n", kk);
    }
}
