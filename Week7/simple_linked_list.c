#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int id;
    float gps_latitude;
    float gps_longitude;
    int age;
    float diameter;
    struct TreeNode* next;
} TreeNode;

// Function to create a new tree node
TreeNode* createTreeNode(int id, float latitude, float longitude, int age, float diameter) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->id = id;
    newNode->gps_latitude = latitude;
    newNode->gps_longitude = longitude;
    newNode->age = age;
    newNode->diameter = diameter;
    newNode->next = NULL;
    return newNode;
}

// Function to add a tree node to the linked list
void addTreeNode(TreeNode** head, int id, float latitude, float longitude, int age, float diameter) {
    TreeNode* newNode = createTreeNode(id, latitude, longitude, age, diameter);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the tree inventory
void displayTreeInventory(TreeNode* head) {
    TreeNode* current = head;
    while (current != NULL) {
        printf("Tree ID: %d\n", current->id);
        printf("GPS Coordinates: (%.6f, %.6f)\n", current->gps_latitude, current->gps_longitude);
        printf("Age: %d years\n", current->age);
        printf("Diameter: %.2f cm\n", current->diameter);
        printf("--------------------------\n");
        current = current->next;
    }
}

// Function to free the linked list
void freeTreeInventory(TreeNode* head) {
    TreeNode* current = head;
    while (current != NULL) {
        TreeNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    TreeNode* treeInventory = NULL;

    // Add some sample trees to the inventory
    addTreeNode(&treeInventory, 1, -6.914744, 107.609810, 10, 25.5);
    addTreeNode(&treeInventory, 2, -6.915000, 107.610000, 15, 30.2);
    addTreeNode(&treeInventory, 3, -6.916000, 107.611000, 8, 20.0);

    // Display the tree inventory
    printf("Tree Inventory:\n");
    printf("==========================\n");
    displayTreeInventory(treeInventory);

    // Free the allocated memory
    freeTreeInventory(treeInventory);

    return 0;
}