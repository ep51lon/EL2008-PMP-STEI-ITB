#include <stdio.h>

int main(void) {
    float prob_hujan, jarak; // Variabel untuk menyimpan probabilitas hujan

    // Meminta pengguna memasukkan probabilitas hujan
    printf("Masukkan probabilitas hujan hari ini (0-100%%): ");
    scanf("%f", &prob_hujan);

    printf("Jarak: ");
    scanf("%f", &jarak);

    printf("Jarak dari rumah ke kampus: %.2f, probabilitas hujan hari ini: %.1f\n", jarak, prob_hujan);

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