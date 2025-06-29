#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk queue
typedef struct QueueNode {
    int t;
    float x, y, z;
    struct QueueNode* next;
} QueueNode;

// Pointer untuk head (depan) dan tail (belakang) queue
QueueNode* front = NULL;
QueueNode* rear = NULL;

// Fungsi untuk menambahkan data ke queue (enqueue)
void enqueue(int t, float x, float y, float z) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->t = t;
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Fungsi untuk menghapus data dari queue (dequeue)
void dequeue() {
    if (front == NULL) {
        printf("Queue kosong!\n");
        return;
    }

    QueueNode* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    printf("Dequeued: t=%d, Pos=(%.2f, %.2f, %.2f)\n", temp->t, temp->x, temp->y, temp->z);
    free(temp);
}

// Fungsi untuk membaca seluruh isi queue
void readQueue() {
    if (front == NULL) {
        printf("Queue kosong!\n");
        return;
    }

    printf("Isi queue:\n");
    QueueNode* temp = front;
    while (temp != NULL) {
        printf("  t=%d, Pos=(%.2f, %.2f, %.2f)\n", temp->t, temp->x, temp->y, temp->z);
        temp = temp->next;
    }
}

// Fungsi utama
int main() {
    // Simulasi enqueue (penyimpanan data tiap frame detik)
    enqueue(0, 0.0, 0.0, 0.0);
    enqueue(1, 0.5, 0.1, 0.0);
    enqueue(2, 1.0, 0.3, 0.0);
    enqueue(3, 1.5, 0.6, 0.0);
    enqueue(4, 2.0, 0.9, 0.0);

    readQueue(); // membaca isi antrian

    printf("\nPemrosesan frame pertama:\n");
    dequeue();  // memproses (menghapus) frame pertama

    printf("\nAntrian setelah 1 frame diproses:\n");
    readQueue();

    return 0;
}