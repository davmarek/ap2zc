#include <stdio.h>

#define SIZEE 10

int sum(int a, int b);

int main() {
    /*
    int a = 1;
    int *p;

    p = &a;
    printf("a: %d, adresa a:%p\n", a, &a);
    printf("p: %d, adresa p:%p\n", *p, p);
     */

    /*
    int arr[] = {1,2,5,8};
    size_t size = sizeof arr;
    size_t len = sizeof arr / sizeof arr[0];
    printf("sizeof arr: %zuB\n", size);
    printf("length arr: %zu\n", len);

    for (int i = 0; i < len; i++){
        printf("adresa %d : %p\n", arr[i], arr + i);
    }
     */

    /*
    int pole[SIZEE];
    printf("%zu", sizeof pole);
    */

    /*
    int velikost;
    printf("Zadej velikost pole a já ho vytvořím: ");
    scanf("%d", &velikost);
    // printf("Velikost: %d", velikost);
    int arr[velikost];
    */

    printf("%d", sum(1, 4));

    // TODO: Úkol: pole čísel a udělat funkci na sumu všech čísel

    return 0;
}


int sum(int a, int b) {
    return a + b;
}