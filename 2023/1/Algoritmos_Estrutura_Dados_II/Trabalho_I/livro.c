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
void salvaPilha(Pilha** pilha, char* arquivo) {
    Pilha* aux = *pilha;
    FILE* arq = fopen(arquivo, "w");
    if(arq == NULL) {
        printf("erro ao abrir o arquivo\n");
        return;
    }
    int byteOffset = 0;
    while(aux != NULL) {
        fprintf(arq, "Id: %d:\n", aux->livro->id);
        fprintf(arq, "Titulo: %s\n", aux->livro->titulo);
        fprintf(arq, "Autor: %s\n", aux->livro->autor);
        fprintf(arq, "Byte offset: %d\n", byteOffset); // posição no arquivo
        byteOffset += sizeof(Livro);
        aux = aux->prox;
    }
    fclose(arq);
}

Livro* leLivro() {
    Livro* livro = (Livro*) malloc(sizeof(Livro));
    scanf("%d", &livro->id);
    scanf(" %[^(\r|\n)]", livro->titulo);
    scanf(" %[^(\r|\n)]", livro->autor);
    return livro;
}