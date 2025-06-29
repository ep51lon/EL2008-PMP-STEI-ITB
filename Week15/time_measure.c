#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();

    for (volatile int i = 0; i < 100000000; i++);  // workload

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time elapsed: %f seconds\\n", time_spent);
    return 0;
}