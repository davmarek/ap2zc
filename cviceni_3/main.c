#include <stdio.h>

void switch_var(int *a, int *b){
    int p = *a;
    *a = *b;
    *b = p;
}

int main() {
    printf("Hello, World!\n");

    int i = 10;
    int j = 15;
    printf("i:%d\n", i);
    printf("j:%d\n", j);

    switch_var(&i,&j);

    printf("i:%d\n", i);
    printf("j:%d\n", j);


    return 0;
}
