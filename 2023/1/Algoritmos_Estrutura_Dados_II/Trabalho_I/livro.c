#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

void addLivro(Pilha** pilha, Livro* livro) {
    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
    novo->livro = livro;
    novo->prox = *pilha;
    *pilha = novo;
}

void printPilha(Pilha** pilha, int n) {
    Pilha* aux = *pilha;
    while(aux != NULL) {
        printf("Livro: %d:\n", aux->livro->id);
        printf("Título: %s\n", aux->livro->titulo);
        printf("Autor: %s\n", aux->livro->autor);
        aux = aux->prox;
    }
}