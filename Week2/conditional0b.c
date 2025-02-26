#include <stdio.h>

#define WARNING_DISTANCE 30.0  // Batas jarak peringatan (cm)
#define EMERGENCY_DISTANCE 10.0  // Batas jarak darurat (cm)

int main(void) {
    float jarak_sensor;  // Variabel untuk menyimpan jarak objek yang terdeteksi oleh sensor

    // Meminta input jarak dari pengguna
    printf("Masukkan jarak objek di depan mobil (cm): ");
    scanf("%f", &jarak_sensor);

    // Logika pergerakan mobil berdasarkan jarak objek di depannya
    if (jarak_sensor < WARNING_DISTANCE) {  
        // Jika jarak lebih kecil dari WARNING_DISTANCE, mobil harus berhenti
        printf("Hambatan terlalu dekat! HENTIKAN MOBIL SEKARANG!\n");
    } else if (jarak_sensor <= EMERGENCY_DISTANCE) {  
        // Jika jarak masih dalam batas EMERGENCY_DISTANCE, mobil harus berbelok untuk menghindari tabrakan
        printf("Hambatan terdeteksi! BELOKKAN MOBIL!\n");
    } else {  
        // Jika jarak lebih dari WARNING_DISTANCE, jalan aman dan mobil bisa melaju
        printf("Jalan aman! GASPOOOLL...\n");
    }

    return 0;
}