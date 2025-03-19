#include <stdio.h>

int main() {
    FILE *file;
    int n;
    char name[50];

    // Membuka file untuk menulis daftar mahasiswa
    file = fopen("mahasiswa.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);
    getchar(); // Membersihkan newline dari buffer

    for (int i = 0; i < n; i++) {
        printf("Masukkan nama mahasiswa ke-%d: ", i + 1);
        fgets(name, sizeof(name), stdin);
        fprintf(file, "%s", name);
    }
    fclose(file);
    printf("Data telah disimpan dalam file mahasiswa.txt\n");

    // Membaca dan menampilkan isi file
    file = fopen("mahasiswa.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    printf("\nDaftar mahasiswa:\n");
    while (fgets(name, sizeof(name), file) != NULL) {
        printf("%s", name);
    }
    fclose(file);

    return 0;
}