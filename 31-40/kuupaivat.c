#include <stdio.h>
int paivienLukumaaraKuukaudessa (int kk);



int main(void){
    int kk;
    printf("Anna kuukauden järjestysnumero:\n");
    scanf("%d", &kk);
    paivienLukumaaraKuukaudessa(kk);
}

int paivienLukumaaraKuukaudessa (int kk){
    switch(kk){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Kuukaudessa %d on %d paivaa\n", kk, 31);
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            printf("Kuukaudessa %d on %d paivaa\n", kk, 30);
            break;

        case 2:
            printf("Kuukaudessa %d on %d paivaa\n", kk, 28);
            break;

        default:
            printf("Kuukautta %d ei ole olemassa\n", kk);
    }
}
