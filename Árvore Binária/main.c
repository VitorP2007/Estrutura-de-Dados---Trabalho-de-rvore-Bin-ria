#include <stdio.h>
#include <stdlib.h>
#include "Funcao.h"

int main() {
    int opcao, resposta, tentativas;
    No *raiz = NULL;
    No *atual = NULL;

    while (1) {
        printf("\n===== MENU =====\n\n");
        printf("1 - Jogar\n");
        printf("2 - Mostrar arvore\n");
        printf("3 - Mostrar Memoria\n");
        printf("0 - Sair\n\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                if (raiz != NULL) {
                    liberar_arvore(raiz);
                }
                printf("\nObrigado por jogar!\n");
                return 0;

            case 1:
                if (raiz != NULL) {
                    liberar_arvore(raiz);
                }

                raiz = construir_arvore(0, 1000);
                atual = raiz;
                resposta = -1;
                tentativas = 0;

                printf("\nPense em um numero entre 0 e 1000.\n");
                system("pause");

                while (atual != NULL && resposta != 0) {
                    printf("\nMeu palpite: %d\n\n", atual->valor);
                    printf("0 = Igual \n\n1 = Maior \n\n2 = Menor\n\n");
                    printf("Resposta: ");
                    scanf("%d", &resposta);

                    if (resposta == 0) {
                        tentativas++;
                        printf("\nAcertei em %d tentativas!\n", tentativas);
                    }
                    else if (resposta == 1) {
                        tentativas++;
                        atual = atual->dir;
                    }
                    else if (resposta == 2) {
                        tentativas++;
                        atual = atual->esq;
                    }
                    else {
                        printf("\nOpcao invalida!\n");
                    }
                }
                break;
                
            case 2:
                if (raiz == NULL) {
                    printf("\nA arvore ainda nao foi criada. Jogue primeiro.\n");
                } else {
                    printf("\n=== ARVORE BINARIA ===\n\n");
                    imprimir_arvore(raiz, 0);
                }
                break;
                
			case 3:
				mostrar_memoria();
				break;
				
            default:
                printf("\nValor invalido!\n");
        }
    }
    return 0;
}
