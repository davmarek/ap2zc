#include <stdio.h>

int printText(const char *text) {
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
