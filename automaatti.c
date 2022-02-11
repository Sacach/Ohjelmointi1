#include <stdio.h>
#include <string.h>

void lueRoskat(void);

int main(void){

   char tilinumero[256];
   FILE * tili;
   int saldo;
   int result;
   char pinkoodi[256];
   char tarkistusPin[256];

   do {

      printf("\nAnna tilinumero > ");
      fgets( tilinumero, 256, stdin );

      if (tilinumero[ strlen(tilinumero)-1] == '\n')
         tilinumero[ strlen(tilinumero)-1] = '\0';
      else
         lueRoskat();

      strcat(tilinumero, ".tili");

      if ((tili = fopen(tilinumero, "r")) != NULL) {
         printf("Anna pinkoodisi > ");

         fgets(pinkoodi, 256, stdin);

         if( pinkoodi[strlen(pinkoodi)-1] == '\n')
            pinkoodi[strlen(pinkoodi)-1] = '\0';
         else
            lueRoskat();

         fgets( tarkistusPin, 256, tili );

         do {

            // poista rivinvaihto
            if (tarkistusPin[strlen(tarkistusPin)-1] == '\n')
               tarkistusPin[strlen(tarkistusPin)-1] = '\0';

            // Huomaa - Windows-ohjelmilla luoduissa tiedostoissa rivin
            // loppu on merkattu kahdella merkill‰:
            // newline/linefeed = lf = '\n' ja carriage return = cr = '\r'
            //
            // Eli, jos vertailu PIN-koodien v‰lill‰ ei onnistu, tee viel‰
            // sueraava toimenpide, eli poista telanpalautus (cr)
            if (tarkistusPin[strlen(tarkistusPin)-1] == '\r')
               tarkistusPin[strlen(tarkistusPin)-1] = '\0';

            if ((result = strcmp(pinkoodi, tarkistusPin)) == 0) {
               fscanf(tili, "%d", &saldo);
            } else {
               printf("Vaara pin-koodi, yrita uudelleen");
            }

         } while (!result);

      } else {
         printf("\nTilisi on suljettu\n");
      }

   } while(1);

   return 0;
}

void lueRoskat(void){

   // Tyhjennet‰‰n puskuri
   while( fgetc(stdin) != '\n');
}
