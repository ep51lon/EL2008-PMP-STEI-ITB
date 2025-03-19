#include <stdio.h>

// Fungsi untuk mengenkripsi string dengan pergeseran karakter
void encryptString(char *str, int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z')) { // Huruf besar
            str[i] = ((str[i] - 'A' + shift) % 26) + 'A';
        } else if ((str[i] >= 'a' && str[i] <= 'z')) { // Huruf kecil
            str[i] = ((str[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

int main() {
    char text[100];
    int shift;

    printf("Masukkan kalimat: ");
    fgets(text, sizeof(text), stdin);

    printf("Masukkan jumlah pergeseran: ");
    scanf("%d", &shift);

    encryptString(text, shift);
    printf("Hasil enkripsi: %s", text);

    return 0;
}