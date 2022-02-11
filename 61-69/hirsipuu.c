#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void tulosta_puu(int vaarat);
void lueRoskat(void);

int main(){
    char sanat[50][256], temp[256];
    char arvaus[2];
    int i, flag, viivat, sanan_paikka, vaarat_lkm = 0, oikein = 0, oikeat_kirjaimet[256] = {0};

    srand(time(NULL));

    FILE *file;
    if( (file=fopen("sanat.txt", "r")) == NULL ){
           printf("Tiedoston avaaminen lukemista varten epäonnistui.\n");
    }
    else {
        while (fgets(temp, sizeof(temp), file)) {
            strcpy(sanat[i], temp);
            i++;
        }
        sanan_paikka = rand() % i;
        //printf("Sana: %s\n", sanat[sanan_paikka]);
        while(vaarat_lkm < 8){
            flag = 0;
            viivat = 0;
            printf("Anna kirjain: > ");
            fgets(arvaus, 2, stdin);
            //arvaus[strcspn(arvaus, "\n")] = 0;
            //printf("\n");
            for(i = 0; i < strlen(sanat[sanan_paikka]) - 1; i++){
                //printf("Sana: %c\n", sanat[sanan_paikka][i]);
                //printf("Arvaus: %s\n", arvaus);
                if(arvaus[0] == sanat[sanan_paikka][i]){
                    oikeat_kirjaimet[i] = 1;
                    //printf("%s", arvaus);
                    flag = 1;
                }
                else if(oikeat_kirjaimet[i] == 0){
                    viivat++;
                    //printf("%c", sanat[sanan_paikka][i]);
                }
            }

            //printf("%d", viivat);
            if (flag == 0){
                vaarat_lkm++;
                tulosta_puu(vaarat_lkm);
            }
            else if(viivat != 0){
                for(i = 0; i < strlen(sanat[sanan_paikka]) - 1; i++){
                    if(oikeat_kirjaimet[i] == 1){
                        printf("%c", sanat[sanan_paikka][i]);
                    }
                    else{
                        printf("_");
                    }
                }
                printf("\n");
            }
            else{
                oikein = 1;
                break;
            }
        lueRoskat();
        }
        if(oikein == 1){
            printf("Hienoa, arvasit oikein!\n");
        }
        else{
            printf("Arvattava sana oli: %s", sanat[sanan_paikka]);
        }
    }
    fclose(file);

    return 0;
}
void tulosta_puu(int vaarat){
    switch(vaarat){
        case 1:
            printf("-------\n");
            break;
        case 2:
            printf("   |   \n   |   \n   |   \n   |   \n   |   \n-------\n");
            break;
        case 3:
            printf("   ____\n   |   \n   |   \n   |   \n   |   \n   |   \n-------\n");
            break;
        case 4:
            printf("   ______\n   |    |\n   |   \n   |   \n   |   \n   |   \n-------\n");
            break;
        case 5:
            printf("   ______\n   |    |\n   |    O\n   |   \n   |   \n   |   \n-------\n");
            break;
        case 6:
            printf("   ______\n   |    |\n   |    O\n   |    |\n   |   \n   |   \n-------\n");
            break;
        case 7:
            printf("   ______\n   |    |\n   |    O\n   |   /|\\\n   |   \n   |   \n-------\n");
            break;
        case 8:
            printf("   ______\n   |    |\n   |    O\n   |   /|\\\n   |   / \\\n   |   \n-------\n");
            break;
    }

}

void lueRoskat(void){

   // Tyhjennetään puskuri
   while( fgetc(stdin) != '\n');
}
