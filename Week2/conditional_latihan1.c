#include <stdio.h>

int main(void) {
    float prob_hujan; // Variabel untuk menyimpan probabilitas hujan

    // Meminta pengguna memasukkan probabilitas hujan
    printf("Masukkan probabilitas hujan hari ini (0-100%%): ");
    scanf("%f", &prob_hujan);

    // Menentukan moda transportasi berdasarkan probabilitas hujan
    if (prob_hujan > 60) {
        printf("Probabilitas hujan %.2f%%. Gunakan mobil.\n", prob_hujan);
    } else if (prob_hujan >= 30 && prob_hujan <= 60) {
        printf("Probabilitas hujan %.2f%%. Gunakan motor.\n", prob_hujan);
    } else {
        printf("Probabilitas hujan %.2f%%. Jalan kaki saja.\n", prob_hujan);
    }

    return 0;
}