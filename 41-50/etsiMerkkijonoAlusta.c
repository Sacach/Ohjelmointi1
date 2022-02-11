#include <stdio.h>
#include <string.h>

void etsiMerkkijonoAlusta( char *sana1, char *sana2 ,char *yhteinen);

int main() {
    char mjono1[100]={"asdfghjkl"};
    char mjono2[100]={"asdfghjkl"};
    char loydetty[100]={'\0'};
    etsiMerkkijonoAlusta( mjono1, mjono2, loydetty );
    printf("%s\n", loydetty);
    char mjono3[10]={"testi"};
    char mjono4[10]={"tapaus"};
    char loydetty2[10]={'\0'};
    etsiMerkkijonoAlusta( mjono3, mjono4, loydetty2 );
    printf("%s\n", loydetty2);
    char mjono5[100]={"Pelle"};
    char mjono6[100]={"Peloton"};
    char loydetty3[100]={'\0'};
    etsiMerkkijonoAlusta( mjono5, mjono6, loydetty3 );
    printf("%s\n", loydetty3);
    return 0;
}

void etsiMerkkijonoAlusta( char *sana1, char *sana2 ,char *yhteinen){
    int i = 0, j = 0;
    while(j <= strlen(sana1) || j <= strlen(sana2)){
        if(sana1[j] == sana2[j]){
            i = i+1;
            j = j+1;
        }
        else{
            j = strlen(sana1) + strlen(sana2);
        }
    }
    strncpy(yhteinen, sana1, i);
    yhteinen[i] = '\0';
}
