#include <stdio.h>


int sum(int *arr, size_t size){
    if (size == 1) return *arr;
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += *(arr + i);
    return sum;
}


int main() {
    int pole[] = {2, 5, 4};
    int length = sizeof pole / sizeof pole[0];
    int suma = sum(pole, length);

    printf("Suma pole: %d\n", suma);

    return 0;
}

