#include <stdio.h>
#include <time.h>

#include "matrizEstatica.h"
#include "caixeiro.h"
#include "tsp.h"

int main(){
	int **matriz;
	double tempo_execucao=0;
	int op, tam, op_bucaRapida, op_bruteForce;
	int start=0, finish=tam-1;

	do {
		system("clear || cls");
		printf("====================\n");
		printf("   TIPO ALGORITMO\n");
		printf("====================\n\n");
		printf("1 - Brute force\n");
		printf("2 - Busca rapida\n");
		printf("0 - Sair\n\n");
		printf("Escolha uma opção: ");
		scanf("%d", &op);

		if(op == 0) {
			printf("O programa sera finalizado!\n");
			return EXIT_SUCCESS;
		}
		
		else if(op == 1) {
			op_bruteForce = bruteForceMenu();
			tam = get_tamVertice(op_bruteForce);
			
			if(tam != -1) {
				matriz = atribuiMatriz(matriz, op_bruteForce);
				clock_t begin = clock();
				ResultadoBruteForce(matriz, tam);
				clock_t end = clock();
				tempo_execucao = (double)(end - begin) / CLOCKS_PER_SEC;
				printf("Tempo de execução:\t%lf segundos", tempo_execucao);
				for(int i=0; i<tam; i++) free(matriz[i]);
			} else
				printf("Opcao invalida!\n");
		}
		
		else if(op == 2) {
			op_bucaRapida = buscaRapidaMenu();
			tam = get_tamVertice(op_bucaRapida);

			if(tam != -1) {
				matriz = atribuiMatriz(matriz, op_bucaRapida);
				printMatrix(matriz, tam);
				clock_t begin = clock();
				ResultadoRapido(matriz, tam);
				clock_t end = clock();
				tempo_execucao = (double)(end - begin) / CLOCKS_PER_SEC;
				printf("Tempo de execução:\t%lf segundos", tempo_execucao);
				for(int i=0; i<tam; i++) free(matriz[i]);
			} else
				printf("Opcao invalida!\n");
		
		} else {
			printf("Opcao invalida!\n");
		}
		
		printf("\n\nPressione enter para continuar...");getchar();while(getchar() != '\n');
		
	} while(op != 0);

	return EXIT_SUCCESS;
}
