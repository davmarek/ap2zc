#include <stdio.h>

// Zadání:
// metoda, která vrací počet čísel ve stringu
// + ukázkový běh programu
int numbersContained(const char *text) {
    int count = 0;
    int i = 0;

    while (*(text + i) != '\0') {
        char c = *(text + i);
        if (c >= '0' && c <= '9') ++count;
        ++i;
    }
    return count;
}


int main() {
    char buffer[5000];
    scanf("%5000[^\n]", buffer);

    int c = numbersContained(buffer);
    printf("%s\n", buffer);
    printf("Numbers contained: %d\n", c);
    return 0;
}
