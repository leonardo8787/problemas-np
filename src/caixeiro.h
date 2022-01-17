#ifndef CAIXEIRO_H
#define CAIXEIRO_H

#define INFINITO 99999

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ResultadoRapido(int **matriz, int tam);
int buscaRapidaMenu();
void imprimirRapido();
void caixeiroViajanteAux(int **matriz, int x);
void caixeiroViajante(int **matriz, int inicial);
void iniciaVetores(int tamanho);

#endif
