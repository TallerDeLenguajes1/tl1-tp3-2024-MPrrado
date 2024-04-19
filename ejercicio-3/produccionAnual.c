#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ANIOS 5
#define MESES 12
#define LIM_INF 10000
#define LIM_SUP 50000


void cargarMatrizConAleatorios(int matriz[ANIOS][MESES], int lim_inf, int lim_sup);

void mostrarMatriz(int matriz[ANIOS][MESES]);
void promedioAnual(int matriz[ANIOS][MESES]);
 
int main ()
{
    int matriz[ANIOS][MESES];
    srand(time(NULL));
    cargarMatrizConAleatorios(matriz, LIM_INF, LIM_SUP);
    mostrarMatriz(matriz);
    promedioAnual(matriz);
    //a)
    // for (int i = 0; i < ANIOS; i++)
    // {
    //     for (int j = 0; j < MESES; j++)
    //     {
    //         matriz[i][j]= rand()%LIM_SUP + LIM_INF;
    //     }
        
    // }

    // //b)
    // printf("\n");
    // for (int i = 0; i < ANIOS; i++)
    // {
    //     for (int j = 0; j < MESES; j++)
    //     {
    //         printf("%d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    // //c)
    // int acumuladorProduccion=0;
    // float promedioAnual=0;
    // for (int i = 0; i < ANIOS; i++)
    // {
    //     for (int j = 0; j < MESES; j++)
    //     {
    //         acumuladorProduccion = acumuladorProduccion + matriz[i][j];
    //     }
    //     promedioAnual=(float)acumuladorProduccion/MESES;
    //     printf("El promedio del año [%d] es: %.2f\n", i+1, promedioAnual);
    //     promedioAnual=0;
    // }

    // //d)
    int max = 0, min=0, indiceAnioMax, indiceMesMax, indiceAnioMin, indiceMesMin;
    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            if(max < matriz[i][j])
            {
                max = matriz[i][j];
                indiceAnioMax=i;
                indiceMesMax=j;
            }
            if(min > matriz[i][j])
            {
                min = matriz[i][j];
                indiceAnioMin=i;
                indiceMesMin=j;
            }
        }
    }

    char mesMax[20], mesMin[20];
    int anioMax, anioMin;
    switch (indiceAnioMax)
    {
    case 0:
        anioMax = 2019;
        break;
    case 1:
        anioMax = 2020;
        break;
    case 2:
        anioMax = 2021;
        break;
    case 3:
        anioMax = 2022;
        break;
    case 4:
        anioMax = 2023;
        break;
    default:
        break;
    }

    switch (indiceMesMax)
    {
    case 0:
        strcpy(mesMax, "Enero");
        break;
    case 1:
        strcpy(mesMax, "Febrero");
        break;
    case 2:
        strcpy(mesMax, "Marzo");
        break;
    case 3:
        strcpy(mesMax, "Abril");
        break;
    case 4:
        strcpy(mesMax, "Mayo");
        break;
    case 5:
        strcpy(mesMax, "Junio");
        break;
    case 6:
        strcpy(mesMax, "Julio");
        break;
    case 7:
        strcpy(mesMax, "Agosto");
        break;
    case 8:
        strcpy(mesMax, "Septiembre");
        break;
    case 9:
        strcpy(mesMax, "Octubre");
        break;
    case 10:
        strcpy(mesMax, "Noviembre");
        break;
    case 11:
        strcpy(mesMax, "Diciembre");
        break;
    default:
        break;
    }
    
    // switch (indiceAnioMax)
    // {
    // case 0:
    //     anioMin = 2019;
    //     break;
    // case 1:
    //     anioMin = 2020;
    //     break;
    // case 2:
    //     anioMin = 2021;
    //     break;
    // case 3:
    //     anioMin = 2022;
    //     break;
    // case 4:
    //     anioMin = 2023;
    //     break;
    // default:
    //     break;
    // }

    // switch (indiceMesMin)
    // {
    // case 0:
    //     mesMax = "Enero";
    //     break;
    // case 1:
    //     mesMax = "Febrero";
    //     break;
    // case 2:
    //     mesMax = "Marzo";
    //     break;
    // case 3:
    //     mesMax = "Abril";
    //     break;
    // case 4:
    //     mesMax = "Mayo";
    //     break;
    // case 5:
    //     mesMax = "Junio";
    //     break;
    // case 6:
    //     mesMax = "Julio";
    //     break;
    // case 7:
    //     mesMax = "Agosto";
    //     break;
    // case 8:
    //     mesMax = "Septiembre";
    //     break;
    // case 9:
    //     mesMax = "Octubre";
    //     break;
    // case 10:
    //     mesMax = "Noviembre";
    //     break;
    // case 11:
    //     mesMax = "Diciembre";
    //     break;
    // default:
    //     break;
    // }

    printf("\n---------- Mayor produccion anual ----------\n");
    printf("[%d]\nanio [%d]\nmes [%s]", matriz[indiceAnioMax][indiceMesMax], anioMax, mesMax);
    getchar();
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
    printf("--------- PROMEDIOS ANUALES ----------\n");
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