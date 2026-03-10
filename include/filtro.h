/**
 * @file filtro.h
 * @brief Interfaz del ejercicio de filtro
 */

#pragma once
#include <math.h>
#include <stdio.h>

/**
 * @brief Funcion que dado un arreglo con numeros ruidosos, lo suaviza
 * utilizando la tecnica del filtro de promedio movil, que se apoya en promediar
 * los valores desde i hasta i-ventana+1
 * @param entrada arreglo con ruido de numeros flotantes
 * @param salida arreglo suavizado de numeros flotantes
 * @param tamano tamanio del arreglo de entrada (y de salida)
 * @param ventana ventana que se usa para suavizar el arreglo
 * */
void filtro_promedio(float *entrada, float *salida, int tamano, int ventana);
