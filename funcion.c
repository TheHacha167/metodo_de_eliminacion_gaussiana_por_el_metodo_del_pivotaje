#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Función que hace la salida de la matriz final
void imprimirMatriz(double **A, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2lf ", A[i][j]);
        }
        printf("\n");
    }
}
/*
La función main pide al usuario el tamaño
de la matriz cuadrada (este paso se puede omitir por una variable global fija)
y asignando memoria dinámica para esta matriz y un arreglo llamado "scale".
Luego se pide al usuario que ingrese los valores de la matriz.

El siguiente bucle for calcula el valor máximo de cada fila de la
matriz A y lo almacena.

Hay un bucle for anidado que se encarga de encontrar el elemento
mayor de la columna y cambia su correspondiente fila con k ( la fila k es solo si no está previamente ),

El siguiente for es para convertir la matriz A en la matriz.

Usamos el "free(scale);" para liberar la memoria de la variable
y despúes hacemos la llamada a la funcion que imprime la matriz A.
*/
int main()
{
    int n, i, j, k, maxI, temp;
    double maxVal, tempf, **A;
    double *scale;

    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);
    // memoria dinámica matriz A
    A = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
    {
        A[i] = (double *)malloc(n * sizeof(double));
    }
    scale = (double *)malloc(n * sizeof(double));
    // valores matriz A
    printf("Ingrese los valores de la matriz:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        scale[i] = 0;
        for (j = 0; j < n; j++)
        {
            if (scale[i] < fabs(A[i][j]))
                scale[i] = fabs(A[i][j]);
        }
    }

    for (k = 0; k < n - 1; k++)
    {
        maxI = k;
        maxVal = fabs(A[k][k] / scale[k]);
        for (i = k + 1; i < n; i++)
        {
            tempf = fabs(A[i][k] / scale[i]);
            if (tempf > maxVal)
            {
                maxVal = tempf;
                maxI = i;
            }
        }

        if (maxI != k)
        {
            for (j = 0; j < n; j++)
            {
                tempf = A[k][j];
                A[k][j] = A[maxI][j];
                A[maxI][j] = tempf;
            }
            temp = scale[k];
            scale[k] = scale[maxI];
            scale[maxI] = temp;
        }
        for (i = k + 1; i < n; i++)
        {
            A[i][k] = A[i][k] / A[k][k];
            for (j = k + 1; j < n; j++)
            {
                A[i][j] = A[i][j] - A[i][k] * A[k][j];
            }
        }
    }

    free(scale);
    imprimirMatriz(A, n);

    return 0;
}
