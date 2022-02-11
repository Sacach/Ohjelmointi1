#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int i, j;
    char vastaus;
    srand(time(NULL));
    i = (rand() % 100) + 1;
    printf("arvaa luku valilta 1-100\n");
    while(vastaus != 'e'){
        scanf("%d", &j);
        //printf("%d\n", i);

        if (j == i){
            printf("OIKEIN!\n");
            printf("Haluatko yrittaa uudelleen (vastaa k, jos haluat jatkaa ja e jos et halua jatkaa pelia)?\n");
            while(1){
                scanf("%c", &vastaus);
                //printf("%c\n", vastaus);
                if (vastaus == 'k'){
                    i = (rand() % 100) + 1;
                    printf("arvaa luku valilta 1-100\n");
                    break;
                }
                else if(vastaus == 'e'){
                    break;
                }
            }
        }
        else if(j < i){
            printf("Liian pieni luku, yrita uudelleen.\n");
        }
        else{
            printf("Liian suuri luku, yrita uudelleen.\n");
        }

    }

    return 0;
}
