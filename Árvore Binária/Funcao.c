#include <stdio.h>
#include <stdlib.h>
#include "Funcao.h"

int total_nos = 0;

// Cria nó
No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return NULL;
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    
    total_nos++;
    return novo;
}

// Monta árvore balanceada
No* construir_arvore(int inicio, int fim) {
    if (inicio > fim) return NULL;

    int meio = (inicio + fim) / 2;
    No* raiz = criar_no(meio);

    raiz->esq = construir_arvore(inicio, meio - 1);
    raiz->dir = construir_arvore(meio + 1, fim);

    return raiz;
}

//Imprime todos os nos da arvoré
void imprimir_arvore(No* raiz, int nivel) {
    int i;
    if (raiz == NULL) return;

    // Imprime primeiro o lado direito
    imprimir_arvore(raiz->dir, nivel + 1);

    // Espaçamento
    for (i = 0; i < nivel; i++) {
        printf("    ");
    }

    // Desenha o ramo
    if (nivel > 0) {
        if (raiz->dir != NULL || raiz->esq != NULL)
            printf("+-- ");
        else
            printf("-- ");
    }

    // Valor do nó
    printf("%d\n", raiz->valor);

    // Imprime o lado esquerdo
    imprimir_arvore(raiz->esq, nivel + 1);
}

//Mostra o consumo da Arvoré na memória
void mostrar_memoria() {
    int total_bytes;

    total_bytes = total_nos * sizeof(No);

    printf("\n=== USO DE MEMORIA ===\n\n");
    printf("Nos alocados: %d\n", total_nos);
    printf("Tamanho de cada No: %lu bytes\n", sizeof(No));
    printf("Memoria total usada: %d bytes (~%d KB)\n\n", total_bytes, total_bytes / 1024);
}

// Libera memória
void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;

    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
    total_nos--;
}
