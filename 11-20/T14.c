#include <stdio.h>

int main(void){
    int i, c = -100;
    float f;

    printf("%7s%12s\n", "Celsius", "Fahrenheit");

    for (i = 21; i > 0; i--){
        f = 1.8 * c + 32;
        printf("%5d%12.2lf\n", c, f);
        c = c + 10;
    }
}
