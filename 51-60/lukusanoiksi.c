#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    char luku_str[300] = "",
    luvut[9][10] = {"yksi", "kaksi", "kolme",
                    "nelja", "viisi", "kuusi",
                    "seitseman", "kahdeksan", "yhdeksan"},
    kertoimet[7][10] = {"tuhatta", "sataa", "kymmenta", "tuhat", "sata", "kymmenen", "toista"};
    int luku_int, i, temp = 0;
    scanf("%d", &luku_int);
    for(i = 0; i < 4; i++){
        temp = (luku_int % (int) pow(10, 4-i)) / (int) pow(10, 3-i);
        switch(temp){
            case 1:
                if(i == 3){
                    strcat(luku_str, luvut[0]);
                }
                else if (i == 2){
                    temp = luku_int % 10;
                    strcat(luku_str, luvut[temp - 1]);
                    strcat(luku_str, kertoimet[6]);
                    i++;
                }
                else{
                    strcat(luku_str, kertoimet[i + 3]);
                }
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:

                if(i == 3){
                    strcat(luku_str, luvut[temp - 1]);
                }
                else{
                    strcat(luku_str, luvut[temp - 1]);
                    strcat(luku_str, kertoimet[i]);
                }
                break;

        }
    }
    strcat(luku_str, "\0");
    printf("%s\n", luku_str);
    return 0;
}
