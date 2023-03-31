#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

void addLivro(Pilha** pilha, Livro* livro) {
    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
    novo->livro = livro;
    novo->prox = *pilha;
    *pilha = novo;
}

// modificar depois para imprimir em arquivo
void printPilha(Pilha** pilha, int n) {
    Pilha* aux = *pilha;
    while(aux != NULL) {
        printf("Id: %d:\n", aux->livro->id);
        printf("Titulo: %s\n", aux->livro->titulo);
        printf("Autor: %s\n", aux->livro->autor);
        printf("Byte offset: %d", 200); // posição no arquivo
        aux = aux->prox;
    }
}

Livro* leLivro() {
    Livro* livro = (Livro*) malloc(sizeof(Livro));
    scanf("%d", &livro->id);
    scanf(" %[^(\r|\n)]", livro->titulo);
    scanf(" %[^(\r|\n)]", livro->autor);
    return livro;
}