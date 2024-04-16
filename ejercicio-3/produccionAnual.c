#include <stdio.h>
#include "../funciones.h"
#include <time.h>

#define ANIOS 5
#define MESES 12
#define LIM_INF 10000
#define LIM_SUP 50000


// void cargarMatrizConAleatorios(int matriz[ANIOS][MESES], int lim_inf, int lim_sup);

// void mostrarMatriz(int matriz[ANIOS][MESES]);
 
int main ()
{
    int matriz[ANIOS][MESES];
    
    cargarMatrizConAleatorios(matriz, LIM_INF, LIM_SUP);
    mostrarMatriz(matriz);

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
    // int max = 0, min=0, indiceAnioMax, indiceMesMax, indiceAnioMin, indiceMesMin;
    // for (int i = 0; i < ANIOS; i++)
    // {
    //     for (int j = 0; j < MESES; j++)
    //     {
    //         if(max < matriz[ANIOS][MESES])
    //         {
    //             max = matriz[ANIOS][MESES];
    //             indiceAnioMax=i+1;
    //             indiceMesMax=j+1;
    //         }
    //         if(min > matriz[ANIOS][MESES])
    //         {
    //             min = matriz[ANIOS][MESES];
    //             indiceAnioMin=i+1;
    //             indiceMesMin=j+1;
    //         }
    //     }
    // }

    // char anioMax[20],mesMax[20],anioMin[20], mesMin[20];
    // switch (indiceAnioMax)
    // {
    // case 0:
    //     anioMax = "2019";
    //     break;
    // case 1:
    //     anioMax = "2020";
    //     break;
    // case 2:
    //     anioMax = "2021";
    //     break;
    // case 3:
    //     anioMax = "2022";
    //     break;
    // case 4:
    //     anioMax = "2023";
    //     break;
    // default:
    //     break;
    // }

    // switch (indiceMesMax)
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
    
    // switch (indiceAnioMin)
    // {
    // case 0:
    //     anioMax = "2019";
    //     break;
    // case 1:
    //     anioMax = "2020";
    //     break;
    // case 2:
    //     anioMax = "2021";
    //     break;
    // case 3:
    //     anioMax = "2022";
    //     break;
    // case 4:
    //     anioMax = "2023";
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

    // printf("La mayor produccion fue \n[%d] \nanio [%s] \nmes [%s]", matriz[indiceAnioMax][indiceMesMax], anioMax, mesMax);
    getchar();
    return 0;
}

// void cargarMatrizConAleatorios(int matriz[ANIOS][MESES], int lim_inf, int lim_sup)
// {
//     for (int i = 0; i < ANIOS; i++)
//     {
//         for (int j = 0; j < MESES; j++)
//         {
//             matriz[i][j]= rand()%lim_sup + lim_inf;
//         }
        
//     }
    
// }

// void mostrarMatriz(int matriz[ANIOS][MESES])
// {
//     printf("\n");
//     for (int i = 0; i < ANIOS; i++)
//     {
//         for (int j = 0; j < MESES; j++)
//         {
//             printf("%d ", matriz[i][j]);
//         }
//         printf("\n");
//     }
    
// }