/**
 * @file common.h
 * @brief declaracion de utilidades comunes para varios ejercicios
 */

#pragma once
/**
 * @brief Representa una medición con identificador, temperatura y humedad.
 *
 * Estructura utilizada en los ejercicios de los puntos 5 y 6 para almacenar
 * los datos de una medición de sensor.
 */
typedef struct Medicion {
    char id[20]; /**< Identificador único de la medición. */
    float temp;  /**< Temperatura registrada en grados Celsius. */
    int hum;     /**< Humedad relativa registrada en porcentaje (0-100). */
} Medicion;
