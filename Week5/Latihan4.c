#include <stdio.h>

int main() {
    FILE *file;
    char product[50], bestProduct[50];
    int quantity, total = 0, maxQuantity = 0;

    // Membuka file untuk membaca data
    file = fopen("penjualan.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    printf("Data penjualan:\n");
    while (fscanf(file, "%s %d", product, &quantity) != EOF) {
        printf("%s: %d unit\n", product, quantity);
        total += quantity;
        if (quantity > maxQuantity) {
            maxQuantity = quantity;
            int i = 0;
            while (product[i] != '\0') {
                bestProduct[i] = product[i];
                i++;
            }
            bestProduct[i] = '\0';
        }
    }
    fclose(file);

    printf("\nTotal unit terjual: %d\n", total);
    printf("Produk terlaris: %s (%d unit)\n", bestProduct, maxQuantity);

    return 0;
}