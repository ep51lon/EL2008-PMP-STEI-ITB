#include <stdio.h>

int main() {
    // Coefficients of the quadratic function ax^2 + bx + c
    double a, b, c;

    // Prompt user for input
    printf("Enter the coefficient a: ");
    scanf("%lf", &a);
    printf("Enter the coefficient b: ");
    scanf("%lf", &b);
    printf("Enter the coefficient c: ");
    scanf("%lf", &c);

    // Derivative of the quadratic function is 2ax + b
    double derivative;
    double x;

    // Calculate the derivative for x values from -10 to 10
    for (x = -10; x <= 10; x++) {
        derivative = 2 * a * x + b;
        printf("The derivative at x = %.2f is %.2f\n", x, derivative);
    }

    return 0;
}
