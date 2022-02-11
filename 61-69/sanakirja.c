#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char sana[256], tiedosto[20];
    char *suomi;
    char *englanti;
    int rivi = 1, i, flag;
    int find_result = 0;
    const char erotin[2] = ";";
    char temp[256];
    //scanf("%s", tiedosto);

    FILE *file;
    if( (file=fopen("sanakirja.txt", "r"))==NULL ){
           printf("Tiedoston avaaminen lukemista varten epäonnistui.\n");
    }
    else {
        fgets(sana, 256, stdin);
        //sana[strcspn(sana, "\n")] = 0;
        while (fgets(temp, sizeof(temp), file)) {
            if((strstr(temp, sana)) != NULL) {
                //printf("A match found on line: %d\n", rivi);
                //printf("\n%s\n", temp);
                find_result++;

                englanti = strtok(temp, erotin);
                suomi = englanti;
                englanti = strtok(NULL, erotin);
                //englanti[strcspn(englanti, "\n")] = 0;
                for(i=0; i < strlen(sana); i++){
                    if(sana[i] == suomi[i]){
                        flag = 1;
                    }
                    else{
                        flag = 0;
                    }

                }

                if(flag == 1){
                    printf("Sana %s englanniksi on %s\n", suomi, englanti);
                }
                else if (flag == 0){
                    printf("Sana %s suomeksi on %s\n", englanti, suomi);
                }
            }
        }
        if(find_result == 0) {
            printf("\nSanaa %s ei loytynyt sanakirjasta\n", sana);
        }

    }
    fclose(file);

    return 0;
}
