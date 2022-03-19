#include <stdio.h>

long fac(int n) {
    if (n == 1) return 1;
    return n * fac(n - 1);
}

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int fib_for(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int x = b;
        b = a + b;
        a = x;
    }
    return b;
}

int sum_rec(int *arr, int size) {
    if (size == 1) return *arr;

    return *arr + sum_rec(arr+1, size - 1);
}

int main() {
    /*
    int n = 0;
    while (n <= 5) {
        printf("%d\n", n);
        ++n;
    }
    */

    /*
    long a = fac(44);
    //printf("%ld", a);
    */

    /*
    int b = fib(13);
    printf("Rekurze: %d\n", b);


    int c = fib_for(2);
    printf("For:     %d\n", c);
    */

    int pole[] = {1, 2, 3, 4};
    int suma = sum_rec(pole, 4);
    printf("%d", suma);

    return 0;
}
