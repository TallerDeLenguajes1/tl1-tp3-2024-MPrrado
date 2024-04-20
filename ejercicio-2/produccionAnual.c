#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ANIOS 5
#define MESES 12
#define LIM_INF 10000
#define LIM_SUP 50000
#define MAX 15

void cargarMatrizConAleatorios(int matriz[ANIOS][MESES], int lim_inf, int lim_sup);
void mostrarMatriz(int matriz[ANIOS][MESES]);
void promedioAnual(int matriz[ANIOS][MESES]);
void obtenerMes(int indice, char mes[]);
int obtenerAnio(int indice);
void mostrarMayorYMenorProduccion(int matriz[ANIOS][MESES]);

int main ()
{
    int matriz[ANIOS][MESES];
    
    srand(time(NULL));

    cargarMatrizConAleatorios(matriz, LIM_INF, LIM_SUP);
    mostrarMatriz(matriz);

    promedioAnual(matriz);

    mostrarMayorYMenorProduccion(matriz);
    return 0;
}

void cargarMatrizConAleatorios(int matriz[ANIOS][MESES], int lim_inf, int lim_sup)
{
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            matriz[i][j]= rand()%lim_sup + lim_inf;
        }
        
    }
    
}

void mostrarMatriz(int matriz[ANIOS][MESES])
{
    printf("\n");
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
}

void promedioAnual(int matriz[ANIOS][MESES])
{
    int acumuladorProduccion=0;
    float promedioAnual=0;
    printf("\n--------- PROMEDIOS ANUALES ----------\n");
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            acumuladorProduccion = acumuladorProduccion + matriz[i][j];
        }
        promedioAnual=(float)acumuladorProduccion/MESES;
        printf("El promedio del año [%d] es: %.2f\n", i+1, promedioAnual);
        promedioAnual=0;
        acumuladorProduccion = 0;
    }
}

int obtenerAnio(int indice)
{
    int anio;
    switch (indice)
    {
    case 0:
        anio = 2019;
        break;
    case 1:
        anio = 2020;
        break;
    case 2:
        anio = 2021;
        break;
    case 3:
        anio = 2022;
        break;
    case 4:
        anio = 2023;
        break;
    default:
        break;
    }
    return anio;
}

void obtenerMes(int indice, char mes[])
{
    switch (indice)
    {
    case 0:
        strcpy(mes, "Enero");
        break;
    case 1:
        strcpy(mes, "Febrero");
        break;
    case 2:
        strcpy(mes, "Marzo");
        break;
    case 3:
        strcpy(mes, "Abril");
        break;
    case 4:
        strcpy(mes, "Mayo");
        break;
    case 5:
        strcpy(mes, "Junio");
        break;
    case 6:
        strcpy(mes, "Julio");
        break;
    case 7:
        strcpy(mes, "Agosto");
        break;
    case 8:
        strcpy(mes, "Septiembre");
        break;
    case 9:
        strcpy(mes, "Octubre");
        break;
    case 10:
        strcpy(mes, "Noviembre");
        break;
    case 11:
        strcpy(mes, "Diciembre");
        break;
    default:
        break;
    }
}

void mostrarMayorYMenorProduccion(int matriz[ANIOS][MESES])
{
    int anio, max = 0,min=0, indiceAnioMax, indiceAnioMin, indiceMesMax, indiceMesMin;
    char mesMax[MAX], mesMin[MAX];
    min = matriz[0][0];
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            if(max <= matriz[i][j])
            {
                max = matriz[i][j];
                indiceAnioMax=i;
                indiceMesMax=j;
            }
            if(min >= matriz[i][j])
            {
                min = matriz[i][j];
                indiceAnioMin=i;
                indiceMesMin=j;
            }
        }
    }
    anio = obtenerAnio(indiceAnioMax);
    obtenerMes(indiceMesMax, mesMax);
    printf("\n---------- Mayor produccion anual ----------\n");
    printf("[%d]\nanio [%d]\nmes [%s]", matriz[indiceAnioMax][indiceMesMax], anio, mesMax);

    anio = obtenerAnio(indiceAnioMin);
    obtenerMes(indiceMesMin, mesMin);

    printf("\n---------- Menor produccion anual ----------\n");
    printf("[%d]\nanio [%d]\nmes [%s]", matriz[indiceAnioMin][indiceMesMin], anio, mesMin);
}