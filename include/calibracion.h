/**
 * @file calibracion.h
 * @brief Interfaz del ejercicio calibracion
 */

#include "common.h"
#include <stdio.h>

/**
 * @brief funcion que corrige el desfase de un arreglo de mediciones con un dado
 * offset. El nuevo arreglo se guarda en un archivo.
 * @param nom_arch el nombre del archivo donde se guarda la inforamcion
 * actualizada
 * @param datos el arreglo original de datos
 * @param cant el numero de datos en el arreglo
 * @param offset el offset para aplicar en la correccion
 */
void exportar_corregido(char *nom_arch, Medicion *datos, int cant,
                        float offset);
