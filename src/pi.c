#include "pi.h"

double calcular_pi(int N) {
    if (N <= 0)
        return 0.0;

    double acc = 0.0;
    for (int k = 0; k < N; k++) {
        if (k % 2 == 0) {
            acc += (double)(1) / (2 * k + 1);
        } else {
            acc += (double)(-1) / (2 * k + 1);
        }
    }
    return 4.0 * acc;
}
