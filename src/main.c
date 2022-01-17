#include <stdio.h>
#include <time.h>

#include "matrizEstatica.h"
#include "caixeiro.h"
#include "tsp.h"

int menu();
int bruteForceMenu();
int buscaRapidaMenu();

void bruteForce(int op);
void resultado(Lista *l, int tam);

int main(){
	int **matriz;
	double inicio = clock();
	
	Lista l;
	Item item;
	int op, tam;
	int op_bucaRapida, op_bruteForce;

	mallocar();

	do {
		op = menu();
		printf("\n");

		if(op == 0) {
			printf("O programa sera finalizado!\n");
			return EXIT_SUCCESS;
		}
		else if(op == 1) {
			bruteForce(bruteForceMenu());
		} 
		else if(op == 2) {
			FLVazia(&l);
			op_bucaRapida = buscaRapidaMenu();
			tam = get_tamVertice(op_bucaRapida);

			if(tam != -1) {
				atribuiMatriz(matriz, op_bucaRapida, &l);
				resultado(&l, tam);
			} else
				printf("Opcao invalida!\n");
		} else {
			printf("Opcao invalida!\n");
		}
		system("read -p \"\nPressione enter para continuar...\" continue");
	} while(op != 0);

	return EXIT_SUCCESS;
}

int menu() {
	int op;

	system("clear || cls");
	printf("====================\n");
	printf("   TIPO ALGORITIMO\n");
	printf("====================\n\n");
	
	printf("1 - Brute force\n");
	printf("2 - Busca rapida\n");
	printf("0 - Sair\n\n");

	printf("Escolha uma opção: ");
	scanf("%d", &op);

	return op;
}

void bruteForce(int op) {
	double time_spent=0;
	int num_vertices, row, col;
	char name[25];
	
	switch(op) {
		case 1:
			num_vertices = 5;
			strcpy(name, "vertice5-ex1");
		break;
		case 2:
			num_vertices = 5;
			strcpy(name, "vertice5-ex2");
		break;
		case 3:
			num_vertices = 10;
			strcpy(name, "vertice10");
		break;
		case 4:
			num_vertices = 13;
			strcpy(name, "vertice13");
		break;
		case 5:
			num_vertices = 18;
			strcpy(name, "vertice18");
		break;
		default:
			printf("\nOpcao invalida!\n");
			return;
	}
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
	int **graph = readGraph(matrix, num_vertices, name);
	
	//----------------PERMUTATION
	int start=0, finish=num_vertices-1;
	clock_t begin = clock();//execution time begin
	
	permutation(vertex, start, finish, graph, num_vertices, cities, min_path);
	
	clock_t end = clock();//execution time end
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	//----------------RESULT
	printMatrix(matrix, num_vertices);
	printVetores(vertex, cities, min_path, num_vertices);
	result(time_spent);
	
	for(int i=0; i<num_vertices; i++)
		free(matrix[i]);
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

int bruteForceMenu() {
	int op;

	system("clear || cls");
	printf("====================\n");
	printf("  MENU BRUTE FORCE\n");
	printf("====================\n\n");
	
	printf("1 - Arquivo 1  -> 5 vértices\n");
	printf("2 - Arquivo 2  -> 5 vértices\n");
	printf("3 - Arquivo 3  -> 10 vértices\n");
	printf("4 - Arquivo 4  -> 13 vértices\n");
	printf("5 - Arquivo 5  -> 18 vértices\n");

	printf("\nEscolha uma opção: ");
	scanf("%d", &op);

	return op;
}

void resultado(Lista *l, int tam) {
	iniciaVetores(tam);
	preencheMatriz(l);
	caixeiroViajante(0);
	imprimir();
}