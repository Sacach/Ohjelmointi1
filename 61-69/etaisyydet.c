#include <stdio.h>
#include <math.h>
typedef struct{
    double x;
    double y;
}koord;

double LaskeVali(koord piste1, koord piste2);

int main(){
    koord pisteet[5];
    int i;
    double matka = 0, lintu;
    printf("anna x-koordinaatti\n");
    scanf("%lf", &pisteet[0].x);

    printf("anna y-koordinaatti\n");
    scanf("%lf", &pisteet[0].y);
    for(i = 1; i<5; i++){

        printf("anna x-koordinaatti\n");
        scanf("%lf", &pisteet[i].x);

        printf("anna y-koordinaatti\n");
        scanf("%lf", &pisteet[i].y);

        matka = matka + LaskeVali(pisteet[i-1], pisteet[i]);
    }
    lintu = LaskeVali(pisteet[0], pisteet[4]);
    printf("Etäisyys mutkitellen on %.3lf\n", matka);
    printf("Alku ja loppupisteiden valinen etaisyys on %.3lf\n", lintu);
    return 0;
}

double LaskeVali(koord piste1, koord piste2){
    double vastaus;
    vastaus = sqrt(pow(piste1.x-piste2.x,2)+pow(piste1.y-piste2.y,2));
    return vastaus;
}
