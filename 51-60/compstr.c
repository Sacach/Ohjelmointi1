#include <stdio.h>
#include <string.h>

int omaStrcmp(  char mjono1[100], char mjono2[100]);

int main() {
    char mjono[2][100];
    int i, vertaus;
    for(i = 0; i < 2; i++){
        printf("Anna merkkjono (max 100 merkkia) > ");
        fgets( mjono[i], 100, stdin );
        mjono[i][strcspn(mjono[i], "\n")] = 0;
    }
    vertaus = omaStrcmp(mjono[0], mjono[1]);
    if(vertaus == 0){
        printf("%s == %s", mjono[0], mjono[1]);
    }
    else if(vertaus == 1){
        printf("%s > %s", mjono[0], mjono[1]);
    }
    else if(vertaus == -1){
        printf("%s < %s", mjono[0], mjono[1]);
    }
    else if(vertaus == 2){
        printf("%s < %s", mjono[0], mjono[1]);
    }

    return 0;
}

int omaStrcmp( char mjono1[100], char mjono2[100]){
    int i;

    for(i = 0; i < strlen(mjono1); i++){
        if (strlen(mjono1) < strlen(mjono2)){

            return 2;
        }
        else if (mjono1[i] < mjono2[i]){
            return -1;
        }
        else if (mjono1[i] > mjono2[i]){
            return 1;
        }

    }
    return 0;
}
