/**
 * @file procesamiento.c
 * @brief Implementacion del ejercicio de analizar temperaturas
 */
#include "procesamiento.h"

    void
    analizar_temperaturas(Medicion *datos, int cantidad) {
    float temp_max = datos[0].temp;
    char id_max[20];
    strncpy(id_max, datos[0].id, 20);
    float temp_min = datos[0].temp;
    char id_min[20];
    strncpy(id_min, datos[0].id, 20);
    float temp_avg = datos[0].temp;

    for (int i = 1; i < cantidad; i++) {
        Medicion cur = datos[i];

        if (cur.temp > temp_max) {
            temp_max = cur.temp;
            strncpy(id_max, cur.id, 20);
        }
        if (cur.temp < temp_min) {
            temp_min = cur.temp;
            strncpy(id_min, cur.id, 20);
        }
        temp_avg += cur.temp;
    }
    printf("Sensor con temp_max: %s con %.2f grados;\nSensor con temp_min: %s "
           "con %.2f grados;\nPromedio de temperaturas: %.2f.\n",
           id_max, temp_max, id_min, temp_min, temp_avg / cantidad);
}
