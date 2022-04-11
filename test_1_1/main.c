#include <stdio.h>

// Zadání:
// metoda, která vypíše zadaný text do konzole
// a vrátí jeho délku
// + ošetřit proměnnou text
int printText(const char *text) {
    // pokud se jedná o pointer na NULL
    if (text == NULL)
        return -1;

    int i = 0;
    char c = *(text + i);
    while (c != '\0') {
        printf("%c", c);
        ++i;
        c = *(text + i);
    };
    return i;
}

int main() {
    int count = printText("Hello World!\n");
    printf("%d", count);
    return 0;
}
