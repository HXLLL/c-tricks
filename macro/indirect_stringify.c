#include <stdio.h>

#define STR(x) #x
#define STR2(x) STR(x)

#define ONE 1

int main() {
    printf("%s\n", STR(ONE));   // "ONE"
    printf("%s\n", STR2(ONE));  // "1"
}