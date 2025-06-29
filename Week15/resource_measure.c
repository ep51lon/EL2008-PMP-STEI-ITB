#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(1000000 * sizeof(int));
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("Memory used: %ld KB\\n", usage.ru_maxrss);
    free(arr);
    return 0;
}