#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 4

int main(void) {

	FILE* fp;
	char nome_file[20];
	int** mat, N, i, j;

	// allocazione matrice 

	printf("Inserisci il numero di righe della matrice:\n");
	scanf("%d", &N);

	mat = (int**)malloc(N * sizeof(int));
	for ( i = 0; i < N; i++) {
		mat[i] = (int*)malloc(M * sizeof(int));
		if (mat == NULL || mat[i] == NULL) {
			printf("ERRORE ALLOCAZIONE MATRICE.\n");
			exit(EXIT_FAILURE);
		}
	}

	// apertura file

	
	fp = fopen(nome_file, "r");
	if (fp == NULL) {
		printf("ERRORE IN APERTURA FILE INPUT.\n");
		exit(EXIT_FAILURE);
	}

	//lettura matrice da file

	for ( i = 0; i < N && !feof(fp) ; i++) {
		for ( j = 0; j < M; j++) {
			fscanf(fp, "%d", &mat[i][j]);
		}
	}
	int dimr = i;
	fclose(fp);
	//stampa matrice

	for (int i = 0; i < dimr; i++) {
		for ( j = 0; j < M; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	// somma colonne

	int sum , count = 0;
	for (int j = 0; j < M; j++) {
		sum = 0;
		for (int i = 0; i < dimr; i++) {
			sum += mat[i][j];
		}
		printf("La somma della colonna %d e' sum: %d.\n", j + 1, sum);
		if ((sum % 2) == 0) {
			count++;
		}
	}

	if (count == M) {
		printf("La matrice rispetta la condizione.\n");
	}
	else printf("La matrice non rispetta la condizione.\n");


	return 0;
}