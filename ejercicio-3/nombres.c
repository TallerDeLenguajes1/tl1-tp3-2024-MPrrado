#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// #define CANT_NOMBRES 5
void ingresarNombres(char **punteroALosPunteroDeCadaNombre, int cantidadNombres);
void mostarNombres(char **punteroALosPunteroDeCadaNombre, int cantidadNombres);
int main()
{
    char **punteroALosPunteroDeCadaNombre, *pCadena;
    punteroALosPunteroDeCadaNombre = &pCadena;
    int cantidadNombres;
    
    printf ("----------INICIO PROGRAMA NOMBRES----------\n\n");
    printf("Ingrese la cantidad de nombres que desea cargar:");
    scanf("%d", &cantidadNombres);
    fflush(stdin);
    punteroALosPunteroDeCadaNombre = (char **) malloc(sizeof(char*) * cantidadNombres);

    ingresarNombres(punteroALosPunteroDeCadaNombre, cantidadNombres);
    mostarNombres(punteroALosPunteroDeCadaNombre, cantidadNombres);


    for (int i = 0; i < cantidadNombres; i++)
    {
        free(*(punteroALosPunteroDeCadaNombre + i));
    }
    free(punteroALosPunteroDeCadaNombre);
    
    return 0;
}

void ingresarNombres(char **punteroALosPunteroDeCadaNombre, int cantidadNombres)
{
    char buffer[100];   
    int longitudNombre;
    printf("\n---------- INGRESE LOS NOMBRES ----------\n");
    for (int i = 0; i < cantidadNombres; i++)
    {
        printf("Nombre [%d]: ", i+1);
        fgets(buffer,100, stdin); //esta funcion la saque de internet, esta bien usarla?
        longitudNombre = strlen(buffer)+1;
        *(punteroALosPunteroDeCadaNombre+i) = (char*) malloc(sizeof(char)* longitudNombre); //hacemos la reserva de memoria para cada uno de los punteros que estan dentro del puntero doble para que sea lo justo par cada nombre
        strcpy(*(punteroALosPunteroDeCadaNombre+i), buffer);
    }
}

void mostarNombres(char **punteroALosPunteroDeCadaNombre, int cantidadNombres)
{
    printf("\n---------- LOS NOMBRES INGRESADOS SON: ----------\n");
    for (int i = 0; i < cantidadNombres; i++)
    {
        printf("El Nombre [%d] es: %s", i+1, punteroALosPunteroDeCadaNombre[i]);
    }
}