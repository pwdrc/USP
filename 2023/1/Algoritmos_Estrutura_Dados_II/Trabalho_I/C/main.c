/* 
ALGORITMOS E ESTRUTURA DE DADOS 2
TRABALHO 1
Processamento de Campos e Registro em Arquivos

Decrição:
Este trabalho consiste na leitura de uma entrada (stdin) contendo dados de registros de
l_livro, escrita desses dados em um arquivo (modo binário) e leitura e impressão dos m
últimos registros escritos no arquivo. Vamos imaginar que você está desenvolvendo um
gerenciador de l_livro para a biblioteca pessoal do seu professor preferido!
*/

#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

int main() {

    int n, m;
    char s[9] = "save";
  
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        Livro* livro = (Livro*) malloc(sizeof(Livro));
        scanf("%d", &livro->id);
        scanf(" %[^(\r|\n)]", livro->titulo);
        scanf(" %[^(\r|\n)]", livro->autor);
        salvaLivro(livro, s);
        free(livro);
    }

    scanf("%d", &m);

    // calcular quantas posicas deve pular para ler os m ultimos:
    int pula = n - m;
    
    Livro lista[n];
    lerTodosOsLivros(lista, s, n);


    for(int i = pula; i < n; i++) {
        printf("Id: %d\n", lista[i].id);
        printf("Titulo: %s\n", lista[i].titulo);
        printf("Autor: %s\n", lista[i].autor);
        printf("Byteoffset: %d\n", lista[i].byteOffset);
        printf("\n");
    }
    return 0;
}
