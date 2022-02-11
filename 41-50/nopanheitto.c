#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heita(void);

int main(){
    int list[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, i, summa;
    srand(time(NULL));

    for(i = 0; i < 36000; i++){
        summa = heita();
        switch (summa){
            case 2:
                list[0] = list[0] + 1;
                break;
            case 3:
                list[1] = list[1] + 1;
                break;
            case 4:
                list[2] = list[2] + 1;
                break;
            case 5:
                list[3] = list[3] + 1;
                break;
            case 6:
                list[4] = list[4] + 1;
                break;
            case 7:
                list[5] = list[5] + 1;
                break;
            case 8:
                list[6] = list[6] + 1;
                break;
            case 9:
                list[7] = list[7] + 1;
                break;
            case 10:
                list[8] = list[8] + 1;
                break;
            case 11:
                list[9] = list[9] + 1;
                break;
            case 12:
                list[10] = list[10] + 1;
                break;
        }
    }
    printf("Summa	Lukumäärä\n");
    for(i = 0; i < 11; i++){
        printf("%5d%10d\n", i+2, list[i]);
    }
    printf("YHTEENSA   36000\n");

    return 0;
}

int heita(void){
    int a, b;
    a = rand() % 6 + 1;
    b = rand() % 6 + 1;
    return (a + b);
}
