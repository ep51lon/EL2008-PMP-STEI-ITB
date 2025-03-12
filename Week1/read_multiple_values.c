#include <stdio.h>

int main() {
    int a, b, c;
    float x, y, z;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("You entered: %d, %d, %d\n", a, b, c);

    printf("Enter three floats: ");
    scanf("%f %f %f", &x, &y, &z);

    printf("You entered: %f, %f, %f\n", x, y, z);

    return 0;
}