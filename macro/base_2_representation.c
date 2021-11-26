#include <stdio.h>

// only use it with 4-byte number literal
#define BYTE(x) ((x&0x0000000FLU ? 1 : 0)) \
+ ((x&0x000000F0LU ? 2 : 0)) \
+ ((x&0x00000F00LU ? 4 : 0)) \
+ ((x&0x0000F000LU ? 8 : 0)) \
+ ((x&0x000F0000LU ? 16 : 0)) \
+ ((x&0x00F00000LU ? 32 : 0)) \
+ ((x&0x0F000000LU ? 64 : 0)) \
+ ((x&0xF0000000LU ? 128 : 0))


int main() {
    printf("%d\n", BYTE(0x11111111)); // print 255
}
