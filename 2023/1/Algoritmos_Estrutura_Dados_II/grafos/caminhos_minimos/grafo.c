#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include <float.h>

No *addNovoNo(int dest, int peso) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->dest = dest;
    novoNo->peso = peso;
    novoNo->proximo = NULL;
    return novoNo;
}

GRAFO *criaGrafo(int n) {
    GRAFO *g = (GRAFO*)malloc(sizeof(GRAFO));

    g->n = n;
    g->m = 0;
    g->lista = (Lista*)malloc(sizeof(Lista) * n);
    
    int i = 0;
    while(i < n) {
        g->lista[i].cabeca = NULL;
        i++;
    }

    return g;
}

void addAresta(GRAFO *g, int src, int dest, float peso) {
    if(!g) return; // verifica se o grafo existe
    if(src < 0 || dest < 0) return;

    No* novo = addNovoNo(dest, peso);

    novo->proximo = g->lista[src].cabeca;
    g->lista[src].cabeca = novo;
    g->m++;
}

    /*
    No *check = (No*)malloc(sizeof(No));
    check = NULL;
    No *novoNo = addNovoNo(dest, peso);

    if (g->lista[src].cabeca == NULL) {
        novoNo->proximo = NULL;
        g->lista[src].cabeca = novoNo;
    } else {
        check = g->lista[src].cabeca;
        while (check->proximo != NULL) {
            check = check->proximo;
        }
        check->proximo = novoNo;
    }

    novoNo = addNovoNo(src, peso);
    if (g->lista[dest].cabeca == NULL) {
        novoNo->proximo = NULL;
        g->lista[dest].cabeca = novoNo;
    } else {
        check = g->lista[dest].cabeca;
        while (check->proximo != NULL) {
            check = check->proximo;
        }
        check->proximo = novoNo;
    }
}
*/


float* dijkstra(GRAFO *g, int origem) {
    int n = g->n;
    float* distancia = (float*)malloc(n * sizeof(float));
    int* visitado = (int*)malloc(n * sizeof(int));
    int i, j, proximo;
    float min;

    // Inicializa as distâncias como infinito e os vértices como não visitados
    for (i = 0; i < n; i++) {
        distancia[i] = FLT_MAX;
        visitado[i] = 0;
    }

    // Define a distância da origem para si mesma como 0
    distancia[origem] = 0.0;

    // Encontra o caminho mínimo para todos os vértices
    for (i = 0; i < n; i++) {
        min = FLT_MAX;

        // Encontra o vértice com a menor distância não visitado
        for (j = 0; j < n; j++) {
            if (!visitado[j] && distancia[j] <= min) {
                min = distancia[j];
                proximo = j;
            }
        }

        // Marca o vértice atual como visitado
        visitado[proximo] = 1;

        // Atualiza as distâncias dos vértices adjacentes não visitados
        for (j = 0; j < n; j++) {
            float peso = encontrarPesoAresta(g, proximo, j); // Função para encontrar o peso da aresta entre os vértices
            if (!visitado[j] && g->lista[proximo].cabeca != NULL && peso != -1 &&
                distancia[proximo] != FLT_MAX && distancia[proximo] + peso < distancia[j]) {
                distancia[j] = distancia[proximo] + peso;
            }
        }
    }

    free(visitado);
    return distancia;
}


float encontrarPesoAresta(GRAFO *g, int src, int dest) {
    No *no = g->lista[src].cabeca;
    while (no != NULL) {
        if (no->dest == dest) {
            return no->peso;
        }
        no = no->proximo;
    }
    return -1.0;  // Retorna -1 se a aresta não existir
}