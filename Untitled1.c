#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int syote = 0;
    scanf("%d\n", &syote);
    printf("%d\n", syote);
    printf("%d\n", isalpha(syote));
    while(isalpha(syote) != 0){
        scanf("%d\n", &syote);
        printf("%d\n", syote);
        printf("%d\n", isalpha(syote));
        //fgets(&syote, 10, stdin);

    }

    return 0;
}
