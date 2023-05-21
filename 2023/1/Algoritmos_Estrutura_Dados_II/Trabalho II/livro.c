#include <stdio.h>
#include "livro.h"

Livro* novoLivro(int id, char* titulo, char* autor) {

    Livro* l = (Livro*) malloc(sizeof(Livro));
    if (l == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    
    l->id = id;
    l->titulo = titulo;
    l->autor = autor;

    return l;
}

/**
Livro buscaLivro(Livro* l, FILE* arq) {
    return Livro;
}

void addLivro(Livro* l, FILE* arq) {
    return 0;
}

void rmLivro(Livro* l, FILE* arq) {

}

*/
