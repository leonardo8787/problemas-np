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
// #ifndef ESTATICA_H
// #define ESTATICA_H

// #include <stdio.h>
// #include <stdlib.h>

// #define INFINITO 429496729

// void teste();
// // void imprimir();
// // void caixeiroViajanteAux(int x);
// // void caixeiroViajante(int inicial);
// // void iniciaVetores(int tamanho);
// // void preencheMatriz(Lista *l);
// // void mallocar();

// #endif