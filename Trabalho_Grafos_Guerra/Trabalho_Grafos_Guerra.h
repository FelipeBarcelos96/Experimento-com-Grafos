#pragma once
#ifndef TRABALHO_GRAFOS_GUERRA_H_INCLUDED
#define TRABALHO_GRAFOS_GUERRA_H_INCLUDED

#define MAX_N 100
#define MAX_K 50


typedef struct tGrafo {
	int MatAdj[MAX_N][MAX_N];
	int MatDist[MAX_N][MAX_N];
}Grafo;

int Dijkstra(Grafo &G, int s, int dest, int N);

#endif // TRABALHO_GRAFOS_GUERRA_H_INCLUDED