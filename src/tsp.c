#include "tsp.h"

int min_pathweight = INT_MAX;
long double total_combinacoes;
long int current_combinacoes=0;
long int num = 1000000;

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

void travelingSalesmanProblem(int **graph, int *vertex, int num_vertices, int *cities, int *min_path) {
	// store current Path weight(cost)
	int current_pathweight = 0;
	int current_path[num_vertices];
	int s = 0;
	int k = s;

	// compute current path weight
	for(int i = 0; i < num_vertices; i++) {
		current_pathweight += graph[k][vertex[i]];
		current_path[i] = graph[k][vertex[i]];
		k = vertex[i];
	}
	current_pathweight += graph[k][s];
	
	// update minimum
	if(current_pathweight < min_pathweight) {
		min_pathweight = current_pathweight;//atualiza caminho minimo
		for(int i=0; i<num_vertices; i++) {//atualiza caminho
			if(i==0) min_path[i] = graph[k][0];
			else min_path[i] = current_path[i]; 
		}
		for(int i=0; i<num_vertices; i++)//atualiza cidades
			cities[i] = vertex[i];
	}
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(int *vertex, int start, int end, int **graph, int num_vertices, int *cities, int *min_path) {
	int i;
	total_combinacoes = factorial(num_vertices);
	
	if(start==end) {
		travelingSalesmanProblem(graph, vertex, num_vertices, cities, min_path);
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
		permutation(vertex, start+1, end, graph, num_vertices, cities, min_path);
		swap((vertex+i), (vertex+start));
	}
	return;
}

int **readGraph(int **arr, int num_vertices, char *name) {
	FILE *file;
	char buffer[BUFFER_SIZE], bufferBackup[BUFFER_SIZE], fileName[15];
	char path[50] = "./grafos/";
	char *token;
	int i=0;
	
	// printf("Entre o nome do arquivo:\t");
	// scanf("%s", fileName);
	strcat(path, name);
	file = fopen(path, "r");

	while(fgets(buffer, BUFFER_SIZE, file) != NULL) {
		strcpy(bufferBackup, buffer);
		token = strtok(buffer, ",");

		for(int j=0; j<num_vertices; j++){
			arr[i][j] = atof(token);
			token = strtok(NULL, ",");	
		}
		i++;
	}
	fclose(file);
	// printf("\n\n");
	// for(int i=0; i<num_vertices; i++) {
	// 	for(int j=0; j<num_vertices; j++) {
	// 		printf("%d ", arr[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	// printf("\n\nPressione qualquer tecla para continuar ...");getchar();while(getchar() != '\n');
	// system("cls || clear");
	return arr;
}

void Inicialize(int *vertex, int *cities, int *min_path, int num_vertices) {
	
	for(int i = 0; i < num_vertices; i++) {
		vertex[i] = i;
		cities[i] = i;
		min_path[i] = i;
	}
	min_pathweight = INT_MAX;
	current_combinacoes = 0;
}

void printMatrix(int **matrix, int num_vertices) {
	printf("\nMatrix:\n\n");
	for(int i=0; i<num_vertices; i++) {// matriz
		for(int j=0; j<num_vertices; j++) {
			printf("%6d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void printVetores(int *vertex, int *cities, int *min_path, int num_vertices) {
	char cityName[][25] = {"Cidade 1", "Cidade 2", "Cidade 3", "Cidade 4", "Cidade 5", "Cidade 6", "Cidade 7", "Cidade 8", "Cidade 9", "Cidade 10", "Cidade 11", "Cidade 12", "Cidade 13", "Cidade 14", "Cidade 15", "Cidade 16", "Cidade 17", "Cidade 18"};
	
	printf("\nCaminho:\t");
	for(int i=0; i<num_vertices; i++){ printf("%d ", min_path[i]); }//caminho
	
	printf("\n\n%s -> ", cityName[cities[num_vertices-1]]);//ultima cidade no array é o ponto de partida
	
	for(int i=0; i<num_vertices; i++) {//cidades
		if(i == num_vertices-1)
			printf("%s", cityName[cities[i]]);
		else {
			printf("%s -> ", cityName[cities[i]]);
		}
	}
}

void result(double time_spent) {
	printf("\nCaminho mais curto passando por todos os vértices:\t%d \n", getMinPathWeight());

	printf("\nPorcentagem concluída:\t%2.Lf%%", percentageExecution());
	printf("\nCombinações realizadas:\t%ld", getCurrentCombinacoes());
	printf("\nTempo de execução:\t%lf seconds", time_spent);
	printf("\n");
}