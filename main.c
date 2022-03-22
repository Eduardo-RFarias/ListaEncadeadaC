#include "stdio.h"
#include "stdlib.h"
typedef struct Node
{
    int val;
    struct Node *prox;
} Node;

Node *add(Node *raiz, int val)
{
    if (raiz == NULL)
    {
        raiz = (Node *)malloc(sizeof(Node));
        raiz->val = val;
        raiz->prox = NULL;
        return raiz;
    }

    Node *aux = raiz;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    Node *newPosition = (Node *)malloc(sizeof(Node));

    aux->prox = newPosition;

    newPosition->val = val;
    newPosition->prox = NULL;

    return raiz;
}

void clear(Node *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    Node *atual = raiz;
    Node *proximo = raiz->prox;

    while (proximo != NULL)
    {
        free(atual);
        atual = proximo;
        proximo = atual->prox;
    }
    free(atual);
}

int main()
{
    Node *raiz = NULL;

    raiz = add(raiz, 1);
    raiz = add(raiz, 2);
    raiz = add(raiz, 3);

    clear(raiz);

    return 0;
}
