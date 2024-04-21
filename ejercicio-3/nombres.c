#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CANT_NOMBRES 5
void ingresarNombres(char **punteroACadaPunteroDeCadaNombre);
void mostarNombres(char **punteroACadaPunteroDeCadaNombre);
int main()
{
    char **punteroACadaPunteroDeCadaNombre, *pCadena;

    punteroACadaPunteroDeCadaNombre = &pCadena;

    punteroACadaPunteroDeCadaNombre = (char **) malloc(sizeof(char*) * CANT_NOMBRES);

    ingresarNombres(punteroACadaPunteroDeCadaNombre);
    mostarNombres(punteroACadaPunteroDeCadaNombre);

    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        free(*(punteroACadaPunteroDeCadaNombre + i));
    }
    free(punteroACadaPunteroDeCadaNombre);
    
    return 0;
}

void ingresarNombres(char **punteroACadaPunteroDeCadaNombre)
{
    char buffer[100];   
    int longitudNombre;
    printf("---------- INGRESE LOS NOMBRES ----------\n");
    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        printf("Nombre [%d]: ", i+1);
        fgets(buffer,100, stdin); //esta funcion la saque de internet, esta bien usarla?
        longitudNombre = strlen(buffer)+1;
        *(punteroACadaPunteroDeCadaNombre+i) = (char*) malloc(sizeof(char)* longitudNombre); //hacemos la reserva de memoria para cada uno de los punteros que estan dentro del puntero doble para que sea lo justo par cada nombre
        strcpy(*(punteroACadaPunteroDeCadaNombre+i), buffer);
    }
}

void mostarNombres(char **punteroACadaPunteroDeCadaNombre)
{
    printf("\n---------- LOS NOMBRES INGRESADOS SON: ----------\n");
    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        printf("El Nombre [%d] es: %s", i+1, punteroACadaPunteroDeCadaNombre[i]);
    }
}