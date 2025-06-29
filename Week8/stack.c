#include <stdio.h>
#include <stdlib.h>

// Struktur node stack (double linked list)
typedef struct StackNode {
    int t;
    float x, y, z;
    struct StackNode* prev;
    struct StackNode* next;
} StackNode;

StackNode* top = NULL;
StackNode* bottom = NULL;

// Fungsi push ke stack
void push(int t, float x, float y, float z) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->t = t;
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;
    newNode->prev = NULL;
    newNode->next = top;

    if (top != NULL)
        top->prev = newNode;
    else
        bottom = newNode; // pertama kali push

    top = newNode;
}

// Fungsi pop dari stack
void pop() {
    if (top == NULL) {
        printf("Stack kosong!\n");
        return;
    }
    StackNode* temp = top;
    top = top->next;
    if (top != NULL)
        top->prev = NULL;
    else
        bottom = NULL; // stack kosong

    free(temp);
}

// Menampilkan seluruh isi stack dari atas ke bawah
void printStack() {
    StackNode* current = top;
    while (current != NULL) {
        printf("t=%d, Pos=(%.2f, %.2f, %.2f)\n", current->t, current->x, current->y, current->z);
        current = current->next;
    }
}

// Ambil data posisi dari waktu t_a sampai t_b (ascending time)
void getDataInTimeRange(int ta, int tb) {
    if (ta > tb) {
        printf("Rentang waktu tidak valid (t_a > t_b)\n");
        return;
    }

    StackNode* current = bottom; // mulai dari waktu paling kecil
    printf("Data dari waktu %d hingga %d:\n", ta, tb);
    while (current != NULL) {
        if (current->t >= ta && current->t <= tb) {
            printf("  t=%d, Pos=(%.2f, %.2f, %.2f)\n", current->t, current->x, current->y, current->z);
        }
        current = current->prev; // naik ke waktu lebih besar
    }
}

int main() {
    // Simulasi pergerakan robot
    push(0, 0.0, 0.0, 0.0);
    push(1, 1.0, 0.5, 0.0);
    push(2, 2.0, 1.0, 0.0);
    push(3, 3.0, 1.5, 0.0);
    push(4, 4.0, 2.0, 0.0);
    push(5, 5.0, 2.5, 0.0);

    printf("Isi stack (top-down):\n");
    printStack();

    printf("\nAmbil data antara t=2 dan t=4:\n");
    getDataInTimeRange(2, 4);

    return 0;
}