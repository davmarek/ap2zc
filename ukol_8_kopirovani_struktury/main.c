#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define ZNAMKY_SIZE 3

typedef struct {
    char name[50];
    int *znamky;
} User;


int userCopy(User *dest, User *origin) {
    strcpy(dest->name, origin->name);
    if (dest->znamky == NULL) {
        dest->znamky = (int *) malloc(sizeof(int) * ZNAMKY_SIZE);
        if (dest->znamky == NULL) {
            printf("Nelze alokovat");
            return -1;
        }
    }
    for (int i = 0; i < ZNAMKY_SIZE; ++i)
        dest->znamky[i] = origin->znamky[i];

    return 0;
}

int main() {

    // Vytvoření a přidání dat prvního usera
    User u1;
    strcpy(u1.name, "Marc");
    u1.znamky = (int *) malloc(sizeof(int) * ZNAMKY_SIZE);
    if (u1.znamky == NULL) {
        return -1;
    }
    u1.znamky[0] = 1;
    u1.znamky[1] = 3;
    u1.znamky[2] = 2;

    // Vytvoření druhého usera
    // a zkopírování dat z prvního usera
    printf("KOPÍROVÁNÍ U1 DO U2 =======\n");
    User u2;
    u2.znamky = (int *) malloc(sizeof(int) * ZNAMKY_SIZE);
    if (u2.znamky == NULL) {
        return -1;
    }
    userCopy(&u2, &u1);

    // Vypsání dat po zkopírování

    printf("%s - ", u1.name);
    for (int i = 0; i < ZNAMKY_SIZE; ++i)
        printf("%d ", u1.znamky[i]);
    printf("\n");

    printf("%s - ", u2.name);
    for (int i = 0; i < ZNAMKY_SIZE; ++i)
        printf("%d ", u2.znamky[i]);
    printf("\n");


    // Přepsání dat Usera u1
    strcpy(u1.name, "Steven");
    u1.znamky[0] = 4;
    u1.znamky[1] = 5;
    u1.znamky[2] = 3;


    printf("PO ÚPRAVĚ USERA U1 =======\n");

    printf("%s - ", u1.name);
    for (int i = 0; i < ZNAMKY_SIZE; ++i)
        printf("%d ", u1.znamky[i]);
    printf("\n");

    printf("%s - ", u2.name);
    for (int i = 0; i < ZNAMKY_SIZE; ++i)
        printf("%d ", u2.znamky[i]);
    printf("\n");

    free(u1.znamky);
    free(u2.znamky);


    return 0;
}
