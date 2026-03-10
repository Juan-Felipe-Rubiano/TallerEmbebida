/**
 * @file main.c
 * @brief Implementacion del ultimo ejercicio que agrupa varias funcionalidades
 */

#include "calibracion.h"
#include "common.h"
#include "datalogger.h"
#include "procesamiento.h"
#include <stdbool.h>
#include <stdio.h>

Medicion datos[100];
bool datos_cargados = 0;
int cant_datos = 0;

void cargar();
void exportar();
int main(void) {
    char opc;
    do {
        printf("\n1. Cargar archivo\n2. Mostrar analisis\n3. Exportar datos "
               "calibrados\n4. Salir\nSeleccione una opcion:\t");
        scanf("%c", &opc);
        scanf("%*c"); // Limpiar el buffer de entrada
        switch (opc) {
        case '1':
            cargar();
            break;
        case '2':
            if (datos_cargados)
                analizar_temperaturas(datos, cant_datos);
            else {
                printf(
                    "El archivo no esta cargado, carguelo a continuacion:\n");
                cargar();
            }
            break;
        case '3':
            if (datos_cargados)
                exportar();
            else {
                printf(
                    "El archivo no esta cargado, carguelo a continuacion:\n");
                cargar();
            }

            break;
        case '4':
            printf("Saliendo del programa\n");
            break;
        default:
            printf("La opcion digitada no existe.\n");
        }
    } while (opc != '4');

    return 0;
}

void cargar() {
    printf("Ingrese el nombre del archivo a cargar:\t");
    char nombre[100];
    scanf("%s", nombre);
    scanf("%*c"); // Limpiar el buffer de entrada
    int num_datos = cargar_datos(nombre, datos, 100);
    if (num_datos < 1) {
        printf("El archivo esta vacio. Cargue otro\n");
        return;
    }
    printf("%d datos cargados correctamente de %s", num_datos, nombre);
    datos_cargados = 1;
    cant_datos = num_datos;
}

void exportar() {
    float offset = 0;
    while (offset <= 0) {
        printf("Ingrese el offset mayor a 0 para la calibracion:\t");
        scanf("%f", &offset);
    }
    exportar_corregido("sensores_calibrados.txt", datos, cant_datos, offset);
}
