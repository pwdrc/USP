#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

void addLivro(Pilha** pilha, Livro* livro) {
    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
    novo->livro = livro;
    novo->prox = *pilha;
    *pilha = novo;
}