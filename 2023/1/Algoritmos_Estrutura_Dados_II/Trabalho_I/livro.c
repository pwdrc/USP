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
 
// modificar depois para imprimir em arq
//void salvaPilha(Pilha** pilha, char* arq) {
//    Pilha* aux = *pilha;
//    FILE* arq = fopen(arq, "w");
//    if(arq == NULL) {
//        printf("erro ao abrir o arq\n");
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
//        //fprintf(arq, "Byte offset: %d\n", byteOffset); // posição no arq
//        byteOffset += sizeof(Livro);
//        aux = aux->prox;
//    }
//    fclose(arq);
//}

void salvaLivro(Livro *livro, char *arquivo, int byteOffset) {
    FILE* arq = fopen(arquivo, "a");
    if(arq == NULL) {
        printf("erro ao abrir o arq\n");
        return;
    }
    
    // id
    fwrite(&(livro->id), sizeof(int), 1, arq);

    // titulo
    fwrite(&(livro->titulo), sizeof(char), strlen(livro->titulo), arq);
    fwrite("|", sizeof(char), 1, arq);
    
    // comprimento autor
    int autor_len = strlen(livro->autor);
    fwrite(&autor_len, sizeof(int), 1, arq);

    // autor
    fwrite(&(livro->autor), sizeof(char), strlen(livro->autor), arq);
    
    // byteOffset
    fwrite(&byteOffset, sizeof(int), 1, arq); // posição no arq
    fwrite("#", sizeof(char), 1, arq);
    
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

void imprimeLivro(Livro *livro) {
    printf("Id: %d\n", livro->id);
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("\n");
}

Livro* leLivroArq(char *arquivo) {
    FILE* arq = fopen(arquivo, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arq.\n");
        return 0;
    }

    Livro* livro = (Livro*) malloc(sizeof(Livro));
    
    
    // ler id
    fread(&(livro->id), sizeof(int), 1, arq);
    
    // ler titulo
    int i = 0;
    char c = fgetc(arq);
    while (c != '|') {
        livro->titulo[i++] = c;
        c = fgetc(arq);
    }
    livro->titulo[i] = '\0';
    
    // ler autor
    int len_autor;
    fread(&len_autor, sizeof(int), 1, arq);
    fgets(livro->autor, len_autor + 1, arq);
    // Remover o símbolo de fim de registro
    livro->autor[strlen(livro->autor)] = '\0';
    
    return livro;
}