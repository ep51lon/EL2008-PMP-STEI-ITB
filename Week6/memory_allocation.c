#include <stdio.h>
#include <stdlib.h>

// Define a struct for palm tree inventory
struct PalmTree {
    int id;            // Unique ID
    float gps_x;       // GPS X coordinate
    float gps_y;       // GPS Y coordinate
    int age;           // Age of the tree in years
    float diameter;    // Estimated diameter in meters
};

int main() {
    int n = 3; // Number of palm trees

    // Dynamically allocate memory using malloc
    struct PalmTree *trees = (struct PalmTree *)malloc(n * sizeof(struct PalmTree));
    if (trees == NULL) {
        printf("Memory allocation failed using malloc\n");
        return 1;
    }

    // Initialize the palm tree records
    for (int i = 0; i < n; i++) {
        trees[i].id = 1001 + i;
        trees[i].gps_x = 123.456 + i;
        trees[i].gps_y = 78.910 + i;
        trees[i].age = 5 + i;
        trees[i].diameter = 0.75 + (i * 0.1);
    }

    // Print details of all palm trees allocated with malloc
    printf("Palm Tree Inventory (using malloc):\n");
    for (int i = 0; i < n; i++) {
        printf("Palm Tree ID: %d\n", trees[i].id);
        printf("GPS Coordinates: (%.3f, %.3f)\n", trees[i].gps_x, trees[i].gps_y);
        printf("Age: %d years\n", trees[i].age);
        printf("Estimated Diameter: %.2f meters\n\n", trees[i].diameter);
    }

    // Free memory allocated with malloc
    free(trees);

    // Dynamically allocate memory using calloc
    struct PalmTree *trees_calloc = (struct PalmTree *)calloc(n, sizeof(struct PalmTree));
    if (trees_calloc == NULL) {
        printf("Memory allocation failed using calloc\n");
        return 1;
    }

    // Initialize the palm tree records allocated with calloc
    for (int i = 0; i < n; i++) {
        trees_calloc[i].id = 2001 + i;
        trees_calloc[i].gps_x = 223.456 + i;
        trees_calloc[i].gps_y = 178.910 + i;
        trees_calloc[i].age = 10 + i;
        trees_calloc[i].diameter = 1.0 + (i * 0.2);
    }

    // Print details of all palm trees allocated with calloc
    printf("Palm Tree Inventory (using calloc):\n");
    for (int i = 0; i < n; i++) {
        printf("Palm Tree ID: %d\n", trees_calloc[i].id);
        printf("GPS Coordinates: (%.3f, %.3f)\n", trees_calloc[i].gps_x, trees_calloc[i].gps_y);
        printf("Age: %d years\n", trees_calloc[i].age);
        printf("Estimated Diameter: %.2f meters\n\n", trees_calloc[i].diameter);
    }

    // Free memory allocated with calloc
    free(trees_calloc);

    return 0;
}