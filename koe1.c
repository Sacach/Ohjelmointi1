double jakolasku(int jaettava, int jakaja, int * onnistuiko);

int main(void){

  int luku1=0;
  int luku2=0;
  double luku3=0.0;
  int lopputulos_ok=0;

  printf("\nAnna ensimmainen luku:");
  scanf("%d", &luku1);

  printf("\nAnna toinen luku:");
  scanf("%d", &luku2);

  luku3 = jakolasku(luku1, luku2, &lopputulos_ok);

  if(lopputulos_ok!=0){
     printf("Luku %d jaettuna luvulla %d on %.2lf", luku1, luku2, luku3);
  } else {
     printf("Jakolasku ei onnistunut.");
  }

}

double jakolasku(int jaettava, int jakaja, int* onnistuiko){

  double tulos=0.0;
  tulos = (double)jaettava/(double)jakaja;
  *onnistuiko=1;
  return (tulos);
}
