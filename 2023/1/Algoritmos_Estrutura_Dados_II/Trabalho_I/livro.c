#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

//void addLivro(Pilha** pilha, Livro* livro) {
//    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
//    novo->livro = livro;
//    novo->prox = *pilha;
//    *pilha = novo;
//}
 
// modificar depois para imprimir em arquivo
//void salvaPilha(Pilha** pilha, char* arquivo) {
//    Pilha* aux = *pilha;
//    FILE* arq = fopen(arquivo, "w");
//    if(arq == NULL) {
//        printf("erro ao abrir o arquivo\n");
//        return;
//    }
//    int byteOffset = 0;
//    while(aux != NULL) {
//        fwrite(&aux->livro->id, sizeof(int), 1, arq);
//        fwrite(aux->livro->titulo, sizeof(char), strlen(aux->livro->titulo), arq);
//        fwrite(aux->livro->autor, sizeof(char), strlen(aux->livro->autor), arq);
//        //fprintf(arq, "Id: %d:\n", aux->livro->id);
//        //fprintf(arq, "Titulo: %s\n", aux->livro->titulo);
//        //fprintf(arq, "Autor: %s\n", aux->livro->autor);
//        //fprintf(arq, "Byte offset: %d\n", byteOffset); // posição no arquivo
//        byteOffset += sizeof(Livro);
//        aux = aux->prox;
//    }
//    fclose(arq);
//}

void salvaLivro(Livro *livro, char *arquivo, int byteOffset) {
    FILE* arq = fopen(arquivo, "a");
    if(arq == NULL) {
        printf("erro ao abrir o arquivo\n");
        return;
    }
    fprintf(arq, "Id: %d\n", livro->id);
    fprintf(arq, "Titulo: %s\n", livro->titulo);
    fprintf(arq, "Autor: %s\n", livro->autor);
    fprintf(arq, "Byte offset: %d\n", byteOffset); // posição no arquivo
    byteOffset += sizeof(Livro);
    fclose(arq);
}

Livro* leLivro() {
    Livro* livro = (Livro*) malloc(sizeof(Livro));
    scanf("%d", &livro->id);
    scanf(" %[^(\r|\n)]", livro->titulo);
    scanf(" %[^(\r|\n)]", livro->autor);
    return livro;
}