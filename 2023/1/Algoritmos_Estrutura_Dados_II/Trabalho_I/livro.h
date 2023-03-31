#ifndef LIVRO_H
#define LIVRO_H

typedef struct Livro {
    int id;
    char* titulo;
    char* autor;
} Livro;

typedef struct Pilha {
    Livro* livro;
    struct Pilha* prox;
} Pilha;

void addLivro(Pilha** pilha, Livro* livro);
void printPilha(Pilha** pilha, int n);

#endif