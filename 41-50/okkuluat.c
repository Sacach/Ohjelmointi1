#include <stdio.h>

int main(){
    int list[10], list2[10], i = 0, luku;

    while(i < 10){
        printf("Syötä %d. luku >\n", i+1);
        scanf("%d", &luku);

        list[i] = luku;
        i = i + 1;
    }
    for (i = 0; i < 10; i++){
        list2[i] = list[9-i];
    }
    for(i = 0; i < 10; i++){
        printf("%d%4d\n", list[i], list2[i]);
    }
}
