
void tyhjennapuskuri(void);
double lueint(void);


void tyhjennapuskuri(void){
    while(fgetc(stdin) != '\n');
}
double lueint(void){
    double luku;
    int result;
    char merkki;

    printf("Anna kokonaisluku > \n");

    while((result=scanf("%lf%c", &luku, &merkki))<= 0 || result == 2 && merkki != '\n'){
        tyhjennapuskuri();
        printf("%lf\n", luku);
        printf("Ei ollut reaaliluku\n");
    }
    return luku;
}
