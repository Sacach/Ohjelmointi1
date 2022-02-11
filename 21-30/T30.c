#include <stdio.h>
int onkoLukuTaydellinen( int luku );

int main(void){
    int luku;
    for (luku = 1; luku < 10001; luku++){
        if (onkoLukuTaydellinen(luku) == 1){
            printf("\nLuku %d on taydellinen luku\n", luku);
        }
    }
  return(0);
}

int onkoLukuTaydellinen( int luku ){
    int summa = 0, i;
    for (i = 1; i < luku; i++){
        if (luku % i == 0){
            summa = summa + i;
        }
    }
    if (summa == luku){
        return 1;
    }
    else{
        return 0;
    }
}
