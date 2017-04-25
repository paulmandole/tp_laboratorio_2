#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define E 20


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona persona[E];
    inicializacionArray(persona,E);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaPersona(persona,E);
                break;
            case 2:
                bajaPersona(persona,E);
                break;
            case 3:
                mostrarPersona(persona,E);
                break;
            case 4:
                grafico(persona,E);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("no ingreso una opcion correcta\n");
                system("pause");
                break;
        }
    }

    return 0;
}
