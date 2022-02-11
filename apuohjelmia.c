int lueKokonaisluku(void){

   int luku;
   char mki;
   int status;

   while (((status = scanf("%d%c", &luku, &mki)) == 0)  || (2 == status && mki != '\n')){
      lueRoskat();
      printf("Et syottanyt kokonaislukua > ");
   }

   return luku;
}

int lueReaaliluku(void){

   double luku;
   char mki;
   int status;

   while (((status = scanf("%lf%c", &luku, &mki)) == 0)  || (2 == status && mki != '\n')){
      lueRoskat();
      printf("Et syottanyt reaalilukua > ");
   }

   return luku;
}

void lueMerkkijono(char merkkijono[], int pituus){

   fgets( merkkijono, pituus, stdin );

   // Jos merkkijonon lopussa, ennen lopetusmerkkiä on ylimääräinen
   // rivinvaihto korvataan se lopetusmerkillä
   if( merkkijono[ strlen(merkkijono)-1 ] == '\n')
      merkkijono[ strlen(merkkijono)-1 ] = '\0';
   else
      lueRoskat();

}

void lueRoskat(void){

   // Tyhjennetään puskuri
   while( fgetc(stdin) != '\n');
}
