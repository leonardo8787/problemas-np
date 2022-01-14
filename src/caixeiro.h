#ifndef CAIXEIRO_H
#define CAIXEIRO_H

#include <stdbool.h>
#include <stdio.h>

#define VERTICES 4
#define INFINITO 429496729

void resultado();
void caixeiroViajanteAux(int x);
void caixeiroViajante(int inicial);
void iniciaVetores();
void preencheMatriz(int valor[][VERTICES]);

#endif