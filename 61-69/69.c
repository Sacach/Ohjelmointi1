#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *ika;
    char *nimi;
    const char erotin[2] = ";";
    char temp[256];

    FILE *file;
    if( (file=fopen("nimet.txt", "r"))==NULL ){
           printf("Tiedoston avaaminen lukemista varten epäonnistui.\n");
    }
    else {
        while (fgets(temp, sizeof(temp), file)) {

            ika = strtok(temp, erotin);
            nimi = ika;
            ika = strtok(NULL, erotin);
            ika[strcspn(ika, "\n")] = 0;
            printf("%s %s\n", nimi, ika);
        }

    }
    fclose(file);

    return 0;
}
