#include <stdio.h>

double factorial(int x);

int main()
{
    double e = 0;           //e:n tulosmuuttuja.
    int i;
    for (i = 0; i < 10; i++){
        e = e + 1 / factorial(i);
        printf("%.6lf\n", e);
    }


    return 0;
}

double factorial(int x){
    double fac = 1;
    int j;
    for (j = 1; j <= x; j++){
        fac = fac * j;
    }
    return fac;
}
