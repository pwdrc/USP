#ifndef LIVRO_H
#define LIVRO_H

typedef struct Livro {
    int id;
    char* titulo;
    char* autor;
} Livro;

typedef struct Pilha {
    Livro* livro;
    Pilha* prox;
}

void addLivro(Pilha** pilha, Livro* livro);

#endif