#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CANT_MAX_CLIENTES 5
struct{
    int productoID; //Numerado en ciclo iterativo
    int cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo tiposProductos
    float precioUnitario; // entre 10 - 100
}typedef Producto;

typedef struct cliente{
    int clienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int cantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *productos //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}cliente;


//funciones
int solicitarCargaCantidadClientes();
void cargarDatosCliente(cliente * punteroClientes, int cantidadClientes);
void mostrarClientes(cliente* punteroClientes, int cantidaClientes);
void liberarMemoria(cliente* punteroClientes, int cantidadClientes);
float calcularCostoTotalProducto(Producto producto);
int main()
{
    int cantidadClientes;
    cliente *punteroClientes = NULL;
    float precioTotalProducto;
    srand(time(NULL));
    int bandera = 0, opcion;


    while (bandera == 0)
    {
        printf("---------- INICIO SISTEMA PREVENTISTAS ---------\n\n");

        printf("------SELECCIONE UNA OPICION------\n\n");
        printf("1- Ingresar cantidad clientes\n");
        printf("2- Cargar datos clientes\n");
        printf("3- Mostrar datos clientes\n");
        printf("4- Salir del programa\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                cantidadClientes= solicitarCargaCantidadClientes();
                punteroClientes = (cliente *) malloc(sizeof(cliente) * cantidadClientes);
                break;
            case 2:
                if (punteroClientes == NULL)
                {
                    printf("\nERROR NO INGRESO UNA CANTIDAD DE CLIENTES\n");
                }else
                {
                    cargarDatosCliente(punteroClientes, cantidadClientes); //solo se carga nombre lo demas es de manera aleatoria
                }
                break;
            case 3:
                if (punteroClientes == NULL)
                {
                    printf("\nERROR NO HAY INFORMACION PARA MOSTRAR\n");
                }else
                {
                    mostrarClientes(punteroClientes, cantidadClientes);
                }
                break;
            case 4:
                printf("\nSALIENDO...\n");
                liberarMemoria(punteroClientes, cantidadClientes);
                bandera= 1;
                break;
            default:
                printf("\nERROR SELECCIONE UNA OPCION VALIDA\n");
                break;
        }
    }
    
    return 0;
}



int solicitarCargaCantidadClientes()
{
    int cantidadClientes = 0;
    cliente *punteroClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);
    while (cantidadClientes > CANT_MAX_CLIENTES)
    {
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d", &cantidadClientes);
    }
    return cantidadClientes;
}

void cargarDatosCliente(cliente *punteroClientes , int cantidadClientes)
{
    char buffer[100];
    char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    for (int i = 0; i < cantidadClientes; i++)
    {
        punteroClientes[i].clienteID = i+1;

        printf("\n\nIngrese el nombre del cliente [%d]:", i+1);
        fflush(stdin);
        fgets(buffer, 100, stdin);

        punteroClientes[i].NombreCliente= (char*) malloc(sizeof(char) * strlen(buffer) + 1);

        strcpy(punteroClientes[i].NombreCliente, buffer);

        punteroClientes[i].cantidadProductosAPedir = rand()%5+1;

        punteroClientes[i].productos = (Producto *) malloc(sizeof(Producto) * punteroClientes[i].cantidadProductosAPedir);

        int indice;
        for (int j = 0; j < punteroClientes[i].cantidadProductosAPedir; j++)
        {
            punteroClientes[i].productos[j].productoID = j+100;
            punteroClientes[i].productos[j].cantidad = rand()%10+1;
            indice = rand()%5;
            punteroClientes[i].productos[j].TipoProducto = (char *) malloc(sizeof(char) * strlen(tiposProductos[indice]+1));
        
            strcpy(punteroClientes[i].productos[j].TipoProducto, tiposProductos[indice]);
            punteroClientes[i].productos[j].precioUnitario =(rand()%10001+1000)/100.00;
        }
        
    }
}

void mostrarClientes(cliente *punteroClientes, int cantidadClientes)
{
    float precioTotalProducto;
    float totalPagarCliente =0;
    printf("\n---------DATOS CLIENTES --------- \n\n");
    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("\n\n------------------DATOS CLIENTE [%d] ------------------ \n\n", i+1);
        printf("ID CLIENTE: %d\n", (punteroClientes + i)->clienteID );
        printf("Nombre: %s", (punteroClientes+i)->NombreCliente);
        printf("Cantidad de productos a pedir: %d", (punteroClientes+i)->cantidadProductosAPedir);

        printf("\n\n\t---Productos y cantidades a pedir del cliente [%d]\n", i+1);
        for (int j = 0; j < punteroClientes[i].cantidadProductosAPedir; j++)
        {   
            printf("\t---Producto [%d]---\n", j+1);
            printf("\tTipo: %s\n",(punteroClientes + i)->productos[j].TipoProducto);
            printf("\tLa ID del producto es: %d\n", (punteroClientes + i)->productos[j].productoID);
            printf("\tLa cantidad de este producto es: %d\n", (punteroClientes + i)->productos[j].cantidad);
            printf("\tEl precio unitario es: $%.2f\n", (punteroClientes + i)->productos[j].precioUnitario);
            precioTotalProducto = calcularCostoTotalProducto((punteroClientes + i)->productos[j]);
            printf("\tEl precio total es: $%.2f\n",precioTotalProducto);
            totalPagarCliente = totalPagarCliente + precioTotalProducto;
        }

        printf("\nTotal a pagar del cliente [%d]: $%.2f\n",i+1, totalPagarCliente);
        totalPagarCliente = 0;
    }
}

void liberarMemoria(cliente *punteroClientes, int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        free(punteroClientes[i].productos);
    }
    free(punteroClientes);
    
}

float calcularCostoTotalProducto(Producto producto)
{
    float precioTotalProducto;
    precioTotalProducto = producto.cantidad * producto.precioUnitario;
    return precioTotalProducto;
}
