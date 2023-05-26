#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

IndicePrimario lista_primario[MAX_LIVROS];
int tamanho_lista_primario = 0;

IndiceSecundario lista_secundario[MAX_LIVROS];
int tamanho_lista_secundario = 0;

IndicePrimario *ler_indice_primario() {
  FILE *primario = fopen("primario.txt", "r");
  if (primario == NULL) {
    // printf("Erro ao abrir o arquivo do índice primário!\n");
    return NULL;
  }

  IndicePrimario *cabeca = NULL;
  char linha[MAX_LINHA];

  while (fgets(linha, MAX_LINHA, primario) != NULL) {
    linha[strcspn(linha, "\n")] = '\0'; // Remover o caractere de nova linha
    if (strncmp(linha, "id:", 3) == 0) {
      int id;
      long int bo;
      sscanf(linha, "id:%d", &id);
      fgets(linha, MAX_LINHA, primario); // Ler a próxima linha "bo:..."
      sscanf(linha, "bo:%ld", &bo);

      IndicePrimario novo;
      novo.id = id;
      novo.bo = bo;

      lista_primario[tamanho_lista_primario++] = novo;

      if (cabeca == NULL) {
        cabeca = &lista_primario[tamanho_lista_primario - 1];
      }
    }
  }

  fclose(primario);

  return cabeca;
}

void escrever_lista_primario(IndicePrimario *lista, int tamanho,
                             FILE *primario) {
  for (int i = 0; i < tamanho; i++) {
    fprintf(primario, "id:%d\n", lista[i].id);
    fprintf(primario, "bo:%ld\n\n", lista[i].bo);
  }
}

void inserir_no_lista_primario(IndicePrimario lista[], int tamanho, int id,
                               long int bo) {
  int i;
  for (i = tamanho - 1; i >= 0 && lista[i].id > id; i--) {
    lista[i + 1] = lista[i];
  }
  lista[i + 1].id = id;
  lista[i + 1].bo = bo;
}

void escrever_lista_arquivo(IndicePrimario *lista, int tamanho,
                            FILE *primario) {

  for (int i = 0; i < tamanho; i++) {
    fprintf(primario, "bo:%ld\n", lista[i].bo);
    fprintf(primario, "id:%d\n\n", lista[i].id);
  }
}

void inserir_no_lista(IndicePrimario lista[], int tamanho, int id,
                      long int bo) {
  int i;
  for (i = tamanho - 1; i >= 0 && lista[i].id > id; i--) {
    lista[i + 1] = lista[i];
  }
  lista[i + 1].id = id;
  lista[i + 1].bo = bo;
}

int inserir_livro(int id, char *titulo, char *autor) {
  FILE *registro = fopen("registro.txt", "a");
  FILE *primario = fopen("primario.txt", "a");
  FILE *secundario = fopen("secundario.txt", "a");

  if (registro == NULL || primario == NULL) {
    printf("Erro ao abrir os arquivos!\n");
    return 1;
  }

  long int bo;
  fseek(registro, 0, SEEK_END);
  bo = ftell(registro);

  // Verificar se o ID já existe na lista primária
  for (int i = 0; i < tamanho_lista_primario; i++) {
    if (lista_primario[i].id == id) {

      fclose(registro);
      fclose(primario);

      return 2;
    }
  }

  // Inserindo o novo registro no índice primário em ordem crescente
  inserir_no_lista_primario(lista_primario, tamanho_lista_primario, id, bo);
  tamanho_lista_primario++;

  // Atualizando o arquivo primário com os registros atualizados
  fclose(primario);
  primario = fopen("primario.txt", "r+");
  if (primario == NULL) {
    printf("Erro ao abrir o arquivo do índice primário!\n");
    return 1; // Retornar código de erro
  }
  escrever_lista_primario(lista_primario, tamanho_lista_primario, primario);

  // Inserindo o novo registro no índice secundário em ordem alfabética de autor
  inserir_no_lista_secundario(lista_secundario, tamanho_lista_secundario, autor,
                              bo);
  tamanho_lista_secundario++;

  // Atualizando o arquivo secundário com os registros atualizados
  fclose(secundario);
  secundario = fopen("secundario.txt", "w");
  if (secundario == NULL) {
    printf("Erro ao abrir o arquivo do índice secundário!\n");
    return 1; // Retornar código de erro
  }
  escrever_lista_secundario(lista_secundario, tamanho_lista_secundario,
                            secundario);

  // Escrevendo o novo registro no arquivo de registros
  fprintf(registro, "id:%d\n", id);
  fprintf(registro, "titulo:%s\n", titulo);
  fprintf(registro, "autor:%s\n\n", autor);

  fclose(registro);
  fclose(primario);
  fclose(secundario);

  return 3;
}

IndiceSecundario *ler_indice_secundario() {
  FILE *secundario = fopen("secundario.txt", "r");
  if (secundario == NULL) {
    // printf("Erro ao abrir o arquivo do índice secundário!\n");
    return NULL;
  }

  IndiceSecundario *cabeca = NULL;
  char linha[MAX_LINHA];

  while (fgets(linha, MAX_LINHA, secundario) != NULL) {
    linha[strcspn(linha, "\n")] = '\0'; // Remover o caractere de nova linha
    if (strncmp(linha, "autor:", 6) == 0) {
      char autor[MAX_AUTOR];
      long int bo;
      sscanf(linha, "autor:%[^,],bo:%ld", autor, &bo);

      IndiceSecundario novo;
      strcpy(novo.autor, autor);
      novo.bo = bo;

      lista_secundario[tamanho_lista_secundario++] = novo;

      if (cabeca == NULL) {
        cabeca = &lista_secundario[tamanho_lista_secundario - 1];
      }
    }
  }

  fclose(secundario);

  return cabeca;
}

void busca_secundaria(char* autor) {
  int encontrados = 0;

  for (int i = 0; i < tamanho_lista_secundario; i++) {
    if (strcmp(lista_secundario[i].autor, autor) == 0) {
      encontrados++;

      FILE* registro = fopen("registro.txt", "r");
      if (registro == NULL) {
        printf("Erro ao abrir o arquivo de registros!\n");
        return;
      }

      fseek(registro, lista_secundario[i].bo, SEEK_SET);
      char linha[MAX_LINHA];
      int id;
      char titulo[MAX_LINHA];
      char a[MAX_LINHA];

      while (fgets(linha, MAX_LINHA, registro) != NULL) {
        if (strncmp(linha, "id:", 3) == 0) {
          sscanf(linha, "id:%d", &id);

          fgets(linha, MAX_LINHA, registro);
          sscanf(linha, "titulo:%[^\n]", titulo);

          fgets(linha, MAX_LINHA, registro);
          sscanf(linha, "autor:%[^\n]", a);

          if(strcmp(a, autor) == 0)
            printf("%d - %s - %s\n", id, titulo, a);
        }
      }

      fclose(registro);
      return;
    }
  }

  if (encontrados == 0) {
    printf("Não encontrado\n");
  }
}




  

void busca_primaria(int id) {
  int encontrados = 0;

  for (int i = 0; i < tamanho_lista_primario; i++) {
    if (lista_primario[i].id == id) {
      encontrados = 1;
      long int byte_offset = lista_primario[i].bo;
      FILE *registro = fopen("registro.txt", "r");
      if (registro == NULL) {
        printf("Erro ao abrir o arquivo de registros!\n");
        return;
      }

      fseek(registro, byte_offset, SEEK_SET);
      int id;
      char titulo[100];
      char autor[100];
      fscanf(registro, "id:%d\n", &id);
      fscanf(registro, "titulo:%99[^\n]\n", titulo);
      fscanf(registro, "autor:%99[^\n]\n\n", autor);

      fclose(registro);

      printf("----------------------------------------------------------\n");
      printf("%d - %s - %s\n", id, titulo, autor);
    }
  }

  if (!encontrados) {
    printf("----------------------------------------------------------\n");
    printf("Não encontrado\n");
  }
}
void escrever_lista_secundario(IndiceSecundario *lista, int tamanho,
                               FILE *secundario) {
  for (int i = 0; i < tamanho; i++) {
    fprintf(secundario, "autor:%s\nbo:%ld\n\n", lista[i].autor, lista[i].bo);
  }
}

void inserir_no_lista_secundario(IndiceSecundario lista[], int tamanho,
                                 char *autor, long int bo) {
  int i;
  for (i = tamanho - 1; i >= 0 && strcmp(lista[i].autor, autor) > 0; i--) {
    lista[i + 1] = lista[i];
  }
  strcpy(lista[i + 1].autor, autor);
  lista[i + 1].bo = bo;
}

void remover_por_id(int id) {
  int i;
  int encontrado = 0;

  for (i = 0; i < tamanho_lista_primario; i++) {
    if (lista_primario[i].id == id) {
      encontrado = 1;
      break;
    }
  }

  if (encontrado) {
    // Remover do índice secundário usando o byteoffset
    int byteoffset = lista_primario[i].bo;
    for (int j = 0; j < tamanho_lista_secundario; j++) {
      if (lista_secundario[j].bo == byteoffset) {
        for (int k = j; k < tamanho_lista_secundario - 1; k++) {
          lista_secundario[k] = lista_secundario[k + 1];
        }
        tamanho_lista_secundario--;
        break;
      }
    }

    // Remover do índice primário
    for (int j = i; j < tamanho_lista_primario - 1; j++) {
      lista_primario[j] = lista_primario[j + 1];
    }
    tamanho_lista_primario--;

    FILE *primario = fopen("primario.txt", "w");
    if (primario == NULL) {
      printf("Erro ao abrir o arquivo do índice primário!\n");
      return;
    }

    escrever_lista_primario(lista_primario, tamanho_lista_primario, primario);
    fclose(primario);

    FILE *secundario = fopen("secundario.txt", "w");
    if (secundario == NULL) {
      printf("Erro ao abrir o arquivo do índice secundário!\n");
      return;
    }

    escrever_lista_secundario(lista_secundario, tamanho_lista_secundario, secundario);
    fclose(secundario);

    printf("----------------------------------------------------------\n");
    printf("Registro removido\n");
  } else {
    printf("----------------------------------------------------------\n");
    printf("Erro ao remover\n");
  }
}


void remover_por_autor(char *autor) {
  int encontrados = 0;
  int qnt = 0;

  for (int i = 0; i < tamanho_lista_secundario; i++) {
    if (strcmp(lista_secundario[i].autor, autor) == 0) {
      encontrados = 1;
      qnt++;
      int byteoffset = lista_secundario[i].bo;

      // Remover do índice secundário
      for (int j = i; j < tamanho_lista_secundario - 1; j++) {
        lista_secundario[j] = lista_secundario[j + 1];
      }
      tamanho_lista_secundario--;
      i--; // Ajustar o índice para continuar verificando a posição atual

      // Remover do índice primário
      int encontrado_primario = 0;
      int posicao_encontrada = 0;
      //int id = 0;

      // Buscar o ID correspondente no índice primário usando o byteoffset
      for (int k = 0; k < tamanho_lista_primario; k++) {
        if (lista_primario[k].bo == byteoffset) {
          encontrado_primario = 1;
          posicao_encontrada = k;
          //id = lista_primario[k].id;
          break;
        }
      }

      if (encontrado_primario) {
        for (int l = posicao_encontrada; l < tamanho_lista_primario - 1; l++) {
          lista_primario[l] = lista_primario[l + 1];
        }
        tamanho_lista_primario--;
      }

      FILE *secundario = fopen("secundario.txt", "w");
      if (secundario == NULL) {
        printf("Erro ao abrir o arquivo do índice secundário!\n");
        return;
      }

      escrever_lista_secundario(lista_secundario, tamanho_lista_secundario, secundario);
      fclose(secundario);

      FILE *primario = fopen("primario.txt", "w");
      if (primario == NULL) {
        printf("Erro ao abrir o arquivo do índice primário!\n");
        return;
      }

      escrever_lista_primario(lista_primario, tamanho_lista_primario, primario);
      fclose(primario);
    }
  }

  if (encontrados) {
    printf("----------------------------------------------------------\n");
    for(int i = 0; i < qnt; i++)
      printf("Registro removido\n");
  } else {
    printf("----------------------------------------------------------\n");
    printf("Erro ao remover\n");
  }
}


/*
void remover_por_autor(char *autor) {
  int encontrados = 0;

  for (int i = 0; i < tamanho_lista_secundario; i++) {
    if (strcmp(lista_secundario[i].autor, autor) == 0) {
      encontrados = 1;
      for (int j = i; j < tamanho_lista_secundario - 1; j++) {
        lista_secundario[j] = lista_secundario[j + 1];
      }
      tamanho_lista_secundario--;
      i--; // Ajuste o índice para continuar verificando a posição atual

      FILE *secundario = fopen("secundario.txt", "w");
      if (secundario == NULL) {
        printf("Erro ao abrir o arquivo do índice secundário!\n");
        return;
      }

      escrever_lista_secundario(lista_secundario, tamanho_lista_secundario, secundario);
      fclose(secundario);
    }
  }

  if (encontrados) {
    printf("----------------------------------------------------------\n");
    printf("Registro removido\n");
  } else {
    printf("----------------------------------------------------------\n");
    printf("Erro ao remover\n");
  }
}
*/