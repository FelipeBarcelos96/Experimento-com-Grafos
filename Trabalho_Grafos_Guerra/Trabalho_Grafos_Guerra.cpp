// Trabalho_Grafos_Guerra.cpp : define o ponto de entrada para o aplicativo do console.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "stdafx.h"
#include <cstdio>
#include <stdlib.h>
#include <memory.h>
#include "Trabalho_Grafos_Guerra.h"

int main()
{
	int N, E, X, Y, H, K, O, D;
	Grafo Correios;
	int Resultados[MAX_K];

	scanf("%d %d \n", &N, &E);
	memset(&Correios.MatAdj, 0, sizeof(Correios.MatAdj));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Correios.MatDist[i][j] = INT_MAX;
		}
	}
	
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d \n", &X, &Y, &H);
		Correios.MatAdj[X - 1][Y - 1] = 1;
		Correios.MatDist[X - 1][Y - 1] = H;
	}

	scanf("%d \n", &K);

	for (int i = 0; i < K-1; i++) {
		scanf("%d %d \n", &O, &D);
		Resultados[i] = Dijkstra(Correios, O - 1, D - 1, N);
	}
	scanf("%d %d", &O, &D);
	Resultados[K-1] = Dijkstra(Correios, O - 1, D - 1, N);
	printf("\n");
	for (int i = 0; i < K; i++) {
		if (Resultados[i] == -1) {
			printf("Nao e possivel entregar a carta\n");
		}
		else {
			printf("%d\n", Resultados[i]);
		}
	}
	printf("\n");

	system("Pause");
    return 0;
}

int Dijkstra(Grafo &G, int s, int dest, int N) {
	int Dist[MAX_N];
	int P[MAX_N];
	int L[MAX_N];

	for (int i = 0; i < N; i++) {
		L[i] = 1;
	}
	memset(&P, -1, sizeof(P));
	for (int i = 0; i < N; i++) {
		Dist[i] = INT_MAX;
	}
	
	L[s] = 0;
	Dist[s] = 0;
	
	for (int i = 0; i < N; i++) {
		if (G.MatAdj[s][i] == 1) {
			Dist[i] = G.MatDist[s][i];
		}
		if (G.MatAdj[s][i] == 1 && G.MatAdj[i][s] == 1) {
			Dist[i] = 0;
		}
	}

	int Flag = 0;
    int MP, MD;
	for (int i = 0; i < N; i++) {
		if (Dist[i] >= 0 && Dist[i] < INT_MAX) {
			Flag = 1;
			break;
		}
	}

	while(Flag == 1) {
		Flag = 0;
		MP = -1;
		MD = INT_MAX;
		for (int i = 0; i < N; i++) {
			if (Dist[i] < MD && L[i] == 1) {
				MD = Dist[i];
				MP = i;
			}
		}
		if (MP != -1) {
			L[MP] = 0;

			for (int i = 0; i < N; i++) {
				if (G.MatAdj[MP][i] == 1 && L[i] == 1) {
					if ((Dist[MP] + G.MatDist[MP][i]) < Dist[i]) {
						Dist[i] = Dist[MP] + G.MatDist[MP][i];
						P[i] = MP;
					}
				}
				if (G.MatAdj[MP][i] == 1 && L[i] == 1 && G.MatAdj[i][MP] == 1) {
					if (Dist[MP] < Dist[i]){
						Dist[i] = Dist[MP];
					}
				}
				
			}

			for (int i = 0; i < N; i++) {
				if (L[i] == 1) {
					Flag = 1;
				}
			}
		}
	}

	if (Dist[dest] < INT_MAX) {
		return Dist[dest];
	}
	else {
		return -1;
	}
}
