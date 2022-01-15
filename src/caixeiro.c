#include "caixeiro.h"

int *tempSolucao;
int *melhorSolucao;
bool *visitados;
int valorMelhorSolucao = INFINITO;
int valorSolucaoAtual = 0;

int VERTICES = 0;

int **matriz;

void preencheMatriz(Lista *l) {
	Block *aux;
	int i=0, j=0;
	bool controle = true;

	aux = l->first->prox;
	matriz = (int**)malloc(VERTICES * sizeof(int*));
	while(i != VERTICES && j != VERTICES) {
		if(controle) {
			matriz[i] = (int*)malloc(VERTICES * sizeof(int));
			controle = !controle;
		}
		matriz[i][j++] = aux->dado.valor;

		if(j == VERTICES) {
			j = 0;
			i++;
			controle = !controle;
		}
		aux = aux->prox;
	}

	for (int i = 0; i < VERTICES; i++) {
		for (int j = 0; j < VERTICES; j++) {
			if (matriz[i][j] == INFINITO)
				printf("  - ");
			else
				printf("%3d ", matriz[i][j]);
		}
		printf("\n");
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
	printf("\n");
	caixeiroViajanteAux(1); // Chama o método auxiliar do caixeiro viajante
}

void iniciaVetores(int tamanho) {
	VERTICES = tamanho;
	valorMelhorSolucao = INFINITO;
	valorSolucaoAtual = 0;

	visitados     = (bool*)realloc(visitados, VERTICES * sizeof(bool));
	tempSolucao   = (int*) realloc(tempSolucao, VERTICES * sizeof(int));
	melhorSolucao = (int*) realloc(melhorSolucao, VERTICES * sizeof(int));

	for (int i = 0; i < VERTICES; i++) {
		visitados[i] = false;
		tempSolucao[i] = -1;
		melhorSolucao[i] = -1;
	}
}

void mallocar() {
	visitados     = (bool*)malloc(VERTICES * sizeof(bool));
	tempSolucao   = (int*) malloc(VERTICES * sizeof(int));
	melhorSolucao = (int*) malloc(VERTICES * sizeof(int));
}

void imprimir() {

	printf("Caminho mínimo: %d\n", valorMelhorSolucao);
	
	for (int i = 0; i < VERTICES; i++) {
		printf("%d, ", melhorSolucao[i] + 1);
	}

	printf("%d\n", melhorSolucao[0] + 1);
}