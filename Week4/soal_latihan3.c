#include <stdio.h>

// Fungsi untuk menghitung faktorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Fungsi untuk menghitung pangkat (power function)
double powert(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Fungsi untuk menghitung sin(x) menggunakan deret Taylor
double sin_taylor(double x, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = (i % 2 == 0 ? 1 : -1) * (powert(x, 2 * i + 1) / factorial(2 * i + 1));
        result += term;
    }
    return result;
}

// Fungsi untuk menghitung cos(x) menggunakan deret Taylor
double cos_taylor(double x, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = (i % 2 == 0 ? 1 : -1) * (powert(x, 2 * i) / factorial(2 * i));
        result += term;
    }
    return result;
}

// Fungsi untuk mengonversi derajat ke radian
double degreeToRadian(double degree) {
    return degree * 3.141592653589793 / 180.0;
}

int main() {
    double degree, radian;
    int terms;

    // Meminta input sudut dalam derajat dan jumlah iterasi
    printf("Masukkan sudut dalam derajat: ");
    scanf("%lf", &degree);

    printf("Masukkan jumlah iterasi deret Taylor: ");
    scanf("%d", &terms);

    // Konversi ke radian
    radian = degreeToRadian(degree);

    // Hitung sin(x) dan cos(x) menggunakan deret Taylor
    double sinValue = sin_taylor(radian, terms);
    double cosValue = cos_taylor(radian, terms);

    // Tampilkan hasil
    printf("\nHasil perhitungan menggunakan deret Taylor:\n");
    printf("sin(%.2f) ≈ %.6f\n", degree, sinValue);
    printf("cos(%.2f) ≈ %.6f\n", degree, cosValue);

    return 0;
}