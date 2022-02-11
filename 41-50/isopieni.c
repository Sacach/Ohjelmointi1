#include <stdio.h>
#include <string.h>

void convertNprint(int upperlower, char mjono[101]);

int main () {
    char  merkkijono[101] = {0};

    printf("Anna merkkijono >");
    fgets( merkkijono, 101, stdin );

    convertNprint(0, merkkijono);
    convertNprint(1, merkkijono);

 return ( 0 );
}

void convertNprint(int upperlower, char mjono[101]){
    int i;

    if (upperlower == 0){

        for(i = 0; i < 100; i++){

            if(mjono[i] >= 65 && mjono[i] <= 90){

                printf("%c", mjono[i] + 32);
            }
            else if(mjono[i] >= 97 && mjono[i] <= 122){

                printf("%c", mjono[i]);
            }
            else if(mjono[i] >= 45 && mjono[i] <= 57){
                printf("%c", mjono[i]);
            }

        }
        printf("\n");
    }
    else{
        for(i = 0; i < 100; i++){
            if(mjono[i] >= 65 && mjono[i] <= 90){

                printf("%c", mjono[i]);
            }
            else if(mjono[i] >= 97 && mjono[i] <= 122){

                printf("%c", mjono[i] - 32);
            }
            else if(mjono[i] >= 45 && mjono[i] <= 57){
                printf("%c", mjono[i]);
            }

        }
        printf("\n");
    }
}
