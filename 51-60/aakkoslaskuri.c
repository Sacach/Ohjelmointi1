#include <stdio.h>
#include <string.h>

int main() {
    char mjono[3][100], kokojono[300] = {NULL};
    int i, aakkoset[26] = {0};
    for(i = 0; i < 3; i++){
        printf("Anna merkkjono (max 100 merkkia) > ");
        fgets( mjono[i], 100, stdin );
        mjono[i][strcspn(mjono[i], "\n")] = 0;
        strcat(kokojono, mjono[i]);
    }
    i = 0;
    while(i < strlen(kokojono)){

        if(kokojono[i] <= 90 && kokojono[i] >= 65){
            aakkoset[kokojono[i] - 65] = aakkoset[kokojono[i] - 65] + 1;
        }
        else if(kokojono[i] >= 97 && kokojono[i] <= 122){
            aakkoset[kokojono[i] - 97] = aakkoset[kokojono[i] - 97] + 1;
        }
    i++;
    }
    printf("Aakkonen        Kpl\n");
    for(i = 0; i < 26; i++){
        printf("%c               %d\n", i + 97, aakkoset[i]);
    }
    return 0;
}
