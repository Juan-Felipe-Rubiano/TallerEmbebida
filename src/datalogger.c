/**
 * @file datalogger.c
 * @brief Implementacion del ejercicio de datalogger
 */
#include "datalogger.h"

    int
    cargar_datos(char *nombre_archivo, Medicion *datos, int max_datos) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (!archivo) {
        perror("El archivo no abre.\n");
        return -1;
    }

    Medicion *aux = malloc(sizeof(Medicion));
    char buffer[100];
    int i = 0;
    while (fgets(buffer, sizeof(buffer), archivo) != NULL && i < max_datos) {
        sscanf(buffer, "%[^,],%f,%d", aux->id, &aux->temp, &aux->hum);
        datos[i] = *aux;
        i++;
    }
    free(aux);
    fclose(archivo);
    return i;
}
