#include <stdio.h>

void printVelocity(float *pInVelocity){
    printf("4\n Input velocity in km/h: %f\n", *pInVelocity);
    printf("Address of velocity: %p\n", pInVelocity);

    *pInVelocity *= 0.277778; // *pInVelocity = *pInVelocity*0.277778;
    printf("5\nVelocity in m/s: %f\n", *pInVelocity);
    // return xxxx;
}

int main() {
    float velocity;
    float *pVelocity = &velocity;

    printf("Enter your velocity in km/h: ");
    scanf("%f", &velocity);

    printf("1\nYour input (km/h): %f\n", velocity);
    printf("Stored in: %p\n", &velocity);

    printf("2\nYour input (km/h): %f\n", *pVelocity);
    printf("Stored in: %p\n", pVelocity);
    
    printVelocity(&velocity);
    printf("6\nVelocity in m/s: %f\n", velocity);

    return 0;
}