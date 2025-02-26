#include <stdio.h>

#define BATAS_KECEPATAN 50

int main(void) {
    char lampu;     // Variabel untuk warna lampu lalu lintas (R = Merah, Y = Kuning, G = Hijau)
    float kecepatan; // Variabel untuk kecepatan kendaraan (km/jam)

    // Ambil data warna lampu lalu lintas
    printf("Masukkan warna lampu lalu lintas (R = Merah, Y = Kuning, G = Hijau): ");
    scanf("%c", &lampu);

    // Menentukan tindakan berdasarkan lampu lalu lintas
    if (lampu == 'R' || lampu == 'r') {
        printf("Berhenti!\n");
    } else if (lampu == 'Y' || lampu == 'y') {
        printf("Kurangi kecepatan dan bersiap untuk berhenti!\n");
    } else if (lampu == 'G' || lampu == 'g') {
        // Jika lampu hijau, ambil data kecepatan kendaraan
        printf("Masukkan kecepatan kendaraan (km/jam): ");
        scanf("%f", &kecepatan);

        // Periksa kecepatan kendaraan
        if (kecepatan <= BATAS_KECEPATAN) {
            printf("Lanjutkan perjalanan Anda.\n");
        } else {
            printf("Kecepatan terlalu tinggi, kurangi kecepatan!\n");
        }
    } else {
        printf("Input tidak valid! Masukkan R, Y, atau G.\n");
    }

    return 0;
}