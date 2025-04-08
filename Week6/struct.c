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
    // Create and initialize a palm tree record
    struct PalmTree tree;

    tree.id = 1001;
    tree.gps_x = 123.456;
    tree.gps_y = 78.910;
    tree.age = 5;
    tree.diameter = 0.75;

    // Print palm tree details
    printf("Palm Tree Details:\n");
    printf("ID: %d\n", tree.id);
    printf("GPS Coordinates: (%.3f, %.3f)\n", tree.gps_x, tree.gps_y);
    printf("Age: %d years\n", tree.age);
    printf("Estimated Diameter: %.2f meters\n", tree.diameter);

    return 0;
}
