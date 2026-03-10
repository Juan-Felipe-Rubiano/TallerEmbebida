/**
 * @file tests.c
 * @brief archivo con las pruebas sugeridas para los ejercicios
 */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "calibracion.h"
#include "cifrado.h"
#include "common.h"
#include "filtro.h"
#include "datalogger.h"
#include "pi.h"
#include "picos.h"
#include "procesamiento.h"

#define EPS 0.001

int float_eq(double a, double b) { return fabs(a - b) < EPS; }
/********************TEST EJ1 APROXIMACION PI***************************/
void test_pi() {
    printf("TESTEANDO calcular_pi...\n");
    double r1 = calcular_pi(10);
    assert(float_eq(r1, 3.23231581));
    double r2 = calcular_pi(1000);
    assert(float_eq(r2, 3.14259165));
    double r3 = calcular_pi(-5);
    assert(r3 == -1);
    printf("TESTS DE PI APROBADOS\n");
}
/********************TEST EJ2 CIFRADO CESAR***************************/
void test_cesar() {
    printf("TESTEANDO cifrar_cadena...\n");

    char t1[20] = "Hola Mundo!";
    cifrar_cadena(t1, 3);
    assert(strcmp(t1, "Krod Pxqgr!") == 0);

    char t2[20] = "Zebra";
    cifrar_cadena(t2, 1);
    assert(strcmp(t2, "Afcsb") == 0);

    char t3[10] = "A";
    cifrar_cadena(t3, -1);
    assert(strcmp(t3, "Z") == 0);

    printf("TESTS DE CESAR APROBADOS\n");
}
/********************TEST EJ3 FILTRO PROMEDIO***************************/
void test_filtro() {

    printf("TESTEANDO filtro_promedio...\n");

    float entrada[] = {10.2, 10.5, 25.0, 10.3, 10.1};
    float salida[5];

    filtro_promedio(entrada, salida, 5, 3);

    assert(float_eq(salida[0], 10.2));
    assert(float_eq(salida[1], 10.35));
    assert(float_eq(salida[2], 15.23));
    assert(float_eq(salida[3], 15.26));
    assert(float_eq(salida[4], 15.13));

    filtro_promedio(entrada, salida, 5, 0);
    filtro_promedio(entrada, salida, 5, -3);

    printf("TESTS DE FILTOR APROBADOS\n");
}

/********************TEST EJ4 PICOS***************************/
void test_picos_con_picos() {
    printf("TESTEANDO matriz con picos n");

    int mapa[5][5] = {{1, 2, 1, 2, 1},
                      {2, 9, 2, 1, 2},
                      {1, 2, 1, 2, 1},
                      {2, 1, 2, 8, 2},
                      {1, 2, 1, 2, 1}};

    detectar_picos(5, 5, mapa);

    printf("\n");
}

void test_matriz_plana() {

    printf("TESTEANDO matriz plana \n");

    int mapa[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    detectar_picos(4, 4, mapa);

    printf("\n");
}

/********************TEST EJ5 DATALOGGER***************************/
void test_datalogger() {
    printf("TESTEANDO logger con /util/archivo.txt\n");
    Medicion datos[100];

    int n = cargar_datos("../util/archivo.txt", datos, 100);

    if (n == -1) {
        printf("Error al leer el archivo\n");
        return;
    }

    printf("Registros leidos: %d\n", n);

    for (int i = 0; i < n; i++) {
        printf("Id: %s ; Temp: %.2f ; Hum: %d\n", datos[i].id, datos[i].temp,
               datos[i].hum);
    }
}

/********************TEST EJ6 PROCESAMIENTO***************************/
void test_analizar_temperaturas() {

    printf("TESTEANDO analizar_temperaturas...\n");

    Medicion datos[5] = {{"SENS_01", 24.5, 60},
                         {"SENS_02", 30.2, 55},
                         {"SENS_03", 18.7, 70},
                         {"SENS_04", 27.0, 65},
                         {"SENS_05", 22.3, 50}};

    analizar_temperaturas(datos, 5);

    printf("TEST DE ANALISIS COMPLETADO\n\n");
}
/********************TEST EJ7 CALIBRACION***************************/
void test_calibracion() {

    printf("TESTEANDO exportar_corregido...\n");

    Medicion datos[3] = {
        {"SENS_01", 24.5, 60}, {"SENS_02", 25.0, 55}, {"SENS_03", 23.0, 70}};

    exportar_corregido("test_corregido.txt", datos, 3, -1.5);

    FILE *f = fopen("test_corregido.txt", "r");
    assert(f != NULL);

    char linea[100];

    fgets(linea, sizeof(linea), f);
    assert(strcmp(linea, "SENS_01,23.00,60\n") == 0);

    fgets(linea, sizeof(linea), f);
    assert(strcmp(linea, "SENS_02,23.50,55\n") == 0);

    fgets(linea, sizeof(linea), f);
    assert(strcmp(linea, "SENS_03,21.50,70\n") == 0);

    fclose(f);

    printf("TESTS DE CALIBRACION APROBADOS\n");
}

int main() {
    test_pi();
    test_cesar();
    test_filtro();
    test_picos_con_picos();
    test_matriz_plana();
    test_datalogger();
    test_analizar_temperaturas();
    test_calibracion();
    return 0;
}
