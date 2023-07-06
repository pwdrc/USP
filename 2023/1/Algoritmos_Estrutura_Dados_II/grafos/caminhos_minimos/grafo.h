#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dest;
    float peso;
    char nome[50];
    struct No* proximo;
} No;
 
typedef struct Lista {
    No* cabeca;
} Lista;


// Grafo

typedef struct GRAFO {
    int n; // numero de vertices
    int m; // numero de arestas

    Lista *lista;

} GRAFO;

GRAFO *criaGrafo(int n);

No *addNovoNo(int dest, int peso);

void addAresta(GRAFO *g, int src, int dest, float peso);

float* dijkstra(GRAFO *g, int origem);

float encontrarPesoAresta(GRAFO *g, int src, int dest);

#endif