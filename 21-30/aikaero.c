#include <stdio.h>

int laskesekunnit(int tunnit, int minuutit, int sekunnit);

int main(){
    int tunnit, minuutit, sekunnit, aika, aika1, aika2;

    printf("anna tunnit\n");
    scanf("%d", &tunnit);

    printf("anna minuutit\n");
    scanf("%d", &minuutit);

    printf("anna sekunnit\n");
    scanf("%d", &sekunnit);
    aika1 = laskesekunnit(tunnit, minuutit, sekunnit);

    printf("anna tunnit\n");
    scanf("%d", &tunnit);

    printf("anna minuutit\n");
    scanf("%d", &minuutit);

    printf("anna sekunnit\n");
    scanf("%d", &sekunnit);
    aika2 = laskesekunnit(tunnit, minuutit, sekunnit);

    if (aika1 > aika2){
        aika = aika1 - aika2;
    }
    else{
        aika = aika2 - aika1;
    }
    printf("Aikaero on: %d sekuntia\n", aika);
    tunnit = aika / 3600;
    minuutit = (aika % 3600) / 60;
    sekunnit = aika % 60;

    printf("Aika on %d tuntia %d minuuttia %d sekuntia\n", tunnit, minuutit, sekunnit);

    return 0;
}
int laskesekunnit(int tunnit, int minuutit, int sekunnit){
    int x;
    x = tunnit * 3600 + minuutit * 60 + sekunnit;
    return x;
}
