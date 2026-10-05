// Práctica 5: El mayor de tres números
// Traduce TU receta de RECETA.md a C++, paso por paso.

#include <iostream>
#include "utilerias.h"

int main() {
    // Variables (siempre inicializadas)
    double numero1 = 0.0;
    double numero2 = 0.0;
    double numero3 = 0.0;
    double mayor = 0.0;

    // Paso 1: mensaje de bienvenida
    std::cout << "Bienvenido a mi programa" << std::endl;

    // Paso 2: leer el primer número
    numero1 = leerDecimal("Ingresa el primer numero: ");

    // Paso 3: leer el segundo número
    numero2 = leerDecimal("Ingresa el segundo numero: ");

    // Paso 4: leer el tercer número
    numero3 = leerDecimal("Ingresa el tercer numero: ");

    // Paso 5: guardar numero1 como el mayor
    mayor = numero1;

    // Paso 6: comparar numero2 con el mayor
    if (numero2 > mayor) {
    mayor = numero2;
}

    // Paso 7: comparar numero3 con el mayor
    if (numero3 > mayor) {
        mayor = numero3;
    }

    // Paso 8: mostrar el resultado
    std::cout << "El numero mayor es: " << mayor << std::endl;

    // Paso 9: terminar
    return 0;
}
