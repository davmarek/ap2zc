#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /*
    // Scanf a buffer
    char buffer[100];
    printf("Zadej jméno: ");

    // scanf("%100s", buffer);
    scanf("%100[^\n]", buffer);
    */

    /*
    //Dynamická paměť
    // Memory ALLOCate
    char *jmeno = malloc(10 * sizeof(char));

    char *namex = "Více jak deset znaků";

    strcpy(jmeno, namex);

    printf("%s  |  %s\n", jmeno, namex);
    printf("%lu  |  %lu\n", strlen(jmeno), strlen(namex));

    free(jmeno);
    */


    // Použití dynamické paměti
    char buffer[100];
    printf("Zadej jméno: ");
    scanf("%100s", buffer);

    printf("Buffer: %s\n", buffer);

    char *jmeno = malloc(strlen(buffer) + 1);

    // při práci s malloc je tato podmínka potřeba
    if(jmeno == NULL){
        printf("Nepovedla se alokace");
        exit(1);
    }

    strcpy(jmeno, buffer);
    printf("STRCPY: %s\n", jmeno);

    *jmeno = '0';
    printf("New name: %s\n", jmeno);
    printf("Buffer:   %s\n", buffer);

    free(jmeno); // povinné uvolnit paměť
    jmeno = NULL; // best practice

    return 0;
}
