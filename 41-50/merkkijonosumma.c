#include <stdio.h>

int main() {
    char mjono1[10], mjono2[10];
    int luku1, luku2;
    printf("Anna 1. luku > ");
    fgets( mjono1, 10, stdin );
    printf("Anna 2. luku > ");
    fgets( mjono2, 10, stdin );

    sscanf(mjono1, "%d", &luku1);
    sscanf(mjono2, "%d", &luku2);
    printf("Lukujen %d ja %d summa on %d", luku1, luku2, luku1 + luku2);
    return 0;
}
