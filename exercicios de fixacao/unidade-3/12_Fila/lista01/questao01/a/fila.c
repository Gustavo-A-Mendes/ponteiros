#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct _fila {
    int ini, fim;
    int qtde;       // num de elementos da fila
    int MAX_SIZE;   // tamanho máximo da fila
    int *val;       // vetordos valores
};

Fila* fila_cria(int MAX_SIZE)
{
    Fila *Q = (Fila*)calloc(1, sizeof(Fila));

    Q->val = (int*)calloc(MAX_SIZE, sizeof(int));
    Q->MAX_SIZE = MAX_SIZE;
    Q->qtde = 0;
    Q->ini = Q->fim = 0;

    return Q;
}

void fila_libera(Fila **Q)
{
    Fila *Qaux = *Q;
    free(Qaux->val);
    free(Qaux);
    *Q = NULL;
}

int fila_vazia(Fila *Q)
{
    return (Q->qtde == 0);
}

int fila_cheia(Fila *Q)
{
    return (Q->qtde == Q->MAX_SIZE);
}

int fila_insere(Fila *Q, int elem)
{
    if (fila_cheia(Q))
    {
        printf("Warning: Fila esta cheia.\n");
        return 0;   // falha na inserção
    }
    else
    {
        Q->val[Q->fim] = elem;
        Q->fim = (Q->fim+1) % Q->MAX_SIZE;
        Q->qtde++;
        return 1;   // falha na inserção
    }
}

int fila_retira(Fila *Q)
{
    if (fila_vazia(Q))
    {
        printf("Warning: Fila esta vazia.\n");
        return 0;   // falha na remoção
    }
    else
    {
        Q->ini = (Q->ini+1) % Q->MAX_SIZE;
        Q->qtde--;
        return 1;   // sucesso na remoção
    }
}

int fila_consulta(Fila *Q, int *elem)
{
   if (fila_vazia(Q))
    {
        printf("Warning: Fila esta vazia.\n");
        return 0;   // falha ao consultar fila
    }
    else
    {
        *elem = Q->val[Q->ini];
        return 1;   // sucesso ao consultar fila
    } 
}

void fila_imprime(Fila *Q)
{
    // printf("%d\n", Q->ini);
    // printf("%d\n", Q->fim);
    // printf("%d\n", Q->qtde);
    printf("\nInicio da Fila\n-->\n");
    int i = Q->ini;
    do
    {
        printf("%d\n", Q->val[i]);
        i = (i+1) % (Q->MAX_SIZE);
    } while (i != Q->fim);
    printf("<--\nFim da Fila\n");
    
}
