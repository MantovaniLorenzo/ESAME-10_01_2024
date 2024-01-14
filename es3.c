#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void) {

	FILE* fp;
	char nome_file[20], c;
	int** mat, N, i, M, dimc = 0, tmp, j, dimr;

	// allocazione matrice 

	printf("Inserisci il numero di righe della matrice:\n");
	scanf("%d", &N);

	printf("Inserisci il numero delle colonne della matrice:\n");
	scanf("%d", &M);

	mat = (int**)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		mat[i] = (int*)malloc(M * sizeof(int));
		if (mat == NULL || mat[i] == NULL) {
			printf("ERRORE ALLOCAZIONE MATRICE.\n");
			exit(EXIT_FAILURE);
		}
	}

	// apertura file

	printf("Inserire il nome del file di input:\n");
	scanf("%s", nome_file);

	fp = fopen(nome_file, "r");
	if (fp == NULL) {
		printf("ERRORE IN APERTURA FILE INPUT.\n");
		exit(EXIT_FAILURE);
	}

	//lettura matrice da file
	
	do{
		fscanf(fp, "%d%c", &tmp, &c);
		dimc++;
	} while (c != '\n');

	fclose(fp);

	

	fp = fopen(nome_file, "r");
	if (fp == NULL) {
		printf("ERRORE APERTURA FILE.\n");
	}

	for (i = 0; i < N && !feof(fp) ; i++) {
		for (j = 0; j < dimc; j++) {
			fscanf(fp, "%d", &mat[i][j]);
		}
	}
	dimr = i;
	fclose(fp);
	//stampa matrice

	for (int i = 0; i < dimr; i++) {
		for (j = 0; j < dimc; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	// somma colonne

	int sum, count = 0;
	for (int j = 0; j < dimc; j++) {
		sum = 0;
		for (int i = 0; i < dimr; i++) {
			sum += mat[i][j];
		}
		printf("La somma della colonna %d e': %d.\n", j + 1, sum);
		if ((sum % 2) == 0) {
			count++;
		}
	}

	if (count == dimc) {
		printf("La matrice rispetta la condizione.\n");
	}
	else printf("La matrice non rispetta la condizione.\n");

	
	return 0;
	
}