#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')
int main() {

    /*
    char d = 3;

    printf("\n"BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(d));
    */

    int x = 1, y = 2;
    int resAnd = x & y;
    int resOr = x | y;
    int resXor = x ^ y;
    int resNotX = ~x ;
    int resRshift = y >> 1;
    int resLshift = y << 1;


    printf("X:\n"BYTE_TO_BINARY_PATTERN"\n" , BYTE_TO_BINARY(x));
    printf("Y:\n"BYTE_TO_BINARY_PATTERN"\n" , BYTE_TO_BINARY(y));

    printf("\n"BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(resAnd));
    printf("\n"BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(resOr));
    printf("\n"BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(resXor));
    printf("\n"BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(resNotX));
    printf("\n"BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(resRshift));
    printf("\n"BYTE_TO_BINARY_PATTERN , BYTE_TO_BINARY(resLshift));



    return 0;
}