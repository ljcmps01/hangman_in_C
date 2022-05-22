#include "hangman.h"

int inicializarVector(char *palabra,int vAdivinados[],int tam)
{
    int error=0;
    for(int i=0;i<tam;i++)
    {
        if(palabra[i]!=32)
        {
            vAdivinados[i]=0;
            palabra[i]=toupper(palabra[i]);
        }
        else
        {
            vAdivinados[i]=1;
        }
    }

    return error;
}

int mostrarVector(int vVector[],int tam)
{
    int error=0;
    for(int i=0;i<tam;i++)
    {
        printf("|%d| ",vVector[i]);
    }
    printf("\n");
    return error;
}

int palabraOculta(char *palabra,int vAdivinados[],int tam)
{
    int error=0;

    for(int i=0;i<tam;i++)
    {
        if(palabra[i]!=32)
        {
            if(!vAdivinados[i])
            {
                printf("_ ");
            }
            else
            {
                printf("%c",palabra[i]);
            }
        }
        else
        {
            printf("  ");
        }
    }
    printf("\n");

    return error;
}

int intentoAdivinar(char *palabra,int vAdivinados[],int tam,char intento)
{
    int resultado=0;
    int caracter=toupper(intento);

    if(caracter>=65&&caracter<=90)
    {
        for(int i=0;i<tam;i++)
        {
            if(caracter==palabra[i])
            {
                vAdivinados[i]=1;
                resultado++;
            }
        }
    }

    else
    {

        resultado=-1;
    }
    return resultado;
}

int checkearVictoria(int vAdivinados[],int tam)
{
    int contador=0;
    int victoria=0;
    for(int i=0;i<tam;i++)
    {
        if(vAdivinados[i])
        {
            contador++;
        }
    }
    if(contador>=tam)
    {
        victoria=1;
    }
    return victoria;
}
