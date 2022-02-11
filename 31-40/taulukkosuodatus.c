#include <stdio.h>

int main(){
    int list[20], i = 0, luku, a, b, dub = 0;

    printf("Syötä %d. luku >\n", i+1);

    while(i < 20){
        scanf("%d", &luku);
        if(luku >= 10 && luku <= 100){
            list[i] = luku;
            i = i + 1;
            if (i < 20){
                printf("Syötä %d. luku >\n", i+1);
            }
        }
        else{
            printf("Ei kelpaa!\nYrita uudelleen > \n");

        }
    }
    for (a = 0; a < 20; a++){
        if(list[a] > 1){
            for (b = a + 1; b < 20; b++){
                /*
                printf("a: %d\n", a);
                printf("b: %d\n", b);
                printf("list[a]: %d\n", list[a]);
                printf("list[b]: %d\n", list[b]);
                */
                if(list[a] == list[b]){

                    list[b] = 1;
                    dub = 1;
                }
            }
        }
        if (dub == 1){
            list[a] = 1;
            dub = 0;
        }
        else{
            if(list[a] != 1){
                printf("%d\n", list[a]);
            }

        }
    }
}
