#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PITUUS 101

int main()
{
    int i;
    char merkkiJono[PITUUS] = {0};

    printf("Anna merkkijono >");
    fgets(merkkiJono, PITUUS, stdin);

    for (i = 0; i < 100; i++)
    {
        merkkiJono[i] = tolower(merkkiJono[i]);
    }
    printf("%s", merkkiJono);


    for (i = 0; i < 100; i++)
    {
        merkkiJono[i] = toupper(merkkiJono[i]);
    }
    printf("%s", merkkiJono);

    return 0;
}
