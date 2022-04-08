#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct {
    char *surname;
    char name[50];
    int age;
    char street[50];
} User;

int main() {
    // Staticky (stack)
    User u1;
    u1.age = 50;

    // Staticky s "konstruktorem"
    User u2 = {"Marek", "David", 19, "Cervankova"};

    // Pointer na struct
    User *uku = &u2;
    uku->age = 20;
    //nebo
    (*uku).age = 60;

    uku->surname = malloc(50);
    uku->surname[0] = 'a';
    *(uku->surname) = 'a';
    *((*uku).surname) = 'a';




    // Halda (dynamicky)
    User *uu = malloc(50);
    if(uu == NULL){
        printf("Nepovedla se alokace");
        return -1;
    }
    // uu.age = 50; // nefunguje
    uu->age = 40;
    strcpy(uu->name, "Vi");

    free(uu);

    return 0;
}
