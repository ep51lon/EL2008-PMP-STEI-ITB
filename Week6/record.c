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

    // Print details of all palm trees
    for (int i = 0; i < 3; i++) {
        printf("Palm Tree ID: %d\n", trees[i].id);
        printf("GPS Coordinates: (%.3f, %.3f)\n", trees[i].gps_x, trees[i].gps_y);
        printf("Age: %d years\n", trees[i].age);
        printf("Estimated Diameter: %.2f meters\n\n", trees[i].diameter);
    }

    return 0;
}
