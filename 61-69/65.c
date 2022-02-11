#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char teksti1[20], teksti2[20], flag = 1;
    int merkki, merkki2;
    scanf("%s", teksti1);
    scanf("%s", teksti2);


    FILE *t1 = fopen(teksti1, "r");

    FILE *t2 = fopen(teksti2, "r");

    if( (t1=fopen(teksti1, "r"))==NULL ){
           printf("Tiedoston 1 avaaminen lukemista varten epäonnistui.\n");
    }
    else if( (t2=fopen(teksti2, "r"))==NULL ){
           printf("Tiedoston 2 avaaminen lukemista varten epäonnistui.\n");
    }
    else {
        for(merkki = fgetc(t1); merkki != EOF; merkki = fgetc(t1) ){
            merkki2 = fgetc(t2);
            if(merkki != merkki2){
                flag = 0;
            }
            else{
                flag = 1;
            }
        }
    }
    // close the file
    fclose(t1);
    fclose(t2);
    if (flag == 1){
        printf("Tiedostot ovat sisällöltään identtiset.");
    }
    else{
        printf("Tiedostot eivät ole sisällöltään identtiset.");
    }
    return 0;
}
