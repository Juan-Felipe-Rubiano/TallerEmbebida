/**
 * @file procesamiento.h
 * @brief Interfaz del ejercicio de analizar temperaturas
 */

#pragma once
#include "common.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief funcion que toma un arreglo de datos tipo Medicion y calcula su
 * temperatura maxima, minima y promedio
 * @param datos el arreglo con los datos de tipo Medicion
 * @param cantidad el numero de datos en el arreglo
 */
void analizar_temperaturas(Medicion *datos, int cantidad);
