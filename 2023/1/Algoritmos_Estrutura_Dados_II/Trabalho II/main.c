#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

#define MAX_INPUT_SIZE 200

int main() {
  char input[MAX_INPUT_SIZE];

  //IndicePrimario* indice_primario = ler_indice_primario();
  //IndiceSecundario* indice_secundario = ler_indice_secundario();
    
  while (fgets(input, MAX_INPUT_SIZE, stdin)) {
    
    // tratar o comando ADD
    if (strncmp(input, "ADD", 3) == 0) {
      int id;
      char titulo[100];
      char autor[100];

      sscanf(input, "ADD id='%d' titulo='%99[^']' autor='%99[^']'", &id, titulo, autor);

      // tratando casos de inserção
      int add = inserir_livro(id, titulo, autor);

      // inserção bem sucedida
      if (add == 3) {
        printf("----------------------------------------------------------\n");
        printf("Registro inserido\n");
      } 

      // inserção mal sucedida
      else if (add == 2) {
        printf("----------------------------------------------------------\n");
        printf("Erro ao inserir registro, chave primária duplicada\n");
      }
    } else if (strncmp(input, "SEARCH", 6) == 0) {
      
      // Tratar comando SEARCH
      if (strstr(input, "autor='") != NULL) {
        
        // Comando SEARCH por autor
        char autor[MAX_INPUT_SIZE];
        sscanf(input, "SEARCH autor='%[^']", autor);
        printf("----------------------------------------------------------\n");
        busca_secundaria(autor);
      } else if (strstr(input, "id='") != NULL) {
        // Comando SEARCH por ID
        int id;
        sscanf(input, "SEARCH id='%d'", &id);
        busca_primaria(id);
      } else {
        printf("Comando de busca inválido\n");
      }
    } else if (strncmp(input, "REMOVE", 6) == 0) {
  // Tratar comando REMOVE
  if (strstr(input, "autor='") != NULL) {
    char autor[MAX_INPUT_SIZE];
    sscanf(input, "REMOVE autor='%[^']", autor);
    remover_por_autor(autor); // Chamar a função para remover por autor
  } else if (strstr(input, "id='") != NULL) {
    int id;
    sscanf(input, "REMOVE id='%d'", &id);
    remover_por_id(id); // Chamar a função para remover por ID
  }
} else if (strncmp(input, "EXIT", 4) == 0) {
      // Tratar comando EXIT
      break;
    } else {
      printf("Comando inválido\n");
    }
  }

  return 0;
}
