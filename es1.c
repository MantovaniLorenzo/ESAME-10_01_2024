#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct m {

	char isbn[18];
	char vend[2];
	char data[11];
	int copie;

}stats;


int main(void) {

	FILE* fp;
	char nome_file[20], find[18];
	stats* v;
	int N, dim, i;

	do {
		printf("Inserire il numero di elementi che si vogliono gestire: ");
		scanf("%d", &N);
	} while (N <= 0);

	// allocazione dinamica vettore di stuct

	v = (stats*)malloc(N * sizeof(stats));
	if (v == NULL) {
		printf("ERRORE DI ALLOCAZIONE VETTORE.\n");
		exit(EXIT_FAILURE);
	}


	// apertura file 

	printf("Inserire il nome del file di input:\n");
	scanf("%s", nome_file);

	fp = fopen(nome_file, "r");
	if (fp == NULL) {
		printf("ERRORE APERTURA FILE DI INPUT.\n");
		exit(EXIT_FAILURE);
	}

	//lettura file

	i = 0;
	while (i < N && fscanf(fp, "%s%s%s%d", v[i].isbn, v[i].vend, v[i].data, &v[i].copie) != EOF) {
		i++;
	}
	dim = i; // reale dimensione degli elementi letti
	fclose(fp);


	// richiesta all'utente 

	char ris[3] = "NO", choice[3];

	do {
		printf("Inserire un ISBN che si vuole cancellare:\n");
		scanf("%s", find);
		for (int i = 0; i < dim; i++) 
			if (strcmp(find, v[i].isbn) == 0) {
				for (int j = i; j < dim - 1; j++) {
					v[j] = v[j + 1];
				}
				dim--;
				if (dim != 0) {
					v = (stats*)realloc(v, dim * sizeof(stats));
					if (v == NULL) {
						printf("ERRORE DI RIALLOCAZIONE.\n");
						exit(EXIT_FAILURE);
					}
				}
				else {
					printf("TUTTI GLI ELEMENTI SONO STATI CANCELLATI.\n");
					exit(EXIT_FAILURE);
				}i--;
			}
		
		printf("Vuoi ripetere l'azione, digitare SI oppure NO (nel caso di formato sbagliato verra' effettuata nuovamente la cancellazione).\n");
		scanf("%s", choice);

	} while (strcmp(choice, ris) != 0);

	int* mese = (int*)malloc(dim * sizeof(int));
	if (mese == NULL) {
		printf("ERRORE DI ALLOCAZIONE.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < dim; i++) {
		sscanf(v[i].data, "%*d/%d/%*d", &mese[i]);
	}

	
	for (int i = 0; i < dim; i++) {
		printf("ISBN : %s MESE : %d COPIE : %d.\n", v[i].isbn, mese[i], v[i].copie);
	}
	

	return 0;
}