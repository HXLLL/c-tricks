#include <stdio.h>

int plus1_i(int x) {
    return x+1;
}

double plus1_d(double x) {
    return x+1;
}

#define plus1(x) _Generic((x), int: plus1_i, double: plus1_d)(x)

int main() {
    int x=1;
    double y=0.5;
    printf("%d %.3lf\n", plus1(x), plus1(y));
}