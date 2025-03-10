#include <stdio.h>

void arithmetic_operations(int a, float b, double c) {
    int x = a + (int)b;       // float -> int
    float y = b * (float)c;   // double -> float
    double z = c / (double)a; // int -> double

    printf("x = %d, y = %f, z = %lf\n", x, y, z);
}

int main() {
    arithmetic_operations(10, 5.5f, 20.8);
    return 0;
}