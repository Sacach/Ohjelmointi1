char* mystrcpy(char* kohde, const char* lahde);
char* mystrcat(char* kohde, char* lahde);

char* mystrcpy(char* kohde, const char* lahde){
    int i;
    for(i = 0; i < strlen(lahde); i++){
        kohde[i] = lahde[i];
    }
    return kohde;
}

char* mystrcat(char* kohde, char* lahde){
    int i, j;
    j = strlen(kohde);
    for(i = 0; i < strlen(lahde); i++){
        kohde[j+i] = lahde[i];
    }
    return kohde;
}
