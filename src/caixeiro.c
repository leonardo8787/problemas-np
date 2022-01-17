#include "caixeiro.h"

int *tempSolucao;
int *melhorSolucao;
bool *visitados;
int valorMelhorSolucao = INFINITO;
int valorSolucaoAtual = 0;
int VERTICES = 0;

void ResultadoRapido(int **matriz, int tam) {
	iniciaVetores(tam);
	caixeiroViajante(matriz, 0);
	imprimirRapido();
}

int buscaRapidaMenu() {
	int op;

	system("clear || cls");
	printf("====================\n");
	printf(" MENU BUSCA SIMPLES\n");
	printf("====================\n\n");
	
	printf("1 - Matriz 1   -> 4  vértices\n");
	printf("2 - Matriz 2   -> 10 vértices\n");
	printf("3 - Matriz 3   -> 5  vértices\n");
	printf("4 - Matriz 3_1 -> 5  vértices: caminho entre (A e D) retirado\n");
	printf("5 - Matriz 4   -> 5  vértices\n");
	printf("6 - Matriz 5   -> 18 vértices\n");
	printf("7 - Matriz 6   -> 10 vértices\n");
	printf("8 - Matriz 7   -> 13 vértices\n\n");

	printf("Escolha uma opção: ");
	scanf("%d", &op);

	return op;
}

void caixeiroViajanteAux(int **matriz, int x) {
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
			caixeiroViajanteAux(matriz, x+1); // Chama recursivamente para o próximo vértice
			valorSolucaoAtual -= matriz[ultimo][i]; // Se ainda não terminou, diminuí o valor da váriavel que guarda o total da solução atual
			visitados[i] = false; // Seta como false a posição para poder ser utilizado por outro vértice
		}

	}

}

void caixeiroViajante(int **matriz, int inicial) {
	visitados[inicial] = true; // Marca o primeiro vértice como visitado (0)
	tempSolucao[0] = inicial; // Coloca o vértice 0 na primeira posição do vetor de solução temporária
	printf("\n");
	caixeiroViajanteAux(matriz, 1); // Chama o método auxiliar do caixeiro viajante
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

void imprimirRapido() {
	printf("\n\nCaminho mais curto passando por todos os vértices:\t%d \n", valorMelhorSolucao);
	
	printf("\nCaminho:\t");
	for (int i = 0; i < VERTICES; i++) {
		printf("%d ", melhorSolucao[i] + 1);
	}

	printf("%d\n", melhorSolucao[0] + 1);
}
