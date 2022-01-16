#include "tsp.h"

int main() {
	double time_spent=0;
	int num_vertices, row, col;
	int opcao=1;
	
	char cityName[][25] = {"Cidade 1", "Cidade 2", "Cidade 3", "Cidade 4", "Cidade 5", "Cidade 6", "Cidade 7", "Cidade 8", "Cidade 9", "Cidade 10", "Cidade 11", "Cidade 12", "Cidade 13", "Cidade 14", "Cidade 15", "Cidade 16", "Cidade 17", "Cidade 18"};
	
	while(opcao) {
		system("cls || clear");
		printf("======================\n        MENU\n======================\n\n1. Carregar grafo\n2. Sair\n\nEscolha uma opção:\t");
		scanf("%d", &opcao);
		
		if(opcao==1) {
			system("cls || clear");
			printf("Entre a quantidade de vértices da matrix:\t");
			scanf("%d", &num_vertices);
			
			//-----------------DECLARATION OF VARIABLES THAT USE num_vertices
			int min_path[num_vertices];
			int cities[num_vertices];
			int vertex[num_vertices];
			
			//-----------------INICIALIZE VECTORS
			Inicialize(vertex, cities, min_path, num_vertices);
			
			//------------------GRAPH
			row=num_vertices; col=num_vertices;
			int *matrix[num_vertices];//alocando matrix
			for(int i = 0; i < row; i++)
				matrix[i] = (int*)malloc(col * sizeof(int));
			
			//-----------------READ GRAPH FROM FILE
			int **graph = readGraph(matrix, num_vertices);
			
			//----------------PERMUTATION
			int start=0, finish=num_vertices-1;
			clock_t begin = clock();//execution time begin
			
			permutation(vertex, start, finish, graph, num_vertices, cities, min_path);
			
			clock_t end = clock();//execution time end
			time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			
			//----------------RESULT
			printf("\n\n--------------------------------------------------------------------------------------\n\n");
			printf("Caminho mais curto passando por todos os vértices:\t%d \n", getMinPathWeight());
			
			printf("\n\nCaminho:\t");
			for(int i=0; i<num_vertices; i++){ printf("%d ", min_path[i]); }//caminho
			
			printf("\n\n%s -> ", cityName[cities[num_vertices-1]]);//ultima cidade no array é o ponto de partida
			for(int i=0; i<num_vertices; i++) {//cidades
				if(i==num_vertices-1) printf("%s", cityName[cities[i]]);
				else printf("%s -> ", cityName[cities[i]]);
			}
			
			printf("\n\nTempo de execução:\t%f seconds", time_spent);
			printf("\nTotal de combinações realizadas:\t%ld", getCurrentCombinacoes());
			printf("\nPorcentagem concluída:\t%2.Lf%%", percentageExecution());
			
			printf("\n\n\nPressione qualquer tecla para continuar ...");getchar();
			
			for(int i=0; i<num_vertices; i++)
				free(matrix[i]);
		} else
			opcao=0;
	}
	
	return 0;
}
