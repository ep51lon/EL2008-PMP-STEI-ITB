#include <stdio.h>

#define KONSUMSI_BBM 8.0 // Konsumsi bensin mobil (km/liter)

int main(void) {
    float jarak_kampus;      // Jarak dari rumah ke kampus (km)
    float bensin_tersedia;   // Jumlah bensin yang tersedia (liter)
    float jarak_tempuh_mobil; // Jarak maksimal yang dapat ditempuh

    // Meminta pengguna memasukkan data perjalanan
    printf("Masukkan jarak dari rumah ke kampus (km): ");
    scanf("%f", &jarak_kampus);
    
    printf("Masukkan jumlah bensin yang tersedia (liter): ");
    scanf("%f", &bensin_tersedia);

    // Menghitung jarak maksimal yang bisa ditempuh
    jarak_tempuh_mobil = bensin_tersedia * KONSUMSI_BBM;

    // Menentukan apakah mobil bisa sampai ke kampus atau tidak
    if (jarak_kampus < jarak_tempuh_mobil) {
        printf("Silakan berangkat.\n");
    } else {
        printf("Bentar, isi bensin dulu!\n");
    }

    return 0;
}