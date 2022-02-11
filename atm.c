#include <stdio.h>
#include <string.h>

void clearBuffer(void);
int readInteger(void);
double readDouble(void);
void readCharacterString(char aString[], int stringSize);

int main(void){

    char accountNumber[256];
    FILE *pFile;
    int balance;
    int result;
    char pinCode[256];
    char checkPin[256];

    do {
        printf("\nGive account number > ");
        fgets(accountNumber, 256, stdin);

        if (accountNumber[strlen(accountNumber)-1] == '\n')
            accountNumber[strlen(accountNumber)-1] = '\0';
        else
            clearBuffer();

        strcat(accountNumber, ".acc");

        if ((pFile = fopen(accountNumber, "r")) != NULL){
            printf("Give your pin-code > ");

            fgets(pinCode, 256, stdin);

            if (pinCode[strlen(pinCode) - 1] == '\n')
                pinCode[strlen(pinCode) - 1] = '\0';
            else
                clearBuffer();


         fgets(checkPin, 256, pFile);

         do {
            if (checkPin[strlen(checkPin) - 1] == '\n')
               checkPin[strlen(checkPin) - 1] = '\0';

            // End of line in files created in Windows have two characters
            // carriage return = cr = '\r' AND
            // newline/linefeed = lf = '\n'
            // so, if you cannot compare the pin-codes, do the following...

            if (checkPin[strlen(checkPin) - 1] == '\r')
               checkPin[strlen(checkPin) - 1] = '\0';

            if ((result = strcmp(pinCode, checkPin)) == 0){
               fscanf(pFile, "%d", &balance);
               printf("Your balance is: %d\n", balance);
            } else
               printf("Wrong PIN-code, please, try again!");

         } while (!result);

      } else {
         printf("\nYour account is closed.\n");
      }

   } while (1);

   return 0;
}

void clearBuffer(void){

   while (fgetc(stdin) != '\n');
}

// For reading integer values
int readInteger(void) {

    int number;
    char character;
    int status;

    while ((status = scanf("%d%c", &number, &character)) == 0 || (2 == status && character != '\n')) {
        clearBuffer();
        printf("You did not enter an integer, try again > ");
    }

    return number;
}

// For reading real numbers
double readDouble(void) {

    double number;
    char character;
    int status;

    while ((status = scanf("%lf%c", &number, &character)) == 0 || (2 == status && character != '\n')) {
        clearBuffer();
        printf("You did not enter a real number, try again > ");
    }

    return number;
}

// For reading character strings
void readCharacterString(char aString[], int stringSize) {

    fgets(aString, stringSize, stdin);

    if (aString[strlen(aString) - 1] == '\n')
        aString[strlen(aString) - 1] = '\0';
    else
        clearBuffer();
}
