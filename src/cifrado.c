/**
 * @file cifrado.c
 * @brief Implementacion del ejercicio de cifrado cesar
 */
#include "cifrado.h"

    void
    cifrar_cadena(char *texto, int desplazamiento) {
    int i = 0;
    while (texto[i] != '\0') {
        char c = texto[i];
        if (c >= 'A' && c <= 'Z') {
            short posicion_relativa = c - 'A';
            posicion_relativa = (posicion_relativa + desplazamiento) % 26;
            if (posicion_relativa < 0)
                posicion_relativa += 26;

            texto[i] = 'A' + posicion_relativa;
        } else if (c >= 'a' && c <= 'z') {
            short posicion_relativa = c - 'a';
            posicion_relativa = (posicion_relativa + desplazamiento) % 26;
            if (posicion_relativa < 0)
                posicion_relativa += 26;

            texto[i] = 'a' + posicion_relativa;
        }
        i++;
    }
}
