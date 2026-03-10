/**
 * @file pi.c
 * @brief Implementacion del ejercicio de cifras de pi 
 */

#include "pi.h"

double calcular_pi(int N) {
    if (N <= 0) {
        printf("Ha ingresado un N <= 0\n");
        return -1;
    }

    double acc = 0.0;
    for (int k = 0; k <= N; k++) {
        if (k % 2 == 0) {
            acc += (double)(1) / (2 * k + 1);
        } else {
            acc += (double)(-1) / (2 * k + 1);
        }
    }
    return 4.0 * acc;
}
