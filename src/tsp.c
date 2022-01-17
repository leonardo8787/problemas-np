#include "tsp.h"

int min_pathweight;
long double total_combinacoes;
long int current_combinacoes;
long int num = 1000000;
int VERTICESBF = 0;

void ResultadoBruteForce(int **graph, int tam){
	//-----------------DECLARATION OF VARIABLES THAT USE tam
	int min_path[tam];
	int cities[tam];
	int vertex[tam];
	
	//-----------------INICIALIZE
	Inicialize(vertex, cities, min_path, tam);
	
	//----------------PERMUTATION
	int start=0, finish=tam-1;
	permutation(vertex, start, finish, graph, tam, cities, min_path);
	
	//----------------RESULT
	printMatrix(graph, tam);
	imprimirBruteForce(vertex, cities, min_path, tam);	
}

int bruteForceMenu() {
	int op;

	system("clear || cls");
	printf("====================\n");
	printf("  MENU BRUTE FORCE\n");
	printf("====================\n\n");
	
	printf("1 - Matriz 1   -> 4  vértices\n");
	printf("2 - Matriz 2   -> 10 vértices\n");
	printf("3 - Matriz 3   -> 5  vértices\n");
	printf("4 - Matriz 3_1 -> 5  vértices: caminho entre (A e D) retirado\n");
	printf("5 - Matriz 4   -> 5  vértices\n");
	printf("6 - Matriz 5   -> 18 vértices\n");
	printf("7 - Matriz 6   -> 10 vértices\n");
	printf("8 - Matriz 7   -> 13 vértices\n\n");

	printf("\nEscolha uma opção: ");
	scanf("%d", &op);

	return op;
}

long double factorial(int n) {
	if(n>=1)
		return n*factorial(n-1);
	else
		return 1;
}

long double percentageExecution() {
	return 100*current_combinacoes/total_combinacoes;
}

int getMinPathWeight() {
	return min_pathweight;
}

long int getCurrentCombinacoes() {
	return current_combinacoes;
}

void travelingSalesmanProblem(int **graph, int *vertex, int tam, int *cities, int *min_path) {
	// store current Path weight(cost)
	int current_pathweight = 0;
	int current_path[tam];
	int s = 0;
	int k = s;

	// compute current path weight
	for(int i = 0; i < tam; i++) {
		current_pathweight += graph[k][vertex[i]];
		current_path[i] = graph[k][vertex[i]];
		k = vertex[i];
	}
	current_pathweight += graph[k][s];
	
	// update minimum
	if(current_pathweight < min_pathweight) {
		min_pathweight = current_pathweight;//atualiza caminho minimo
		for(int i=0; i<tam; i++) {//atualiza caminho
			if(i==0) min_path[i] = graph[k][0];
			else min_path[i] = current_path[i]; 
		}
		for(int i=0; i<tam; i++)//atualiza cidades
			cities[i] = vertex[i];
	}
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(int *vertex, int start, int end, int **graph, int tam, int *cities, int *min_path) {
	int i;
	total_combinacoes = factorial(tam);
	
	if(start==end) {
		travelingSalesmanProblem(graph, vertex, tam, cities, min_path);
		current_combinacoes++;
		if(current_combinacoes % num == 0) {//imprime porcentagem a cada 10000 combinaçoes realizadas
			system("cls || clear");
			printf("------- INFO durante execução -------\n");
			printf("\nPorcentagem concluída:\t%2.Lf%% \n", percentageExecution());
			printf("Combinações realizadas:\t%ld \n", current_combinacoes);
		}
		return;
	}
	for(i=start;i<=end;i++) {
		swap((vertex+i), (vertex+start));
		permutation(vertex, start+1, end, graph, tam, cities, min_path);
		swap((vertex+i), (vertex+start));
	}
	return;
}

void Inicialize(int *vertex, int *cities, int *min_path, int tam) {
	for(int i = 0; i < tam; i++) {
		vertex[i] = i;
		cities[i] = i;
		min_path[i] = i;
	}
	min_pathweight = INT_MAX;
	current_combinacoes = 0;
}

void imprimirBruteForce(int *vertex, int *cities, int *min_path, int tam) {	
	char cityName[][25] = {"Cidade 1", "Cidade 2", "Cidade 3", "Cidade 4", "Cidade 5", "Cidade 6", "Cidade 7", "Cidade 8", "Cidade 9", "Cidade 10", "Cidade 11", "Cidade 12", "Cidade 13", "Cidade 14", "Cidade 15", "Cidade 16", "Cidade 17", "Cidade 18"};
	
	printf("\n\nCaminho mais curto passando por todos os vértices:\t%d \n", getMinPathWeight());
	
	printf("\nCaminho:\t");
	for(int i=0; i<tam; i++){ printf("%d ", min_path[i]); }//caminho
	
	printf("\n\n%s -> ", cityName[cities[tam-1]]);//ultima cidade no array é o ponto de partida
	for(int i=0; i<tam; i++) {//cidades
		if(i == tam-1)
			printf("%s", cityName[cities[i]]);
		else {
			printf("%s -> ", cityName[cities[i]]);
		}
	}
	
	printf("\n\nPorcentagem concluída:\t%2.Lf%%", percentageExecution());
	printf("\nCombinações realizadas:\t%ld", getCurrentCombinacoes());
	printf("\n");
}
