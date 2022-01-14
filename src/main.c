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

#define VERTICES 10
#define INFINITO 429496729

int tempSolucao[VERTICES];
int melhorSolucao[VERTICES];
bool visitados[VERTICES];
int valorMelhorSolucao = INFINITO;
int valorSolucaoAtual = 0;

int matriz[VERTICES][VERTICES]  = {
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
		printf("%d, ", melhorSolucao[i] + 1);
	}
	printf("%d", melhorSolucao[0] + 1);
	printf("\n\n");
}

// #include <stdio.h>
// int matrix[25][25], visited_cities[25], limit, cost = 0;

// int tsp(int c) {
//     int count, nearest_city = 999;
//     int minimum = 999, temp;

//     int aux_count = 0, menor = 999;
    
//     // limit = 4

//     // # 0
//     // c = 0

//     // # 1
//     // c = 3

//     // # 2
//     // c = 2

//     printf("\n#%d\n", c);
//     for(count = 0; count < limit; count++) {
//         // # 0 ===============================

//         //  matrix[c][count] -> matrix[0][0] = 0
//         //  matrix[count][0] -> matrix[0][0] = 0
//         //  visited_cities[count] -> visited_cities[0] = 1
//         //  minimum = 999
//         //  temp = ?
//         //  nearest_city = 0
        
//         //  matrix[c][count] -> matrix[0][1] = 10
//         //  matrix[count][0] -> matrix[1][0] = 10
//         //  visited_cities[count] -> visited_cities[1] = 0
//         //  minimum = 10 + 10 = 20
//         //  temp = 10
//         //  nearest_city = 1
        
//         //  matrix[c][count] -> matrix[0][2] = 15
//         //  matrix[count][0] -> matrix[2][0] = 15
//         //  visited_cities[count] -> visited_cities[2] = 0
//         //  minimum = 15 + 15 = 30
//         //  temp = 15
//         //  nearest_city = 2
        
//         //  matrix[c][count] -> matrix[0][3] = 20
//         //  matrix[count][0] -> matrix[3][0] = 20
//         //  visited_cities[count] -> visited_cities[3] = 0
//         //  minimum = 20 + 20 = 40
//         //  temp = 20
//         //  nearest_city = 3

//         // # 1 ===============================

//         //  matrix[c][count] -> matrix[1][0] = 10
//         //  matrix[count][0] -> matrix[0][0] = 0
//         //  visited_cities[count] -> visited_cities[0] = 1
//         //  minimum = 999
//         //  temp = ?
//         //  nearest_city = 999
        
//         //  matrix[c][count] -> matrix[1][1] = 0
//         //  matrix[count][0] -> matrix[1][0] = 10
//         //  visited_cities[count] -> visited_cities[1] = 0
//         //  minimum = 999
//         //  temp = ?
//         //  nearest_city = 999
        
//         //  matrix[c][count] -> matrix[1][2] = 35
//         //  matrix[count][0] -> matrix[2][0] = 15
//         //  visited_cities[count] -> visited_cities[2] = 0
//         //  minimum = 15 + 35 = 50
//         //  temp = 35
//         //  nearest_city = 2
        
//         //  matrix[c][count] -> matrix[1][3] = 25
//         //  matrix[count][0] -> matrix[3][0] = 20
//         //  visited_cities[count] -> visited_cities[3] = 1
//         //  minimum = 50
//         //  temp = 35
//         //  nearest_city = 2

//         // # 2 ===============================

//         //  matrix[c][count] -> matrix[1][0] = 
//         //  matrix[count][0] -> matrix[0][0] = 0
//         //  visited_cities[count] -> visited_cities[0] = 
//         //  minimum = 999
//         //  temp = 
//         //  nearest_city = 999
        
//         //  matrix[c][count] -> matrix[1][1] = 
//         //  matrix[count][0] -> matrix[1][0] = 10
//         //  visited_cities[count] -> visited_cities[1] = 
//         //  minimum = 
//         //  temp = 
//         //  nearest_city = 
        
//         //  matrix[c][count] -> matrix[1][2] = 
//         //  matrix[count][0] -> matrix[2][0] = 15
//         //  visited_cities[count] -> visited_cities[2] = 
//         //  minimum = 
//         //  temp = 
//         //  nearest_city = 
        
//         //  matrix[c][count] -> matrix[1][3] = 
//         //  matrix[count][0] -> matrix[3][0] = 20
//         //  visited_cities[count] -> visited_cities[3] = 
//         //  minimum = 
//         //  temp = 
//         //  nearest_city = 
         
//         if((matrix[c][count] != 0) && (visited_cities[count] == 0)) {
//             // if(matrix[c][count] < minimum) {
//             //     minimum = matrix[count][0] + matrix[c][count];
//             // }
//             if(matrix[c][count] < menor) {
//                 menor = matrix[c][count];
//                 aux_count = count;
//             }
//             temp = matrix[c][count];
//             nearest_city = count;
//             // break;
//         }
//         if(count != 0 && (matrix[c][count] != 0)) {
//             printf("valor: %d: (%d-%d) -> %d-%d\n", matrix[c][count], c, count, menor, aux_count+1);
//             nearest_city = aux_count + 1;
//         }
            
//     }
//     //  # 0
//     //  minimum = 40
//     //  temp = 20
//     //  cost = 0
//     //  cost = 0 + 20 = 20
//     //  nearest_city = 3

//     //  # 1
//     //  minimum = 50
//     //  temp = 35
//     //  cost = 20
//     //  cost = 35 + 20 = 45
//     //  nearest_city = 2

//     if(minimum != 999) {
//         cost = cost + temp;
//         // printf("\ntemp -> %d-%d\n", temp, cost);
//     }
//     return nearest_city;
// }

// void minimum_cost(int city) {
//     int nearest_city;
//     visited_cities[city] = 1;

//     // # 0
//     // city = 0
//     // visited_cities[0] = 1

//     // # 1
//     // city = 3
//     // visited_cities[3] = 1

//     // # 2
//     // city = 2
//     // visited_cities[2] = 1
    
//     printf("%d ", city + 1);

//     // # 0 -> 1
//     // # 1 -> 4
//     // # 2 -> 3
    
//     nearest_city = tsp(city);

//     // # 0
//     // nearest_city = 3
//     // cost = 20

//     // # 1
//     // nearest_city = 2
//     // cost = 45

//     if(nearest_city == 999) {
//         nearest_city = 0;
//         printf("%d", nearest_city + 1);
//         cost = cost + matrix[city][nearest_city];
//         return;
//     }
//     minimum_cost(nearest_city);
// }

// int main() { 
//     int i, j;
    
//     limit = 4;

//     int matriz_aux[4][4] = {
//         { 0, 10, 15, 20 },
//         { 10, 0, 35, 25 },
//         { 15, 35, 0, 30 },
//         { 20, 25, 30, 0 }
//     };
    
//     for(i = 0; i < limit; i++) {
//         for(j = 0; j < limit; j++)
//             matrix[i][j] = matriz_aux[i][j];
//         visited_cities[i] = 0;
//     }
    
//     for(i = 0; i < limit; i++) {
//         printf("\n");
       
//         for(j = 0; j < limit; j++) {
//             printf("%d ", matrix[i][j]);
//         }
//     }
//     printf("\n\nPath:\t");
//     minimum_cost(0);
//     printf("\n\nMinimum Cost: \t");
//     printf("%d\n", cost);

//     return 0;
// }


// // int i, j;
// //     // printf("Enter Total Number of Cities:\t");
// //     // scanf("%d", &limit);
// //     limit = 4;
// //     // printf("\nEnter Cost Matrix\n");

// //     // int matriz_aux[10][10] = {
// //     //     {0,1,1,1,0,0,0,0,0,0},
// //     //     {1,0,1,0,1,1,0,0,0,0},
// //     //     {1,1,0,0,1,1,0,0,1,0},
// //     //     {1,0,0,0,1,0,0,1,1,0},
// //     //     {0,1,1,1,0,1,1,0,0,0},
// //     //     {0,1,1,0,1,0,1,0,0,1},
// //     //     {0,0,0,0,1,1,0,0,1,1},
// //     //     {0,0,0,0,1,0,0,0,1,1},
// //     //     {0,0,1,1,0,0,1,1,0,1},
// //     //     {0,0,0,0,0,1,1,1,1,0}
// //     // };

// //     int matriz_aux[4][4] = {
// //         { 0, 10, 15, 20 },
// //         { 10, 0, 35, 25 },
// //         { 15, 35, 0, 30 },
// //         { 20, 25, 30, 0 }
// //     };

// //     // int matriz_aux[5][5] = {
// //     //     {0,1,0,0,1},
// //     //     {1,0,1,1,1},
// //     //     {0,1,0,1,0},
// //     //     {0,1,1,0,1},
// //     //     {1,1,0,1,0}
// //     // };
// //     // int matriz_aux[18][18] = {
// //     //     {0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0},
// //     //     {1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
// //     //     {0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
// //     //     {0,0,1,0,1,1,1,0,1,1,0,0,0,1,0,0,0,0},
// //     //     {0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0},
// //     //     {0,0,0,1,1,0,1,0,0,1,1,0,0,0,0,0,0,0},
// //     //     {0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0},
// //     //     {1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
// //     //     {0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,1,0,0},
// //     //     {0,0,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,0},
// //     //     {0,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,1},
// //     //     {1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0},
// //     //     {1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,1,0,0},
// //     //     {0,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,1,0},
// //     //     {0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,1},
// //     //     {0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0},
// //     //     {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1},
// //     //     {0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0}
// //     // };