#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #define Sleep(x) sleep((x) / 1000)  // Konversi ms ke s untuk Linux
#endif

#define LOOP_C_1 10
#define LOOP_C_2 1

// Fungsi untuk mengisi array dengan bilangan acak
void f01(int *pTemp) {
    Sleep(1000);  // Tunggu 1 detik
    srand((unsigned int)time(NULL));  // Seed untuk rand()

    for (int i = 0; i < LOOP_C_1; i++) {
        *(pTemp + i) = rand() % 100 + 1;
    }
}

// Fungsi untuk mengurutkan array (bubble sort)
void f02(int *pTemp) {
    int temp;
    for (int i = 0; i < (LOOP_C_1 - 1); i++) {
        for (int j = i + 1; j < LOOP_C_1; j++) {
            if (*(pTemp + i) > *(pTemp + j)) {
                temp = *(pTemp + j);
                *(pTemp + j) = *(pTemp + i);
                *(pTemp + i) = temp;
            }
        }
    }
}

int main() {
    int iVariabel[LOOP_C_1];
    int *pVariabel;
    pVariabel = iVariabel;

    for (int x = 0; x < LOOP_C_2; x++) {
        f01(pVariabel);   // perbaikan: cukup kirim pointer langsung
        f02(pVariabel);   // perbaikan: cukup kirim pointer langsung

        // Tampilkan semua hasil sorting
        for (int i = 0; i < LOOP_C_1; i++) {
            printf("%d ", *(pVariabel + i));  // perbaikan: akses elemen array
        }
        printf("\n");
    }

    return 0;
}