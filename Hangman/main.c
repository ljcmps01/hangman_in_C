/*
TODO:
    * Fortalecer ingreso de char
    * Modo configuracion de palabra secreta

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hangman.h"

#define PALABRA "palabra"
#define MAX_CHAR 16
#define VIDAS_MAXIMAS 5

int main()
{
    char palabraSecreta[MAX_CHAR]=PALABRA;
    int adivinados[MAX_CHAR]={};
    int cChar=strlen(palabraSecreta);
    int vidas=VIDAS_MAXIMAS;
    char intento;
    int acierto;

    if(inicializarVector(palabraSecreta,adivinados,cChar))
    {
        printf("ERROR INICIALIZANDO EL VECTOR\n");
        system("PAUSE");
    }

    if(mostrarVector(adivinados,cChar))
    {
        printf("ERROR MOSTRANDO EL VECTOR\n");
        system("PAUSE");
    }

    while(vidas)
    {
        if(palabraOculta(palabraSecreta,adivinados,cChar))
        {
            printf("ERROR IMPRIMIENDO LA PALABRA OCULTA\n");
        }
        printf("\nIngrese una letra: ");

        scanf("%c",&intento);
        fflush(stdin);
        acierto=intentoAdivinar(palabraSecreta,adivinados,cChar,intento);

        system("cls");

        if(acierto>0)
        {
            printf("BIEN! ADIVINASTE %d LETRA/S\n",acierto);
            if(checkearVictoria(adivinados,cChar))
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
            if(acierto==0)
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
            else
            {
                printf("CARACTER INGRESADO NO VALIDO\n");
            }

        }

    }


    printf("%s\n",palabraSecreta);
    system("PAUSE");
    return 0;
}
