#ifndef CAIXEIRO_H
#define CAIXEIRO_H

#include <stdbool.h>

#include "lista.h"

#define VERTICES 10
#define INFINITO 429496729

void resultado();
void caixeiroViajanteAux(int x);
void caixeiroViajante(int inicial);
void iniciaVetores(int tamanho);
void preencheMatriz(Lista *l);

#endif