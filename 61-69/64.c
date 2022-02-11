#include <stdio.h>

int main(){
    FILE *teksti = fopen("teksti.txt", "r");
    int rivit = 1, merkit = 32;
    char merkki;
    if (teksti == NULL)
    {
        printf("Error: could not open file");
        return 1;
    }
    while ((merkki = fgetc(teksti)) != EOF){
        if(merkki == '\n'){
            rivit = rivit + 1;
        }
        else{
            merkit = merkit + 1;
        }
    }
    // close the file
    fclose(teksti);
    printf("Rivit: %d\n", rivit);
    printf("Merkit: %d\n", merkit);
    return 0;
}
