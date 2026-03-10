/**
 * @file calibracion.c
 * @brief Implementacion del ejercicio de calibracion
 */

#include "calibracion.h"

void exportar_corregido(char *nom_arch, Medicion *datos, int cant,
                        float offset) {
    FILE *archivo = fopen(nom_arch, "w");
    if (!archivo) {
        perror("El archivo no abre.\n");
        return;
    }
    float nueva_temp;

    for (int i = 0; i < cant; i++) {
        nueva_temp = datos[i].temp + offset;
        fprintf(archivo, "%s,%.2f,%d\n", datos[i].id, nueva_temp, datos[i].hum);
    }

    fclose(archivo);
}
