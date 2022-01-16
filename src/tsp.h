#ifndef TSP_H
#define TSP_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

int **readGraph(int **arr, int num_vertices, char *name);
void Inicialize(int *vertex, int *cities, int *min_path, int num_vertices);

void travelingSalesmanProblem(int **graph, int *vertex, int num_vertices, int *cities, int *min_path);
void permutation(int *vertex, int start, int end, int **graph, int num_vertices, int *cities, int *min_path);
void swap(int *a, int *b);
void result(double time_spent);
void printMatrix(int **matrix, int num_vertices);
void printVetores(int *vertex, int *cities, int *min_path, int num_vertices);

int getMinPathWeight();
long int getCurrentCombinacoes();

long double factorial(int n);
long double percentageExecution();

int atoi(const char *string);

#endif
