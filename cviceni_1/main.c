#include <stdio.h>

int main() {
    // Armáda datových typů

    // char od -128 do 127
    signed char c = 127;
    printf("char: %d\n", c);

    // unsigned char od 0 do 255
    unsigned char uc = 255;
    printf("unsigned char: %u\n", uc);


    short int si = 32000;
    printf("short int:  %hd\n", si);

    unsigned short int usi = 65000;
    printf("short int:  %hu\n", usi);

    int i = 32;
    printf("int: %d\n", i);

    unsigned int ui = 64;
    printf("unsigned int: %u\n", ui);

    long int li = 32;
    printf("long int: %li\n", li);

    unsigned long int uli = 64;
    printf("unsigned long int: %lu\n", uli);

    long long int lli = 32;
    printf("long long int: %lli\n", lli);

    unsigned long long int ulli = 64;
    printf("unsigned long long int: %llu\n", ulli);

    float f = 1.25f;
    printf("float:    %f\n", f);

    double d = 4.6;
    printf("double:   %lf\n", d);

    long double ld = 8.2;
    printf("double:   %Lf\n", ld);


    char ch = 'a';
    printf("char:     %c\n", ch);

    char str[] = "ahoj";
    printf("string:   %s\n", str);





    // printf("Sizeof i: %lu\n", sizeof i);

    return 0;
}
