#include <stdio.h>
#include <time.h>
#include "caixeiro.h"

int menu();
void resultado(Lista *l, int tam);

int main(){
	double inicio = clock();
	
	Lista l;
	Item item;
	int op, tam;

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
		{0,7,5,9,4},
		{7,0,2,8,1},
		{5,2,0,10,6},
		{9,8,10,0,3},
		{4,1,6,3,0}
	};

	int matriz3_1[5][5] = {
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

	int matriz7[13][13] = {
		{0, 2451, 713, 1018, 1631, 1374, 2408, 213, 2571, 875, 1420, 2145, 1972},
		{2451, 0, 1745, 1524, 831, 1240, 959, 2596, 403, 1589, 1374, 357, 579},
		{713, 1745, 0, 355, 920, 803, 1737, 851, 1858, 262, 940, 1453, 1260},
		{1018, 1524, 355, 0, 700, 862, 1395, 1123, 1584, 466, 1056, 1280, 987},
		{1631, 831, 920, 700, 0, 663, 1021, 1769, 949, 796, 879, 586, 371},
		{1374, 1240, 803, 862, 663, 0, 1681, 1551, 1765, 547, 225, 887, 999},
		{2408, 959, 1737, 1395, 1021, 1681, 0, 2493, 678, 1724, 1891, 1114, 701},
		{213, 2596, 851, 1123, 1769, 1551, 2493, 0, 2699, 1038, 1605, 2300, 2099},
		{2571, 403, 1858, 1584, 949, 1765, 678, 2699, 0, 1744, 1645, 653, 600},
		{875, 1589, 262, 466, 796, 547, 1724, 1038, 1744, 0, 679, 1272, 1162},
		{1420, 1374, 940, 1056, 879, 225, 1891, 1605, 1645, 679, 0, 1017, 1200},
		{2145, 357, 1453, 1280, 586, 887, 1114, 2300, 653, 1272, 1017, 0, 504},
		{1972, 579, 1260, 987, 371, 999, 701, 2099, 600, 1162, 1200, 504, 0}
	};


	mallocar();
	do {
		system("clear || cls");
		op = menu();
		FLVazia(&l);
		printf("\n");

		switch(op) {
			case 1:
				tam = sizeof(matriz1[0]) / sizeof(int);

				for(int i = 0; i < tam; i++) {
					for(int j = 0; j < tam; j++) {
						item.valor = matriz1[i][j];
						LInsere(&l, item);
					}
				}
				resultado(&l, tam);
			break;
			case 2:
				tam = sizeof(matriz2[0]) / sizeof(int);

				for(int i = 0; i < tam; i++) {
					for(int j = 0; j < tam; j++) {
						item.valor = matriz2[i][j];
						LInsere(&l, item);
					}
				}
				resultado(&l, tam);
			break;
			case 3:
				tam = sizeof(matriz3[0]) / sizeof(int);

				for(int i = 0; i < tam; i++) {
					for(int j = 0; j < tam; j++) {
						item.valor = matriz3[i][j];
						LInsere(&l, item);
					}
				}
				resultado(&l, tam);
			break;
			case 4:
				tam = sizeof(matriz3_1[0]) / sizeof(int);

				for(int i = 0; i < tam; i++) {
					for(int j = 0; j < tam; j++) {
						item.valor = matriz3_1[i][j];
						LInsere(&l, item);
					}
				}
				resultado(&l, tam);
			break;
			case 5:
				tam = sizeof(matriz4[0]) / sizeof(int);

				for(int i = 0; i < tam; i++) {
					for(int j = 0; j < tam; j++) {
						item.valor = matriz4[i][j];
						LInsere(&l, item);
					}
				}
				resultado(&l, tam);
			break;
			case 6:
				tam = sizeof(matriz5[0]) / sizeof(int);
				
				for(int i = 0; i < tam; i++) {
					for(int j = 0; j < tam; j++) {
						item.valor = matriz5[i][j];
						LInsere(&l, item);
					}
				}
				resultado(&l, tam);
			break;
			case 7:
				tam = sizeof(matriz6[0]) / sizeof(int);

				for(int i = 0; i < tam; i++) {
					for(int j = 0; j < tam; j++) {
						item.valor = matriz6[i][j];
						LInsere(&l, item);
					}
				}
				resultado(&l, tam);
			break;
			case 8:
				tam = sizeof(matriz7[0]) / sizeof(int);

				for(int i = 0; i < tam; i++) {
					for(int j = 0; j < tam; j++) {
						item.valor = matriz7[i][j];
						LInsere(&l, item);
					}
				}
				resultado(&l, tam);
			break;
			
			case 0:
				printf("O programa sera finalizado!\n");
				return EXIT_SUCCESS;
			default:
				printf("Opcao invalida!\n");
		}
		system("read -p \"\nPressione enter para continuar...\" continue");
	} while(op != 0);

	return EXIT_SUCCESS;
}

int menu() {
	int op;

	printf("====================\n");
	printf("   MENU DE OPCOES\n");
	printf("====================\n\n");
	
	printf("1 - Matriz 1   -> 4  vértices\n");
	printf("2 - Matriz 2   -> 10 vértices\n");
	printf("3 - Matriz 3   -> 5  vértices\n");
	printf("4 - Matriz 3_1 -> 5  vértices: caminho entre (A e D) retirado\n");
	printf("5 - Matriz 4   -> 5  vértices\n");
	printf("6 - Matriz 5   -> 18 vértices\n");
	printf("7 - Matriz 6   -> 10 vértices\n");
	printf("8 - Matriz 7   -> 13 vértices\n");
	printf("0 - Sair\n\n");

	printf("Escolha uma opção: ");
	scanf("%d", &op);

	return op;
}

void resultado(Lista *l, int tam) {
	iniciaVetores(tam);
	preencheMatriz(l);
	caixeiroViajante(0);
	imprimir();
}