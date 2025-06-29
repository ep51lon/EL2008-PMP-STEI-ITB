#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk menyimpan elemen non-nol dari matriks
typedef struct Node {
    int row, col;
    float value;
    struct Node* next;
} Node;

// Representasi matriks menggunakan linked list
typedef struct {
    int size;     // Ukuran matriks (diasumsikan persegi)
    Node* head;   // Pointer ke elemen non-nol
} Matrix;

// Tambahkan elemen ke matriks
void insert_element(Matrix* mat, int row, int col, float value) {
    if (value == 0.0) return;
    Node* new_node = malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->value = value;
    new_node->next = mat->head;
    mat->head = new_node;
}

// Ambil nilai dari posisi (row, col)
void get_element(Matrix* mat, int row, int col, float* result) {
    Node* current = mat->head;
    *result = 0.0;
    while (current != NULL) {
        if (current->row == row && current->col == col) {
            *result = current->value;
            return;
        }
        current = current->next;
    }
}

// Transpos matriks src -> dest
void transpose_matrix(Matrix* src, Matrix* dest) {
    dest->size = src->size;
    dest->head = NULL;
    Node* current = src->head;
    while (current != NULL) {
        insert_element(dest, current->col, current->row, current->value);
        current = current->next;
    }
}

// Invers matriks 2x2
void inverse_2x2(Matrix* mat, Matrix* result) {
    result->size = 2;
    result->head = NULL;
    float a, b, c, d;
    get_element(mat, 0, 0, &a);
    get_element(mat, 0, 1, &b);
    get_element(mat, 1, 0, &c);
    get_element(mat, 1, 1, &d);
    float det = a * d - b * c;
    if (det == 0) return;

    insert_element(result, 0, 0,  d / det);
    insert_element(result, 0, 1, -b / det);
    insert_element(result, 1, 0, -c / det);
    insert_element(result, 1, 1,  a / det);
}

// Penjumlahan dua matriks A + B -> result
void add_matrices(Matrix* A, Matrix* B, Matrix* result) {
    result->size = A->size;
    result->head = NULL;
    for (int i = 0; i < result->size; i++) {
        for (int j = 0; j < result->size; j++) {
            float v1, v2, sum;
            get_element(A, i, j, &v1);
            get_element(B, i, j, &v2);
            sum = v1 + v2;
            if (sum != 0.0) insert_element(result, i, j, sum);
        }
    }
}

// Perkalian dua matriks A * B -> result
void multiply_matrices(Matrix* A, Matrix* B, Matrix* result) {
    result->size = A->size;
    result->head = NULL;
    for (int i = 0; i < result->size; i++) {
        for (int j = 0; j < result->size; j++) {
            float sum = 0.0;
            for (int k = 0; k < result->size; k++) {
                float v1, v2;
                get_element(A, i, k, &v1);
                get_element(B, k, j, &v2);
                sum += v1 * v2;
            }
            if (sum != 0.0) insert_element(result, i, j, sum);
        }
    }
}

// Tampilkan matriks dalam bentuk array 2D
void print_matrix(Matrix* mat) {
    printf("Matrix:\n");
    for (int i = 0; i < mat->size; i++) {
        for (int j = 0; j < mat->size; j++) {
            float val;
            get_element(mat, i, j, &val);
            printf("%.3f ", val);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Matrix A = {2, NULL};
    Matrix B = {2, NULL};

    // Inisialisasi matriks A
    insert_element(&A, 0, 0, 2);
    insert_element(&A, 0, 1, 1);
    insert_element(&A, 1, 0, 1);
    insert_element(&A, 1, 1, 1);

    // Inisialisasi matriks B
    insert_element(&B, 0, 0, 1);
    insert_element(&B, 0, 1, -1);
    insert_element(&B, 1, 0, -1);
    insert_element(&B, 1, 1, 2);

    print_matrix(&A);
    print_matrix(&B);

    Matrix At = {0, NULL};
    transpose_matrix(&A, &At);
    print_matrix(&At);

    Matrix AplusB = {0, NULL};
    add_matrices(&A, &B, &AplusB);
    print_matrix(&AplusB);

    Matrix AB = {0, NULL};
    multiply_matrices(&A, &B, &AB);
    print_matrix(&AB);

    Matrix Ainv = {0, NULL};
    inverse_2x2(&A, &Ainv);

    Matrix AinvB = {0, NULL};
    multiply_matrices(&Ainv, &B, &AinvB);
    print_matrix(&AinvB);

    return 0;
}