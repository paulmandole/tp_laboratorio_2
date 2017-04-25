#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
void inicializacionArray(EPersona persona[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        persona[i].estado=0;

    }

}
void altaPersona(EPersona persona[],int tam)
{
    int i,flag=0,tamMin=0,retorno,tamMax=150,rta,ret;

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==0)
        {
            do
            {
                printf("ingrese nombre: ");
                fflush(stdin);
                gets(persona[i].nombre);
                rta=validaNombre(persona[i].nombre);

            }
            while(rta==0);

            do
            {
                printf("ingrese edad: ");
                scanf("%d",&persona[i].edad);
                retorno=validaNumEntero(persona[i].edad,tamMin,tamMax);


            }
            while(retorno==0);
            do
            {
                printf("ingrese el dni de la persona: ");
                scanf("%ld",&persona[i].dni);
                ret=validaDni(persona[i].dni);
            }while(ret==0);


            flag=1;

            persona[i].estado=1;
            break;
        }


    }
    if(flag==0)
    {
        printf("ERROR NO HAY MAS MEMORIA DISPONIBLE PARA GUARDAR LA PERSONA.");
    }
    system("pause");
    system("cls");

}
void bajaPersona(EPersona persona[],int tam)
{
    int i,flag=0;
    long int dniAux;
    char rta;
    printf("ingrese el dni a buscar: ");
    scanf("%ld",&dniAux);
    for(i=0; i<tam; i++)
    {
        if(dniAux==persona[i].dni&&persona[i].estado==1)
        {
            printf("%s\t%ld\t%d\n\n",persona[i].nombre,persona[i].dni,persona[i].edad);

            printf("esta seguro q desea borrar esta persona?\n");
            fflush(stdin);
            scanf("%c",&rta);

            if(rta=='s')
            {
                persona[i].estado=0;
                printf("la inforamcion a sido borrada.");
                flag=1;
                break;
            }
            else
            {
                printf("ACCION CANCELADA!!!.");
            }
        }

    }
    if(flag==0)
    {
        printf("el dni ingresado no se encontro.\n");
    }
    system("pause");
    system("cls");

}

void mostrarPersona(EPersona persona[],int tam)
{
    EPersona auxPersona;
    int i,j;

    for (i =0; i<tam-1; i++)
    {
        for(j=1; j<tam; j++)
        {
            if(strcasecmp(persona[i].nombre,persona[j].nombre)<0)
            {
                auxPersona=persona[i];
                persona[i]=persona[j];
                persona[j]=auxPersona;
            }
        }
    }

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1)
        {
            printf("%s\t%ld\t%d\n",persona[i].nombre,persona[i].dni,persona[i].edad);
        }
    }
    system("pause");
    system("cls");
}

int validaNumEntero(int num,int tamMin,int tamMax)
{
    int retorno=0;

    if(num>tamMin&&num<tamMax)
    {
        retorno=1;
    }
    else
    {
        printf("ERROR EL DATO INGRESADO NO ES VALIDO REINGRESE!!\n");
    }

    return retorno;

}
int validaNombre(char nombre[50])
{
    int retorno=1,tam,i;

    tam=strlen(nombre);


    for(i=0; i<tam; i++)
    {
        if(isalpha(nombre[i])==0&&isspace(nombre[i])==0)
        {
            printf("ERROR EL DATO INGRESADO NO ES VALIDO REINGRESE!!\n");
            retorno=0;
            break;

        }

    }
    return retorno;
}
void grafico(EPersona persona[],int tam)
{
    int i,flag=0;
   int contMenores18=0,cont1935=0,contMay35=0,mayor;



    for(i=0;i<tam;i++)
    {
        if(persona[i].estado==1)
          {
                   if(persona[i].edad<=18&&persona[i].edad>=1)
                   {
                            contMenores18++;

                   }
                   else if(persona[i].edad>=35)
                   {
                     contMay35++;

                   }
                   else
                   {
                      cont1935++;


                   }
         }


    }

     if(contMenores18>=cont1935&&contMenores18>=contMay35)
     {
         mayor=contMenores18;
     }
     else if(cont1935>=contMay35&&cont1935>=contMenores18)
     {
         mayor=cont1935;
     }
     else
     {
         mayor=contMay35;
     }


     for(i=mayor; i>0; i--)
    {
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<=contMenores18)
        {
            printf("*");
        }
        if(i<=cont1935)
        {
            flag=1;
            printf("\t*");
        }
        if(i<=contMay35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }

        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n\n", contMenores18, cont1935, contMay35);

    system("pause");
    system("cls");



}
int validaDni(long int dni)
{
    int retorno=1,num,i;
    char cadDni[50];
    sprintf(cadDni,"%ld",dni);

    num=strlen(cadDni);
    for(i=0;i<num;i++)
    {
        if(num!=8)
        {
            printf("ERROR EL DATO INGRESADO NO ES VALIDO REINGRESE!!\n");
            retorno=0;
            break;

        }

    }

    return retorno;

}


