#include <stdio.h>
int karkausvuosi(double vuosiluku);

int main(void){
    double vuosi;
    printf("Anna vuosiluku:\n");
    scanf("%lf", &vuosi);
    karkausvuosi(vuosi);
}

int karkausvuosi(double vuosiluku){

    if ((vuosiluku / 400) == (int)(vuosiluku / 400)){
        //printf("(vuosiluku / 400) % 1 == 0\n");
        printf("Vuosi %d on karkausvuosi\n", (int)vuosiluku);
    }
    else if ((vuosiluku / 4) == (int)(vuosiluku / 4)){
        if ((vuosiluku / 100) == (int)(vuosiluku / 100)){
            //printf("(vuosiluku / 100) % 1 == 0\n");
            printf("Vuosi %d ei ole karkausvuosi\n", (int)vuosiluku);
        }
        else{
            //printf("(vuosiluku / 4) % 1 == 0)\n", vuosiluku);
            printf("Vuosi %d on karkausvuosi\n", (int)vuosiluku);
        }
    }
    else{
        printf("Vuosi %d ei ole karkausvuosi\n", (int)vuosiluku);
    }

}
