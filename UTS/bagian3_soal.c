#include <stdio.h>
#include <time.h>

#define __LINUX__

#if defined(__WINDOWS__)
    #include <windows.h>
#elif defined(__LINUX__)
    #include <unistd.h>
#endif

#define LOOP_C_1 10
#define LOOP_C_2 1

void f01 (int *pTemp)
{
    Sleep(1000);
    srand(time(NULL));

    for (int i = 0; i < LOOP_C_1; i++) {
        *pTemp = rand() % 100 + 1;
    }
}

void f02 (int *pTemp)
{
    for (int i = 0; i < (LOOP_C_1 - 1); i++) {
        for (int j = (i + 1); j < (LOOP_C_1); j++) {
            if (*(pTemp + i) > *(pTemp + j)) {
                int temp = *(pTemp + j);
                *(pTemp + j) = *(pTemp + j);
                *(pTemp + i) = temp;
            }
        }
    }
}

int main()
{
    int iVariabel[LOOP_C_1];
    int *pVariabel;
    pVariabel = iVariabel;

    for (int x = 0; x < LOOP_C_2; x++) {
        f01(&pVariabel);
        f02(&pVariabel);
        // tampilkan all number hasil sorting
        for (int i = 0; i < (LOOP_C_1); i++) {
            printf("%d ", *pVariabel);
        }
        printf("\n");
    }

    return (0);
}