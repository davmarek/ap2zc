#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *removeLast(int *local_ptr, size_t size) {

    size_t newSize = sizeof(int) * (size - 1);
    int *tmp = malloc(newSize);
    memmove(tmp, local_ptr, newSize);
    free(local_ptr);
    return tmp;

}

int *removeMiddle(int *local_ptr, size_t size) {
    // index prvku který bude odstraněn
    int rm_i = (size / 2) + (size % 2) - 1;
    // posunutí prvků na místo rm_i
    for(int i = rm_i; i< size;++i)
        *(local_ptr+i) = *(local_ptr+i+1);

    // odstranění posledního prvku (removeLast)
    size_t newSize = sizeof(int) * (size - 1);
    int *tmp = malloc(newSize);
    memmove(tmp, local_ptr, newSize);
    free(local_ptr);
    return tmp;
}

int main() {

    size_t vel = 7;
    int *pole = malloc(vel * sizeof(int));
    if (pole == NULL) {
        printf("Out of memory");
        exit(1);
    }

    pole[0] = 1;
    pole[1] = 2;
    pole[2] = 3;
    pole[3] = 4;
    pole[4] = 5;
    pole[5] = 6;
    pole[6] = 7;


    pole = removeMiddle(pole, vel);


    for (int i = 0; i < vel-1; ++i)
        printf("%d", pole[i]);
    printf("\n");


    free(pole);
    return 0;
}
