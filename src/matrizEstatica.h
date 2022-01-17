#ifndef MATRIZ_ESTATICA_H
#define MATRIZ_ESTATICA_H

#include <stdio.h>
#include <stdlib.h>

#define INFINITO 99999

int get_tamVertice(int op);
int **inicializaMatriz(int **matriz, int op);
int **atribuiMatriz(int **matriz, int op);
void printMatrix(int **matrix, int tam);

#endif
