#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

void salvaLivro(Livro* livro, char* arquivo) {
    
    FILE* arq = fopen(arquivo, "ab");
    if(arq == NULL) {
        printf("erro ao abrir o arq\n");
        return;
    }
    
    // id
    fwrite(&(livro->id), sizeof(int), 1, arq);

    // titulo
    fwrite(livro->titulo, sizeof(char), strlen(livro->titulo), arq);
    fwrite("|", sizeof(char), 1, arq);
    
    // comprimento autor
    int autor_len = strlen(livro->autor);
    fwrite(&autor_len, sizeof(int), 1, arq);

    // autor
    fwrite(livro->autor, sizeof(char), strlen(livro->autor), arq);

    // fim do registro
    fwrite("#", sizeof(char), 1, arq);
   
    fclose(arq);
    
}

void lerTodosOsLivros(Livro* lista, char* arquivo, int n) {
    
    FILE* arq = fopen(arquivo, "rb");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de leitura!\n");
        return;
    }
    
    // calcular tamanho do arquivo
    fseek(arq, 0, SEEK_END);
    long size = ftell(arq);
    rewind(arq);

    // ler todos os registros
    int i = 0;
    while(ftell(arq) < size && i < n) {

        // id
        fread(&(lista[i].id), sizeof(int), 1, arq);

        // titulo
        int j = 0;
        char c = fgetc(arq);
        while (c != '|') {
            lista[i].titulo[j] = c;
            j++;
            c = fgetc(arq);
        }
        lista[i].titulo[j] = '\0';

        // avançar mais um caractere para ignorar o delimitador "|"

        // autor
        int tamanhoAutor;
        fread(&tamanhoAutor, sizeof(int), 1, arq);
        fread(lista[i].autor, sizeof(char), tamanhoAutor, arq);

        // avançar mais um caractere para ignorar o delimitador "#"
        c = fgetc(arq);

        lista[i].byteOffset = i * (sizeof(int) + strlen(lista[i].titulo) + 1 + sizeof(int) + strlen(lista[i].autor) + 1);

        // incrementar o contador de livros
        i++;
    }

    fclose(arq);
}