// estrutura do registro

#ifndef LIVRO_H
#define LIVRO_H

typedef struct Livro {
    int id;
    char titulo[100];
    char autor[50];
} Livro;

/**
typedef ListaDeLivros* p;
typedef struct ListaDeLivros {
    Livro* l;
    p* prox;
    int altura;
} ListaDeLivros;
void criaListaDeLivros();

*/

Livro* novoLivro(int id, char* titulo, char* autor);
Livro* buscaLivro(Livro* l, FILE* arq);
void addLivro(Livro* l, FILE* arq);
void rmLivro(Livro* l, FILE* arq);

#endif