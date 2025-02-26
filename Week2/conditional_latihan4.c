#include <stdio.h>

// Mendefinisikan mode transmisi menggunakan #define
#define MODE_PARKIR 'P'
#define MODE_REVERSE 'R'
#define MODE_NETRAL 'N'
#define MODE_DRIVE 'D'
#define MODE_SPORT 'S'

int main() {
    char transmisi; // Variabel untuk menyimpan mode transmisi yang dipilih

    // Meminta pengguna memasukkan mode transmisi
    printf("Masukkan mode transmisi (P/R/N/D/S): ");
    scanf("%c", &transmisi);

    // Menampilkan indikator HUD berdasarkan mode transmisi
    switch (transmisi) {
        case MODE_PARKIR:
            printf("HUD: Mode PARKIR - Mobil berhenti dan terkunci.\n");
            break;
        case MODE_REVERSE:
            printf("HUD: Mode REVERSE - Mobil mundur, periksa kamera belakang!\n");
            break;
        case MODE_NETRAL:
            printf("HUD: Mode NETRAL - Tidak ada tenaga ke roda.\n");
            break;
        case MODE_DRIVE:
            printf("HUD: Mode DRIVE - Mobil dalam mode berkendara normal.\n");
            break;
        case MODE_SPORT:
            printf("HUD: Mode SPORT - Akselerasi lebih responsif!\n");
            break;
        default:
            printf("HUD: Mode tidak dikenali! Pilih P, R, N, D, atau S.\n");
    }

    return 0;
}