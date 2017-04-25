#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

int validaNombre(char nombre[]);//valida q sean letras lo ingresado

void inicializacionArray(EPersona persona[],int tam);//inicializa el array

void bajaPersona(EPersona persona[],int tam);//funcion para dar de baja la persona

void altaPersona(EPersona persona[],int tam);//funcion para dar de alta la persona

void mostrarPersona(EPersona persona[],int tam);//funcion q muestra las personas ingresadas

void grafico(EPersona persona[],int tam);//funcion q  muestra el grafico de edades

int validaNumEntero(int num,int tamMin,int tamMax);//funcion q valida q la edad ingresada este entre 0 y 150 como maximo

int validaDni(long int dni);//valida q el dni sea de 8 digitos y q sean numeros
#endif // FUNCIONES_H_INCLUDED
