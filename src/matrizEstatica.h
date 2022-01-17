#ifndef MATRIZ_ESTATICA_H
#define MATRIZ_ESTATICA_H

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#define INFINITO 429496729

int get_tamVertice(int op);
int **inicializaMatriz(int **matriz, int op);
void atribuiMatriz(int **matriz, int op, Lista *l);

#endif