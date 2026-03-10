/**
 * @file picos.h
 * @brief Interfaz del ejercicio de picos en matriz
 */

#pragma once
#include <stdbool.h>
#include <stdio.h>

/**
 * @brief Funcion que busca e imprime los picos de una matriz A_{ij} \in N\times
 * M
 * @param filas el numero de filas N de la matriz
 * @param cols el numero de columnas M de la matriz
 * @param mapa la matriz de tamanio NXM como mapa topografico
 */
void detectar_picos(int filas, int cols, int mapa[filas][cols]);
