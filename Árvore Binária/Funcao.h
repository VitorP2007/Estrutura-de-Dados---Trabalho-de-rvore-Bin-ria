#ifndef FUNCAO_H
#define FUNCAO_H

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* criar_no(int valor);

No* construir_arvore(int inicio, int fim);

void imprimir_arvore(No* raiz, int nivel);

void mostrar_memoria();

void liberar_arvore(No* raiz);

#endif
