/*
TODO:
    * Fortalecer ingreso de char
    * Modo configuracion de palabra secreta

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hangman.h"

#define PALABRA "hola mundo"
#define cCHAR 10
#define VIDAS_MAXIMAS 5

int main()
{
    char palabraSecreta[20]=PALABRA;
    int adivinados[cCHAR]={};
    int vidas=VIDAS_MAXIMAS;
    char intento;
    int acierto;

    if(inicializarVector(palabraSecreta,adivinados,cCHAR))
    {
        printf("ERROR INICIALIZANDO EL VECTOR\n");
        system("PAUSE");
    }

    if(mostrarVector(adivinados,cCHAR))
    {
        printf("ERROR MOSTRANDO EL VECTOR\n");
        system("PAUSE");
    }

    while(vidas)
    {
        if(palabraOculta(palabraSecreta,adivinados,cCHAR))
        {
            printf("ERROR IMPRIMIENDO LA PALABRA OCULTA\n");
        }
        printf("\nIngrese una letra: ");

        scanf("%c",&intento);
        fflush(stdin);
        acierto=intentoAdivinar(palabraSecreta,adivinados,cCHAR,intento);

        system("cls");

        if(acierto)
        {
            printf("BIEN! ADIVINASTE %d LETRA/S\n",acierto);
            if(checkearVictoria(adivinados,cCHAR))
            {
                printf("\t\t#########################\n");
                printf("\t\t#                       #\n");
                printf("\t\t#       GANASTE! :D     #\n");
                printf("\t\t#                       #\n");
                printf("\t\t#########################\n");
                break;
            }
        }
        else
        {
            vidas--;
            printf("LO SIENTO :( NO ACERTASTE, TE QUEDAN %d VIDA/S\n",vidas);
            if(!vidas)
            {
                printf("\t\t#########################\n");
                printf("\t\t#                       #\n");
                printf("\t\t#       PERDISTE :(     #\n");
                printf("\t\t#                       #\n");
                printf("\t\t#########################\n");
            }
        }

    }


    printf("%s\n",palabraSecreta);
    system("PAUSE");
    return 0;
}
