#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 10

typedef struct
{
    int dados[TAMANHO];
    int topo;
} Pilha;

void inicializar(Pilha *p)
{
    p->topo = -1;
}

bool isEmpty(Pilha *p)
{
    return p->topo == -1;
}

bool isFull(Pilha *p)
{
    return p->topo == TAMANHO - 1;
}

void push(Pilha *p, int valor)
{
    if (isFull(p))
    {
        printf("Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor;
}

int pop(Pilha *p)
{
    if (isEmpty(p))
    {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo--];
}

void imprime_pilha(Pilha *p, char *nome)
{
    printf("\n%s: ", nome);
    if (isEmpty(p))
    {
        printf("vazia");
    }
    else
    {
        for (int i = 0; i <= p->topo; i++)
        {
            printf("[%d] ", p->dados[i]);
        }
    }
    printf("\n");
}

int main()
{
    Pilha undo, redo;
    inicializar(&undo);
    inicializar(&redo);
    push(&undo, 1);
    push(&undo, 2);
    push(&undo, 3);

    imprime_pilha(&undo, "Pilha Undo");
    imprime_pilha(&redo, "Pilha Redo");

    printf("\nDesfazendo...\n");
    int acao = pop(&undo);
    if (acao != -1)
        push(&redo, acao);

    acao = pop(&undo);
    if (acao != -1)
        push(&redo, acao);

    imprime_pilha(&undo, "Pilha Undo");
    imprime_pilha(&redo, "Pilha Redo");

    printf("\nRefazendo...\n");
    acao = pop(&redo);
    if (acao != -1)
        push(&undo, acao);

    imprime_pilha(&undo, "Pilha Undo");
    imprime_pilha(&redo, "Pilha Redo");

    printf("\nFazendo nova ação 4 (limpa Redo)\n");
    push(&undo, 4);
    inicializar(&redo);

    imprime_pilha(&undo, "Pilha Undo");
    imprime_pilha(&redo, "Pilha Redo");

    return 0;
}
