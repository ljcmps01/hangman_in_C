#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED
#include <string.h>
#include <stdio.h>

#endif // HANGMAN_H_INCLUDED

int inicializarVector(char *palabra,int vAdivinados[],int tam);
int mostrarVector(int vVector[],int tam);

int palabraOculta(char *palabra,int vAdivinados[],int tam);
int intentoAdivinar(char *palabra,int vAdivinados[],int tam,char intento);

int checkearVictoria(int vAdivinados[],int tam);

