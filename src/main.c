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
#include <stdbool.h>

#define VERTICES 5
#define INFINITO 429496729

int tempSolucao[VERTICES];
int melhorSolucao[VERTICES];
bool visitados[VERTICES];
int valorMelhorSolucao = INFINITO;
int valorSolucaoAtual = 0;

// int matriz[VERTICES][VERTICES]  = {
//     {0,         18,         30,         7,          INFINITO,   INFINITO,   INFINITO,   INFINITO,   INFINITO,   INFINITO},
//     {18,        0,          25,         INFINITO,   20,         30,         INFINITO,   INFINITO,   INFINITO,   INFINITO},
//     {30,        25,         0,          INFINITO,   30,         20,         INFINITO,   INFINITO,   60,         INFINITO},
//     {7,         INFINITO,   INFINITO,   0,          40,         INFINITO,   INFINITO,   INFINITO,   17,         INFINITO},
//     {INFINITO,  20,         30,         40,         0,          10,         5,          INFINITO,   INFINITO,   INFINITO},
//     {INFINITO,  30,         20,         INFINITO,   10,         0,          9,          INFINITO,   INFINITO,   60},
//     {INFINITO,  INFINITO,   INFINITO,   INFINITO,   5,          9,          0,          INFINITO,   50,         50},
//     {INFINITO,  INFINITO,   INFINITO,   INFINITO,   4,          INFINITO,   INFINITO,   0,          40,         38},
//     {INFINITO,  INFINITO,   50,         17,         INFINITO,   INFINITO,   42,         37,         0,          20},
//     {INFINITO,  INFINITO,   INFINITO,   INFINITO,   INFINITO,   60,         37,         38,         20,         0}
// };

	int matriz[VERTICES][VERTICES] = {
									{0,7,5,9,4},
									{7,0,2,8,1},
									{5,2,0,10,6},
									{9,8,10,0,3},
									{4,1,6,3,0}
								};

// int matriz[VERTICES][VERTICES]  = {
//                                 {0,   10, 15,  20},
//                                 {10,   0, 35,  25},
//                                 {15,  35,  0,  30},
//                                 {20,  25, 30,   0}};

// int matriz[VERTICES][VERTICES]  = {{         0,          2,   INFINITO, 3,          6 },
// 								  {          2,          0,          4, 3,   INFINITO },
// 								  {   INFINITO,          4,          0, 7,          3 },
// 								  {          3,          3,          7, 0,          3 },
// 								  {          6,   INFINITO,          3, 3,          0 }};

void caixeiroViajanteAux(int x){
	// Se o valor da solução atual já estiver maior que o valor da melhor solução já para, pois já não pode mais ser a melhor solução
	if( valorSolucaoAtual > valorMelhorSolucao )
		return;

	if( x == VERTICES ){ // Se x == VERTICES significa que o vetor da solução temporária está completo
		int distancia = matriz[tempSolucao[x-1]][tempSolucao[0]];
		// Se encontrou uma solução melhor/menor
		if( distancia < INFINITO && valorSolucaoAtual + distancia < valorMelhorSolucao ){
			valorMelhorSolucao = valorSolucaoAtual + distancia; // Substitui a melhor solução pela melhor encontrada agora
			// Copia todo o vetor de solução temporária para o vetor de melhor solução encontrada
			for (int i = 0; i < VERTICES; ++i){
				melhorSolucao[i] = tempSolucao[i];
			}
		}
		return;
	}

	int ultimo = tempSolucao[x-1]; // Ultimo recebe o número do último vértice que se encontra na solução temporária
	// For que percorre todas as colunas da matriz na linha do último vértice do vetor solução temporária
	for (int i = 0; i < VERTICES; i++){
		// Se a posição i do vetor ainda não foi visitada, e se o valor da matriz na posição é menor que INFINITO
		if( visitados[i] == false && matriz[ultimo][i] < INFINITO ){
			visitados[i] = true; // Marca como visitado
			tempSolucao[x] = i; // Carrega o vértice que está passando no vetor de solução temporária
			valorSolucaoAtual += matriz[ultimo][i]; // Incrementa o valor da matriz na variável que guarda o total do caminho percorrido
			caixeiroViajanteAux(x+1); // Chama recursivamente para o próximo vértice
			valorSolucaoAtual -= matriz[ultimo][i]; // Se ainda não terminou, diminuí o valor da váriavel que guarda o total da solução atual
			visitados[i] = false; // Seta como false a posição para poder ser utilizado por outro vértice
		}

	}

}

void caixeiroViajante(int inicial){
	visitados[inicial] = true; // Marca o primeiro vértice como visitado (0)
	tempSolucao[0] = inicial; // Coloca o vértice 0 na primeira posição do vetor de solução temporária
	caixeiroViajanteAux(1); // Chama o método auxiliar do caixeiro viajante
}

void iniciaVetores(){
	for (int i = 0; i < VERTICES; i++){
		visitados[i] = false;
		tempSolucao[i] = -1;
		melhorSolucao[i] = -1;
	}
}

int main(){

	iniciaVetores();
	caixeiroViajante(0);
	melhorSolucao[VERTICES] = melhorSolucao[0];

	printf("Caminho mínimo: %d\n", valorMelhorSolucao);
	for (int i = 0; i < VERTICES; i++){
		printf("%d, ", melhorSolucao[i]);
	}
	printf("\n\n");
}