#ifndef LIVRO_H
#define LIVRO_H
#define MAX_TAM 100

typedef struct Livro {
    int id;
    char titulo[MAX_TAM];
    char autor[MAX_TAM];
} Livro;

typedef struct Pilha {
    Livro* livro;
    struct Pilha* prox;
} Pilha;

Livro* leLivro(); 
void addLivro(Pilha** pilha, Livro* livro);
void printPilha(Pilha** pilha, int n);

#endif