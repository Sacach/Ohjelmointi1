#include <stdio.h>

int main() {
    char mjono[5][100];
    int i;
    for(i = 0; i < 5; i++){
        printf("Anna merkkjono (max 100 merkkia) > ");
        fgets( mjono[i], 100, stdin );
        mjono[i][strcspn(mjono[i], "\n")] = 0;
    }
    for(i = 0; i < 5; i++){
        if(mjono[i][0] == 'a'){
            printf("\"a\"-merkilla alkava merkkijono \"%s\"\n", mjono[i]);
        }
    }

    return 0;
}
