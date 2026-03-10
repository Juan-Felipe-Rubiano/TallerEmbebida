/**
 * @file filtro.c
 * @brief Implementacion del ejercicio de filtro promedio
 */
#include "filtro.h"

    void
    filtro_promedio(float *entrada, float *salida, int tamano, int ventana) {
    if (ventana < 0) {
        printf("[ERROR]La ventana es negativa.\n");
        return;
    }
    for (int i = 0; i < tamano; i++) {
        float sum = 0;
        int cnt = 0;
        for (int j = i; j >= i - ventana + 1 && j >= 0; j--) {
            sum += entrada[j];
            cnt++;
        }
        salida[i] = ((int)((sum / cnt) * 100)) / 100.0;
    }
}
