#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char street[50];
} User;

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

User sort(User users[], size_t length) {
    for (int ii = 0; ii < length; ++ii)
        for (int i = 0; i < length - 1 - ii; ++i) {
            int j = 0;
            char c1 = users[i].name[j];
            char c2 = users[i + 1].name[j];

            if (c1 < c2) continue;

            if (c1 > c2) {
                swapUsers(&users[i], &users[i + 1]);
                continue;
            }

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
    User users[3];
    strcpy(users[0].name, "Petr");
    strcpy(users[1].name, "Dominik");
    strcpy(users[2].name, "David");

    printf("Před seřazením:\n");
    for (int i = 0; i < 3; ++i) {
        printf("User: %s\n", users[i].name);
    }

    sort(users, 3);

    printf("Po seřazení:\n");
    for (int i = 0; i < 3; ++i) {
        printf("User: %s\n", users[i].name);
    }
    return 0;
}
