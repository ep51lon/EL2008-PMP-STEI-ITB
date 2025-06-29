#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;

    // Record start time
    gettimeofday(&start, NULL);

    // -------- Code block to measure --------
    volatile long long sum = 0;
    for (long long i = 0; i < 100000000; i++) {
        sum += i;
    }
    // ----------------------------------------

    // Record end time
    gettimeofday(&end, NULL);

    // Calculate elapsed time in seconds
    double elapsed = (end.tv_sec - start.tv_sec) +
                     (end.tv_usec - start.tv_usec) / 1e6;

    printf("Elapsed time: %f seconds\n", elapsed);

    return 0;
}