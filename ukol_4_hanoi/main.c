#include <stdio.h>

void hanoi(int n, char from, char to, char help) {
    if (n == 1) {
        printf("presun disk %d z %c na %c\n", n, from, to);
        return;
    }

    hanoi(n - 1, from, help, to);

    printf("presun disk %d z %c na %c\n", n, from, to);

    hanoi(n - 1, help, to, from);
}

int main() {
    hanoi(10, 'A', 'C', 'B');
    return 0;
}
