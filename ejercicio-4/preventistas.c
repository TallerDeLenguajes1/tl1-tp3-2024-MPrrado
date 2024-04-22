#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CANT_MAX_CLIENTES
struct{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef producto;

struct{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    producto *Productos //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}typedef cliente;

int main()
{
    int cantidadClientes;
    cliente *punteroClientes;
    char buffer[100];

    printf("---------- INICIO SISTEMA PREVENTISTAS ---------\n\n");
    while (cantidadClientes <= CANT_MAX_CLIENTES)
    {
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d", cantidadClientes);
    }
    punteroClientes = (cliente*) malloc(sizeof(cliente) * cantidadClientes);
    printf("\n---------- Cargue los datos de los clientes ---------- ");

    //carga de datos de cada cliente que se genera
    for (int i = 0; i < cantidadClientes; i++)
    {
        punteroClientes[i].ClienteID = i+1;

        printf("Ingrese el nombre del cliente [%d]:", i+1);
        fgets(buffer, 100, stdin);

        punteroClientes[i].NombreCliente= (char*) malloc(sizeof(char) * strlen(buffer) + 1);

        strcpy(punteroClientes[i].NombreCliente, buffer);

        punteroClientes[i].CantidadProductosAPedir = rand()%5+1;

        punteroClientes[i].Productos = (producto *) malloc(sizeof(producto) * punteroClientes[i].CantidadProductosAPedir);

        for (int j = 0; j < punteroClientes[i].CantidadProductosAPedir; j++)
        {
            punteroClientes[i].Productos[j].ProductoID = j+1;
            punteroClientes[i].Productos[j]. = j+1;
        }
        

        
    }
    

       
    return 0;
}
