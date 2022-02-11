#include <stdio.h>

int main(void){
    int pisteet;
    scanf("%d", &pisteet);

    if(pisteet <= 11 && pisteet >= 0){
        printf("Hylatty");
    }
    else if(pisteet <= 13 && pisteet >= 12){
        printf("1");
    }
    else if(pisteet <= 16 && pisteet >= 14){
        printf("2");
    }
    else if(pisteet <= 19 && pisteet >= 17){
        printf("3");
    }
    else if(pisteet <= 22 && pisteet >= 21){
        printf("4");
    }
    else if(pisteet <= 24 && pisteet >= 23){
        printf("5");
    }
    else{
        printf("Virheellinen pistemaara");
    }
}
