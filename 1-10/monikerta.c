#include <stdio.h>
#include <math.h>

int main(void){
    int luku1, luku2, alkuperainen;

    scanf("%d", &luku1);
    scanf("%d", &luku2);
    alkuperainen = luku1;
    if(luku2 != 0){
    luku1 = luku1 % luku2;
        if(luku1 == 0){
            printf("Luku %d on luvun %d monikerta", alkuperainen, luku2);
        }
        else{
            printf("Luku %d ei ole luvun %d monikerta", alkuperainen, luku2);
        }
    }
    else{
        printf("Luku %d ei ole luvun %d monikerta", alkuperainen, luku2);
    }

}
