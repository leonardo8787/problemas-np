/*
*	Problema do Caixeiro Viajante em C
*	Utilizando uma matriz de distância para representar um grafo não direcionado.
*	Objetivo: Encontrar o menor caminho que passe por todos os vértices sem repetir nenhum, e chegar novamente ao vértice de início
*
*                      6
*                 (4)-----(0)
*                 |  \    / \ 
*                 |   \ 3/   \2 
*                 |    \/     \ 
*                3|    /\     (1)
*                 |   / 3\   4/ |
*                 |  /    \  /  |
*                 (3)-----(2)   |
*                  |   7        | 
*                  |            | 3
*                  --------------
*
*
*   Matriz de Distância
*       0  1  2  3  4 
*    0  0  2  -  3  6
*    1  2  0  4  3  -
*    2  -  4  0  7  3
*    3  3  3  7  0  3
*    4  6  -  3  3  0
*
*
*/

#include <stdio.h>
#include <time.h>
#include "caixeiro.h"


int main(){
	double inicio = clock();
	iniciaVetores();

	int matriz1[4][4] = {
		{0,   10, 15,  20},
		{10,   0, 35,  25},
		{15,  35,  0,  30},
		{20,  25, 30,   0}
	};

	int matriz2[10][10]  = {
		{0,         18,         30,         7,          INFINITO,   INFINITO,   INFINITO,   INFINITO,   INFINITO,   INFINITO},
		{18,        0,          25,         INFINITO,   20,         30,         INFINITO,   INFINITO,   INFINITO,   INFINITO},
		{30,        25,         0,          INFINITO,   30,         20,         INFINITO,   INFINITO,   60,         INFINITO},
		{7,         INFINITO,   INFINITO,   0,          40,         INFINITO,   INFINITO,   INFINITO,   17,         INFINITO},
		{INFINITO,  20,         30,         40,         0,          10,         5,          INFINITO,   INFINITO,   INFINITO},
		{INFINITO,  30,         20,         INFINITO,   10,         0,          9,          INFINITO,   INFINITO,   60},
		{INFINITO,  INFINITO,   INFINITO,   INFINITO,   5,          9,          0,          INFINITO,   50,         50},
		{INFINITO,  INFINITO,   INFINITO,   INFINITO,   4,          INFINITO,   INFINITO,   0,          40,         38},
		{INFINITO,  INFINITO,   50,         17,         INFINITO,   INFINITO,   42,         37,         0,          20},
		{INFINITO,  INFINITO,   INFINITO,   INFINITO,   INFINITO,   60,         37,         38,         20,         0}
	};

	int matriz3[5][5] = {
		{0,7,5,INFINITO,4},
		{7,0,2,8,1},
		{5,2,0,10,6},
		{INFINITO,8,10,0,3},
		{4,1,6,3,0}
	};

	int matriz4[5][5] = {
		{          0,          2,   INFINITO, 3,          6 },
		{          2,          0,          4, 3,   INFINITO },
		{   INFINITO,          4,          0, 7,          3 },
		{          3,          3,          7, 0,          3 },
		{          6,   INFINITO,          3, 3,          0 }
	};

	int matriz5[18][18] = {
		{0,20,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,39,INFINITO,INFINITO,INFINITO,29,37,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
		{20,0,25,INFINITO,INFINITO,INFINITO,INFINITO,28,INFINITO,INFINITO,INFINITO,39,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
		{INFINITO,25,0,25,INFINITO,INFINITO,INFINITO,30,INFINITO,INFINITO,INFINITO,INFINITO,54,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
		{INFINITO,INFINITO,25,0,39,32,42,INFINITO,23,33,INFINITO,INFINITO,INFINITO,35,INFINITO,INFINITO,INFINITO,INFINITO},
		{INFINITO,INFINITO,INFINITO,39,0,12,26,INFINITO,INFINITO,19,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
		{INFINITO,INFINITO,INFINITO,32,12,0,17,INFINITO,INFINITO,35,30,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
		{INFINITO,INFINITO,INFINITO,42,26,17,0,INFINITO,INFINITO,INFINITO,38,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
		{39,28,30,INFINITO,INFINITO,INFINITO,INFINITO,0,INFINITO,INFINITO,INFINITO,25,22,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
		{INFINITO,INFINITO,INFINITO,23,INFINITO,INFINITO,INFINITO,INFINITO,0,26,INFINITO,INFINITO,34,56,INFINITO,43,INFINITO,INFINITO},
		{INFINITO,INFINITO,INFINITO,33,19,35,INFINITO,INFINITO,26,0,24,INFINITO,INFINITO,30,19,INFINITO,INFINITO,INFINITO},
		{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,30,38,INFINITO,INFINITO,24,0,INFINITO,INFINITO,INFINITO,26,INFINITO,INFINITO,36},
		{29,39,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,25,INFINITO,INFINITO,INFINITO,0,27,INFINITO,INFINITO,43,INFINITO,INFINITO},
		{37,INFINITO,54,INFINITO,INFINITO,INFINITO,INFINITO,22,34,INFINITO,INFINITO,27,0,24,INFINITO,19,INFINITO,INFINITO},
		{INFINITO,INFINITO,INFINITO,56,INFINITO,INFINITO,INFINITO,INFINITO,35,30,INFINITO,INFINITO,24,0,20,19,17,INFINITO},
		{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,19,26,INFINITO,INFINITO,20,0,INFINITO,18,21},
		{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,43,INFINITO,INFINITO,43,19,19,INFINITO,0,19,INFINITO},
		{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,17,18,26,0,15},
		{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,36,INFINITO,INFINITO,INFINITO,21,INFINITO,15,0}
	};

	int matriz6[10][10] = {
		{0, 185, 119, 152, 133, 321, 297, 277, 412, 381},
		{185, 0, 121, 150, 200, 404, 458, 492, 379, 427},
		{119, 121, 0, 174, 120, 332, 439, 348, 245, 443},
		{152, 150, 174, 0, 199, 495, 480, 500, 454, 489},
		{133, 200, 120, 199, 0, 315, 463, 204, 396, 487},
		{321, 404, 332, 495, 315, 0, 356, 211, 369, 222},
		{297, 458, 439, 480, 463, 356, 0, 471, 241, 235},
		{277, 492, 348, 500, 204, 211, 471, 0, 283, 478},
		{412, 379, 245, 454, 396, 369, 241, 283, 0, 304},
		{381, 427, 443, 489, 487, 222, 235, 478, 304, 0} 
	};

	printf("%ld\n", sizeof(matriz1[0]) / sizeof(int));
	printf("%ld\n", sizeof(matriz2[0]) / sizeof(int));
	printf("%ld\n", sizeof(matriz3[0]) / sizeof(int));
	printf("%ld\n", sizeof(matriz4[0]) / sizeof(int));
	printf("%ld\n", sizeof(matriz5[0]) / sizeof(int));

	preencheMatriz(matriz1);
	
	caixeiroViajante(0);
	resultado();
	printf("\n\n");
	printf("tempo: %lf\n", (clock() - inicio) / (double)CLOCKS_PER_SEC);
}