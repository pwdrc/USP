#ifndef LIVRO_H
#define LIVRO_H
#define MAX_TAM 100

typedef struct Livro {
    int id;
    char titulo[MAX_TAM];
    char autor[MAX_TAM];
} Livro;

//typedef struct Pilha {
//    Livro* livro;
//    struct Pilha* prox;
//} Pilha;


Livro* leLivro();
void salvaLivro(Livro *livro, char *arquivo);
void imprimeLivro(Livro *livro);
Livro** lerUltimosLivros(char* arquivo, int pula, int m);
void posicionaNoCaractere(FILE* fp, char caractere);
//void addLivro(Pilha** pilha, Livro* livro);
//void salvaPilha(Pilha** pilha, char* arquivo);

#endif