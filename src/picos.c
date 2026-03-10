/**
 * @file picos.c
 * @brief Implementacion del ejercicio de picos en una matriz
 */
#include "picos.h"

    void
    detectar_picos(int filas, int cols, int mapa[filas][cols]) {
    bool hayPicos = 0;
    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            int cur = mapa[i][j];
            if (cur > mapa[i - 1][j] && cur > mapa[i][j - 1] &&
                cur > mapa[i][j + 1] && cur > mapa[i + 1][j]) {
                hayPicos = 1;
                printf("Pico en (%d, %d) con valor %d.\n", i, j, cur);
            }
        }
    }
    if (!hayPicos)
        printf("No se encontraron picos.\n");
}
