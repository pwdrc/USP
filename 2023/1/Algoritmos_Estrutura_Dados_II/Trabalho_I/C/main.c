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

    //Pilha* pilhaDelivros = NULL;
   
    // n: número de livros de entrada
    // m: número de m últimos livros a exibir
    // m deve ser <= n
    int n, m;

    // s: save.txt: nome do arquivo para salvar os dados
    char s[9] = "save";
  
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        Livro* l = leLivro();
        salvaLivro(l, s);

        //addLivro(&pilhaDelivros, l);
    }

    scanf("%d", &m);

    // calcular quantas posicas deve pular para ler os m ultimos:
    int pula = m - n - 1;
    Livro** lista = lerUltimosLivros(s, pula, m);
    for(int i = 0; i < m; i++) {
        imprimeLivro(lista[i]);
    }
    return 0;
}