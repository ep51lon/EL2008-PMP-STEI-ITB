#include <stdio.h>

// Fungsi untuk menormalisasi data kecepatan
void normalizeSpeed(float *data, float *normalizedData, int n, float minSpeed, float maxSpeed) {
    for (int i = 0; i < n; i++) {
        normalizedData[i] = (data[i] - minSpeed) / (maxSpeed - minSpeed);
    }
}

int main(void) {
    int n;
    float minSpeed = 0.0, maxSpeed = 150.0; // Nilai min dan max sudah diketahui

    // Meminta jumlah data
    printf("Masukkan jumlah data kecepatan yang mau dimasukkan: ");
    scanf("%d", &n);

    float speedData[n], normalizedData[n];

    // Memasukkan data kecepatan
    printf("Masukkan kecepatan(km/jam):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &speedData[i]);
    }

    // Normalisasi data
    normalizeSpeed(speedData, normalizedData, n, minSpeed, maxSpeed);

    // Menampilkan hasil normalisasi
    printf("\nHasil normalisasi kecepatan:\n");
    for (int i = 0; i < n; i++) {
        printf("Data %d: actual %.4f, normalised %.4f\n", i + 1, speedData[i], normalizedData[i]);
    }

    return 0;
}