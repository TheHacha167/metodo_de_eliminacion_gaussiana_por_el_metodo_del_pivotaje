#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprimirMatriz(double **A, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2lf ", A[i][j]);
        }
        printf("\n");
    }
}
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
    imprimirMatriz(A,n);
    
    return 0;
}
