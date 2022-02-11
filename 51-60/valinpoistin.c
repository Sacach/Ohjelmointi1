#include <stdio.h>
#include <string.h>

void  poistaValilyonnit( char merkkijono[100], char siivottu[100]);

int main() {
    char mjono[3][100], siivottu[100];
    int i;
    for(i = 0; i < 3; i++){
        printf("Anna merkkjono (max 100 merkkia) > ");
        fgets( mjono[i], 100, stdin );
        mjono[i][strcspn(mjono[i], "\n")] = 0;
    }

    for(i = 0; i < 3; i++){
        poistaValilyonnit(mjono[i], siivottu);
        printf("%s\n", siivottu);
    }

    return 0;
}

void  poistaValilyonnit( char merkkijono[100], char siivottu[100]){
    int i, j = 0;
    for (i = 0; i < strlen(merkkijono); i++){

        if(merkkijono[i] == 32){

            j = j + 1;
        }
        else{
            siivottu[i-j] = merkkijono[i];
        }
    }
}
