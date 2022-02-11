#include <stdio.h>
#include <math.h>

int korotaKokonaislukuPotenssiin (int luku, int potenssi);

int main()
{
    int luku, potenssi, korotettu;
    scanf("%d", &luku);
    scanf("%d", &potenssi);

    korotettu = korotaKokonaislukuPotenssiin(luku, potenssi);

    printf("Luku %d korotettuna potenssiin %d on %d", luku, potenssi, korotettu);
    return 0;
}
int korotaKokonaislukuPotenssiin (int luku, int potenssi){
    int x = 1;
    for (;potenssi > 0; potenssi--){
        x = x * luku;
    }
    return x;

}

