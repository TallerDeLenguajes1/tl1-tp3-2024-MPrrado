
// int filas, columnas;
void cargarMatrizConAleatorios(int matriz[filas][columnas], int lim_inf, int lim_sup)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j]= rand()%lim_sup + lim_inf;
        }
        
    }
    
}

void mostrarMatriz(int matriz[filas][columnas])
{
    printf("\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
}