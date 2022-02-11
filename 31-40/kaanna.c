#include <stdio.h>
#include <math.h>

int kaanna( int luku );
int korota(int luku, int potenssi);
int main(void){
    int luku, kaannetty;
    scanf("%d", &luku);

    if (luku >= 1000 && luku < 10000){
        kaannetty = kaanna(luku);
        printf("Luku %d kaannettyna on %04d\n", luku, kaannetty);
    }
    else if(luku >= 100 && luku < 1000){
        kaannetty = kaanna(luku);
        printf("Luku %d kaannettyna on %03d\n", luku, kaannetty);
    }
    else if(luku >= 10 && luku < 100){
        kaannetty = kaanna(luku);
        printf("Luku %d kaannettyna on %02d\n", luku, kaannetty);
    }
    else if(luku >= 1 && luku < 10){
        kaannetty = kaanna(luku);
        printf("Luku %d kaannettyna on %d\n", luku, kaannetty);
    }
    else{
        printf("luku ei ole väliltä 1-9999\n");
    }
    return(0);
}

int kaanna( int luku ){
    int i, x[4], mod, y;
    if (luku >= 1000 && luku < 10000){
        for (i = 0; i < 4; i++){
            mod = luku % (int)pow(10, i+1);
            //printf("mod: %d\n", mod);
            luku = luku - luku % (int)pow(10, i+1);
            x[i] = mod / pow(10, i);
        }
        y = x[0]*1000 + x[1]*100 + x[2]*10 + x[3];
    }
    else if(luku >= 100 && luku < 1000){
        for (i = 0; i < 3; i++){
            //mod = luku % (int)pow(10, i+1);
            printf("mod: %d\n", mod);
            luku = luku - luku % (int)pow(10, i+1);
            x[i] = mod / pow(10, i);
        }
        y = x[0]*100 +x[1]*10 + x[2];
    }
    else if(luku >= 10 && luku < 100){
        for (i = 0; i < 2; i++){
            //mod = luku % (int)pow(10, i+1);
            printf("mod: %d\n", mod);
            luku = luku - luku % (int)pow(10, i+1);
            x[i] = mod / pow(10, i);
        }
        y = x[0]*10 +x[1];
    }
    else{
        y = luku;
    }
    return y;
}

int korota(int luku, int potenssi){
    int x = 1;
    for (;potenssi > 0; potenssi--){
        x = x * luku;
    }
    return x;

}
