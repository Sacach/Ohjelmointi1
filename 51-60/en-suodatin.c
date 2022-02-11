#include <stdio.h>
#include <string.h>

int main() {
    char mjono[5][100];
    int i;
    for(i = 0; i < 5; i++){
        printf("Anna merkkjono (max 100 merkkia) > ");
        fgets( mjono[i], 100, stdin );
        mjono[i][strcspn(mjono[i], "\n")] = 0;
    }
    for(i = 0; i < 5; i++){
        if(mjono[i][strlen(mjono[i])-1] == 'n' && mjono[i][strlen(mjono[i])-2] == 'e' ){
            printf("\"en\"-merkkijonoon paattyva merkkijono \"%s\"\n", mjono[i]);
        }
    }

    return 0;
}
