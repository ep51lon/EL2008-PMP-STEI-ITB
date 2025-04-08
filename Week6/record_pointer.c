#include <stdio.h>

// Define a struct for palm tree inventory
struct PalmTree {
    int id;            // Unique ID
    float gps_x;       // GPS X coordinate
    float gps_y;       // GPS Y coordinate
    int age;           // Age of the tree in years
    float diameter;    // Estimated diameter in meters
};

int main() {
    // Create and initialize an array of palm tree records
    struct PalmTree trees[3] = {
        {1001, 123.456, 78.910, 5, 0.75},
        {1002, 124.567, 79.011, 8, 0.85},
        {1003, 125.678, 80.112, 3, 0.65}
    };

    // Use a asterisk symbol to access and print details of all palm trees
    struct PalmTree *ptr = trees;
    for (int i = 0; i < 3; i++) {
        printf("Palm Tree ID: %d\n", (*(ptr + i)).id);
        printf("GPS Coordinates: (%.3f, %.3f)\n", (*(ptr + i)).gps_x, (*(ptr + i)).gps_y);
        printf("Age: %d years\n", (*(ptr + i)).age);
        printf("Estimated Diameter: %.2f meters\n\n", (*(ptr + i)).diameter);
    }

    // Or, use a arrow to access and print details of all palm trees
    struct PalmTree *ptrs = trees;
    for (int i = 0; i < 3; i++) {
        printf("Palm Tree ID: %d\n", (ptrs + i)->id);
        printf("GPS Coordinates: (%.3f, %.3f)\n", (ptr + i)->gps_x, (ptrs + i)->gps_y);
        printf("Age: %d years\n", (ptrs + i)->age);
        printf("Estimated Diameter: %.2f meters\n\n", (ptrs + i)->diameter);
    }

    return 0;
}
