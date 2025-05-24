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

void remover_pares(Pilha *p)
{
    Pilha auxiliar;
    inicializar(&auxiliar);

    while (!isEmpty(p))
    {
        int valor = pop(p);
        if (valor % 2 != 0)
        {
            push(&auxiliar, valor);
        }
    }

    while (!isEmpty(&auxiliar))
    {
        push(p, pop(&auxiliar));
    }
}

int main()
{
    Pilha p;
    inicializar(&p);

    push(&p, 1);
    push(&p, 2);
    push(&p, 3);
    push(&p, 4);
    push(&p, 5);
    push(&p, 6);
    push(&p, 7);

    imprime_pilha(&p, "Pilha original");

    remover_pares(&p);

    imprime_pilha(&p, "Pilha sem pares");

    return 0;
}
