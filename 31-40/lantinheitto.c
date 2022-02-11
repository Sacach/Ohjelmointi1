#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int i, x, klaava = 0, kruuna = 0;

    srand(time(NULL));

    for (i = 0; i < 100; i++){
        x = rand() % 2;
        if (x == 1){
            klaava = klaava + 1;
        }
        else{
            kruuna = kruuna + 1;
        }
    }
    printf("Heittojen tulos: %d kruunua ja %d klaavaa", kruuna, klaava);
    return 0;
}
