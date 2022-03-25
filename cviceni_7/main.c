#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Možnost jak definovat struct
struct UserStruct {
    char name[50];
    int age;
};

// 2. Možnost jak definovat struct
typedef struct {
    int id;
    char name[50];
    int age;
} User;


struct Organization {
    char orgNumber[50];
    char orgName[50];

    struct Employee {
        int id;
    } emp;

};

int main() {

    /*
    // STRUKTURY =======
    User u1;
    u1.id = 1;
    u1.age = 18;
    // u1.name = "Honza"; Hodí error
    strcpy(u1.name, "Honza");

    printf("id: %d, age: %d, name: %s", u1.id, u1.age, u1.name);
    */


    // PRÁCE SE SOUBORY ======
    // ČTENÍ SOUBORU
    // !!! JE POTŘEBA NAHRADIT CESTU
    FILE *stream = fopen("/Users/davidmarek/CLionProjects/AP2ZC/cviceni_7/data.csv", "r");
    if (stream == NULL) {
        printf("Soubor neotevřen!");
        return 1;
    }

    struct UserStruct users[3];

    char line[1024];
    int i = 0;
    while (fgets(line, 1024, stream)) {
        int age = atoi(strtok(line, ";"));
        users[i].age = age;

        char *name = strtok(NULL, ";");
        strcpy(users[i].name, name);

        ++i;
    }

    fclose(stream);

    for (int o = 0; o < 3; ++o) {
        printf("age: %d  ; name: %s\n", users[o].age, users[o].name);
    }


    // ZÁPIS DO SOUBORU
    FILE *streamWrite = fopen("/Users/davidmarek/CLionProjects/AP2ZC/cviceni_7/data2.csv", "a");
    fprintf(streamWrite, "12;xxx\n");
    if (fclose(streamWrite) == EOF) {
        printf("Soubor se nepovedlo uložit");
        return 1;
    }
    return 0;
}
