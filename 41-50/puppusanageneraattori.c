#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MAARA = 5;


int main() {
    char substantiivit[MAARA][101], verbit[MAARA][101];
    int i, lausemaara, randluku, a, b, c, d;

    srand(time(NULL));

    for(i = 0; i < MAARA; i++){
        printf("Anna substantiivi (max 100 merkkia) > ");
        fgets( substantiivit[i], 101, stdin );

        printf("Anna verbi (max 100 merkkia) > ");
        fgets( verbit[i], 101, stdin );
    }
    printf("Montako puppulausetta generoidaan > ");
    scanf("%d", &lausemaara);
    printf("---Puppulauseet---\n");

    for(i = 0; i < lausemaara; i++){
        randluku = rand() % 4;
        switch(randluku){
            case 0:
                a = rand() % 5;
                b = rand() % 5;
                printf("%c%s %s.\n", toupper(substantiivit[a][0]), substantiivit[a] + 1, verbit[b]);
                break;
            case 1:
                a = rand() % 5;
                b = rand() % 5;
                c = rand() % 5;
                d = rand() % 5;
                printf("%c%s %s ja %s %s.\n", toupper(substantiivit[a][0]), substantiivit[a] + 1, verbit[b], substantiivit[c], verbit[d]);
                break;
            case 2:
                a = rand() % 5;
                b = rand() % 5;
                c = rand() % 5;
                d = rand() % 5;
                printf("%c%s %s tai %s %s.\n", toupper(substantiivit[a][0]), substantiivit[a] + 1, verbit[b], substantiivit[c], verbit[d]);
                break;
            case 3:
                a = rand() % 5;
                b = rand() % 5;
                c = rand() % 5;
                d = rand() % 5;
                printf("Jos %s %s, niin %s %s.\n", substantiivit[a], verbit[b], substantiivit[c], verbit[d]);
                break;

        }
    }


    return 0;
}
