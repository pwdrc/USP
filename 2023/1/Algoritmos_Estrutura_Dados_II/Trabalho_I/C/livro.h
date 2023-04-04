#ifndef LIVRO_H
#define LIVRO_H
#define MAX_TAM 100

typedef struct Livro {
    int id;
    char titulo[MAX_TAM];
    char autor[MAX_TAM];
    long int byteOffset;
} Livro;

void salvaLivro(Livro* livro, char *arquivo);
void lerTodosOsLivros(Livro*lista, char* arquivo, int m);

#endif