#include <stdio.h>

int main(void){
    int i;


    printf("%-7s%-7s%-7s%-7s\n","N", "10*N", "100*N", "1000*N");
    for(i = 1; i < 11; ++i){

        printf("%-7d%-7d%-7d%-7d\n", i, 10*i, 100*i, 1000*i);
  }

}
