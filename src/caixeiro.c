#include "caixeiro.h"

int tempSolucao[VERTICES];
int melhorSolucao[VERTICES];
bool visitados[VERTICES];
int valorMelhorSolucao = INFINITO;
int valorSolucaoAtual = 0;


// int matriz[VERTICES][VERTICES] = {
// 	{0,20,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,39,INFINITO,INFINITO,INFINITO,29,37,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
// 	{20,0,25,INFINITO,INFINITO,INFINITO,INFINITO,28,INFINITO,INFINITO,INFINITO,39,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
// 	{INFINITO,25,0,25,INFINITO,INFINITO,INFINITO,30,INFINITO,INFINITO,INFINITO,INFINITO,54,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
// 	{INFINITO,INFINITO,25,0,39,32,42,INFINITO,23,33,INFINITO,INFINITO,INFINITO,35,INFINITO,INFINITO,INFINITO,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,39,0,12,26,INFINITO,INFINITO,19,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,32,12,0,17,INFINITO,INFINITO,35,30,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,42,26,17,0,INFINITO,INFINITO,INFINITO,38,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
// 	{39,28,30,INFINITO,INFINITO,INFINITO,INFINITO,0,INFINITO,INFINITO,INFINITO,25,22,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,23,INFINITO,INFINITO,INFINITO,INFINITO,0,26,INFINITO,INFINITO,34,56,INFINITO,43,INFINITO,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,33,19,35,INFINITO,INFINITO,26,0,24,INFINITO,INFINITO,30,19,INFINITO,INFINITO,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,30,38,INFINITO,INFINITO,24,0,INFINITO,INFINITO,INFINITO,26,INFINITO,INFINITO,36},
// 	{29,39,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,25,INFINITO,INFINITO,INFINITO,0,27,INFINITO,INFINITO,43,INFINITO,INFINITO},
// 	{37,INFINITO,54,INFINITO,INFINITO,INFINITO,INFINITO,22,34,INFINITO,INFINITO,27,0,24,INFINITO,19,INFINITO,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,56,INFINITO,INFINITO,INFINITO,INFINITO,35,30,INFINITO,INFINITO,24,0,20,19,17,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,19,26,INFINITO,INFINITO,20,0,INFINITO,18,21},
// 	{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,43,INFINITO,INFINITO,43,19,19,INFINITO,0,19,INFINITO},
// 	{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,17,18,26,0,15},
// 	{INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,INFINITO,36,INFINITO,INFINITO,INFINITO,21,INFINITO,15,0}
// };

int matriz[VERTICES][VERTICES];

void preencheMatriz(int valor[VERTICES][VERTICES]) {
    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            matriz[i][j] = valor[i][j];
        }
    }
}

void caixeiroViajanteAux(int x) {
	// Se o valor da solução atual já estiver maior que o valor da melhor solução já para, pois já não pode mais ser a melhor solução
	if( valorSolucaoAtual > valorMelhorSolucao )
		return;

	if( x == VERTICES ) { // Se x == VERTICES significa que o vetor da solução temporária está completo
		int distancia = matriz[tempSolucao[x-1]][tempSolucao[0]];
		// Se encontrou uma solução melhor/menor
		if( distancia < INFINITO && valorSolucaoAtual + distancia < valorMelhorSolucao ) {
			valorMelhorSolucao = valorSolucaoAtual + distancia; // Substitui a melhor solução pela melhor encontrada agora
			// Copia todo o vetor de solução temporária para o vetor de melhor solução encontrada
			for (int i = 0; i < VERTICES; ++i) {
				melhorSolucao[i] = tempSolucao[i];
			}
		}
		return;
	}

	int ultimo = tempSolucao[x-1]; // Ultimo recebe o número do último vértice que se encontra na solução temporária
	// For que percorre todas as colunas da matriz na linha do último vértice do vetor solução temporária
	for (int i = 0; i < VERTICES; i++) {
		// Se a posição i do vetor ainda não foi visitada, e se o valor da matriz na posição é menor que INFINITO
		if( visitados[i] == false && matriz[ultimo][i] < INFINITO ) {
			visitados[i] = true; // Marca como visitado
			tempSolucao[x] = i; // Carrega o vértice que está passando no vetor de solução temporária
			valorSolucaoAtual += matriz[ultimo][i]; // Incrementa o valor da matriz na variável que guarda o total do caminho percorrido
			caixeiroViajanteAux(x+1); // Chama recursivamente para o próximo vértice
			valorSolucaoAtual -= matriz[ultimo][i]; // Se ainda não terminou, diminuí o valor da váriavel que guarda o total da solução atual
			visitados[i] = false; // Seta como false a posição para poder ser utilizado por outro vértice
		}

	}

}

void caixeiroViajante(int inicial) {
	visitados[inicial] = true; // Marca o primeiro vértice como visitado (0)
	tempSolucao[0] = inicial; // Coloca o vértice 0 na primeira posição do vetor de solução temporária
	caixeiroViajanteAux(1); // Chama o método auxiliar do caixeiro viajante
}

void iniciaVetores() {
	for (int i = 0; i < VERTICES; i++) {
		visitados[i] = false;
		tempSolucao[i] = -1;
		melhorSolucao[i] = -1;
	}
}

void resultado() {
    melhorSolucao[VERTICES] = melhorSolucao[0];

	printf("Caminho mínimo: %d\n", valorMelhorSolucao);
	for (int i = 0; i < VERTICES; i++){
		printf("%d, ", melhorSolucao[i]+1);
	}
}