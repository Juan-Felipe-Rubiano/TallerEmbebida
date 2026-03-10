/**
 * @file datalogger.h
 * @brief Interfaz del ejercicio de cargar datos
 */

#pragma once
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief funcion que carga datos de tipo Medicion desde un archivo y los guarda
 * en un arreglo, retornando el numero de registros leidos
 * @param nombre_archivo el nombre del archivo de texto a leer
 * @param datos el arreglo de datos donde guardar las entradas leidas del
 * archivo
 * @param max_datos el numero maximo de datos que se pueden guardar, sea el
 * tamanio del arreglo
 * @return el numero de registros leidos
 */
int cargar_datos(char *nombre_archivo, Medicion *datos, int max_datos);
