#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char street[50];
} User;

// Metoda která prohodí všechny atributy dvou uživatelů
void swapUsers(User *left, User *right) {

    char tmpName[50];
    strcpy(tmpName, right->name);
    strcpy(right->name, left->name);
    strcpy(left->name, tmpName);

    int tmpAge;
    tmpAge = right->age;
    right->age = left->age;
    left->age = tmpAge;

    char tmpStreet[50];
    strcpy(tmpStreet, right->street);
    strcpy(right->street, left->street);
    strcpy(left->street, tmpStreet);
}

// Upravený bubble-sort
User sort(User users[], size_t length) {
    // ii = počet iterací (kolikrát sort jede)
    for (int ii = 0; ii < length; ++ii)
        // projde každý znak kromě posledního (ten nemá žádný další prvek napravo od něj)
        // "- ii" je tam protože nepotřebujeme kontrolovat posledních "ii" prvků
        // protože už "probublali" na konec
        for (int i = 0; i < length - 1 - ii; ++i) {
            // j = pomocná proměná při procházení stringu name
            int j = 0;
            // c1 = char aktuálního usera (na indexu i)
            // c2 = char usera za aktuálním userem  [i + 1]
            char c1 = users[i].name[j];
            char c2 = users[i + 1].name[j];

            // pokud ASCII hodnota znaku c1 je menší než c2 (A=65 ... Z=90)
            // tak aktuální uživatel je abecedně výš
            if (c1 < c2) continue;

            // pokud je to naopak tak je user na [i + 1] abecedně výš než ten aktuální
            if (c1 > c2) {
                // uživatelé se prohodí a jde se na další ho uživatele
                swapUsers(&users[i], &users[i + 1]);
                continue;
            }

            // pokud c1 není ani menší ani větší, tak jsou určitě stejné
            // musí se prokontrolovat i další znaky/zbytek slova
            ++j;
            c1 = users[i].name[j];
            c2 = users[i + 1].name[j];
            while (c1 != '\0') {

                if (c1 < c2)break;
                if (c1 > c2) {
                    swapUsers(&users[i], &users[i + 1]);
                    break;
                }
                ++j;
                c1 = users[i].name[j];
                c2 = users[i + 1].name[j];

                if (c2 == '\0') {
                    swapUsers(&users[i], &users[i + 1]);
                    break;
                }
            }
        }

    return users[0];
}

int main() {
    int length = 6;
    User users[length];
    strcpy(users[0].name, "Pzeter");
    strcpy(users[2].name, "Dominikek");
    strcpy(users[1].name, "Zara");
    strcpy(users[3].name, "Pater");
    strcpy(users[4].name, "Domimik");
    strcpy(users[3].name, "Peter");
    strcpy(users[5].name, "David");

    printf("Před seřazením:\n");
    for (int i = 0; i < length; ++i) {
        printf("User: %s\n", users[i].name);
    }

    sort(users, length);

    printf("Po seřazení:\n");
    for (int i = 0; i < length; ++i) {
        printf("User: %s\n", users[i].name);
    }
    return 0;
}
