//Ejecutar el programa usando:

// g++ -fopenmp Inciso4.c -o Inciso4
// ./Inciso4

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int num_hilos, i;
    int N;
    double a = 5.0;
    
    // Solicitar el número de hilos al usuario
    printf("Ingrese el numero de hilos con los que desea trabajar (8, 16, 32): ");
    scanf("%d", &num_hilos);
    N = num_hilos;

    // Inicializar los arrays x e y
    int x[N];
    double y[N];
    
    // Llenar el array x con números pares
    #pragma omp parallel for num_threads(num_hilos)
    for (i = 0; i < N; i++) {
        x[i] = 2 * (i + 1);
    }

    // Calcular el valor de y para cada x en paralelo
    #pragma omp parallel for num_threads(num_hilos)
    for (i = 0; i < N; i++) {
        y[i] = (0.5 * a) + (x[i] * x[i]);
    }

    // Imprimir los resultados
    printf(" x   |   y\n");
    printf("-----------\n");
    for (i = 0; i < N; i++) {
        printf("%d   |  %.2f\n", x[i], y[i]);
    }

    return 0;
}
