#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>

#define MAX_AUTOR 100
#define MAX_TITULO 100
#define MAX_LINHA 256
#define MAX_LIVROS 1000

// Índice primário
typedef struct IndicePrimario {
  int id;
  long int bo;
} IndicePrimario;


// Índice secundário
typedef struct IndiceSecundario {
  char autor[MAX_AUTOR];
  long int bo;
} IndiceSecundario;

int inserir_livro(int id, char *titulo, char *autor);
long int busca_primario(int id);
IndicePrimario* ler_indice_primario();
void escrever_lista_primario(IndicePrimario* lista, int tamanho, FILE* primario);
void inserir_no_lista_primario(IndicePrimario lista[], int tamanho, int id, long int bo);
void remover_livro();
void escrever_lista_arquivo(IndicePrimario* lista, int tamanho, FILE* primario);
void busca_secundaria(char* autor);
void busca_primaria(int id);
IndiceSecundario* ler_indice_secundario();
void escrever_lista_secundario(IndiceSecundario* lista, int tamanho, FILE* secundario);
void inserir_no_lista_secundario(IndiceSecundario lista[], int tamanho, char* autor, long int bo);
void remover_por_autor(char* autor);
void remover_por_id(int id);
#endif

