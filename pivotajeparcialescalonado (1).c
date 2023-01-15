#include <stdio.h>

#define N 4 // se define una constante N con un valor de 4

void imprimir_matriz(double matriz[N][N])
{ // se define una función para imprimir la matriz con un formato específico
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%.2f\t", matriz[i][j]); // se imprime cada elemento de la matriz con dos decimales
        }
        printf("\n"); // salto de línea después de cada fila
    }
}

int main()
{
    double matriz[N][N]; // se declara la matriz 4x4
    double escalar[N];   // se declara un arreglo escalar de tamaño N
    int pivote[N];       // se declara un arreglo pivote de tamaño N

    printf("Introduce los elementos de la matriz 4x4:\n");
    for (int i = 0; i < N; i++)
    { // ciclo para recibir los elementos de la matriz
        for (int j = 0; j < N; j++)
        {
            if (scanf("%lf", &matriz[i][j]) != 1)
            { // se verifica si la matriz es 4x4
                printf("La matriz introducida no es 4x4, por favor vuelve a intentarlo.\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {                              // ciclo para asignar el escalar y el pivote a cada fila de la matriz
        escalar[i] = matriz[i][0]; // se asigna el primer elemento de cada fila como escalar
        pivote[i] = i;             // se asigna el índice de cada fila como pivote
        for (int j = 1; j < N; j++)
        {
            if (escalar[i] < matriz[i][j])
            { // se busca el valor máximo de cada fila
                escalar[i] = matriz[i][j];
            }
        }
    }

    for (int i = 0; i < N - 1; i++)
    { // ciclo para escalar la matriz utilizando el método de Gauss-Jordan
        double max_ratio = 0;
        int max_ratio_row = i;
        for (int j = i; j < N; j++)
        {
            double ratio = matriz[pivote[j]][i] / escalar[pivote[j]];
            if (ratio > max_ratio)
            { // se busca el máximo ratio entre el elemento y el escalar
                max_ratio = ratio;
                max_ratio_row = j;
            }
        }

        int temp = pivote[i]; // se intercambian los valores de los índices
        pivote[i] = pivote[max_ratio_row];
        pivote[max_ratio_row] = temp;

        for (int j = i + 1; j < N; j++) // se realiza un ciclo para actualizar los valores de la matriz utilizando Gauss-Jordan.
        {
            double factor = matriz[pivote[j]][i] / matriz[pivote[i]][i];
            matriz[pivote[j]][i] = factor;
            for (int k = i + 1; k < N; k++)
            {
                matriz[pivote[j]][k] = matriz[pivote[j]][k] - factor * matriz[pivote[i]][k];
            }
        }
    }

    printf("Matriz escalada:\n"); // se imprime la matriz escalada y se finaliza la ejecucion del programa
    imprimir_matriz(matriz);
    return 0;
}
