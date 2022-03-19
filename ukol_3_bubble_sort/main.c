#include <stdio.h>

void bubble_sort(int *arr, int size, int i) {
    for (int ii = 0; ii < i; ii++) {
        for (int j = 0; j < size - 1 - ii; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int x = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = x;
            }
        }
    }
}


int main() {

    int pole[] = {1, 4, 5, -1, -9};

    for (int i = 0; i < 5; i++) {
        printf("%d  ", *(pole + i));
    }
    printf("\n");

    bubble_sort(pole, 5, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d  ", *(pole + i));
    }
    printf("\n");
    return 0;
}
