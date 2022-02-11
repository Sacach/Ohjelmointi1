#include <stdio.h>

int main(){
    int i, j, juomat[] = {0, 0, 0, 0}, arvosana;

    for(i = 0; i < 4; i++){
        printf("Anna juoma numero %d. pisteet", i+1);
        j = 0;
        while(j < 10){
            printf("Anna arvosana (1-5) > ");
            scanf("%d", &arvosana);
            if(arvosana >= 1 && arvosana <= 5){
                if(arvosana >= 3){
                    juomat[i] = juomat[i] + 1;
                }
                j = j + 1;

            }
            else{
                printf("ARVOSANAN TULEE\nOLLA VALILTA 1 - 5 !");
            }
        }

    }
    i = 0;
    for(i = 0; i < 4; i++){
        if(juomat[i] >= 5){
            printf("Juoma numero %d on kelvollista\n", i+1);
        }
        else{
            printf("Juoma numero %d on kelvotonta\n", i+1);
        }
    }

}

