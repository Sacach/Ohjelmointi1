#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char teksti1[20], merkki, syote;
    int i;
    scanf("%s", teksti1);

    FILE *file = fopen(teksti1, "r");
    if( (file=fopen(teksti1, "r"))==NULL ){
           printf("Tiedoston avaaminen lukemista varten epäonnistui.\n");
    }
    else {
        while(merkki != EOF || syote != 'Q'){
            i = 0;
            syote = fgetc(stdin);
            if( syote != 'Q'){
                while(i < 20){
                    //printf("\ni: %d\n",i);
                    merkki = fgetc(file);
                    if(merkki == EOF){
                        break;
                    }
                    printf("%c", merkki);
                    if(merkki == '\n'){
                        i++;
                    }
                }
            }
            if(merkki == EOF){
                        break;
            }
        }
    }

    fclose(file);

    return 0;
}
