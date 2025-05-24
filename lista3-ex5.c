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

int topo(Pilha *p)
{
    if (isEmpty(p))
    {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[p->topo];
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

void ordenar_pilha(Pilha *p)
{
    Pilha aux;
    inicializar(&aux);

    while (!isEmpty(p))
    {
        int temp = pop(p);

        while (!isEmpty(&aux) && topo(&aux) > temp)
        {
            push(p, pop(&aux));
        }

        push(&aux, temp);
    }

    while (!isEmpty(&aux))
    {
        push(p, pop(&aux));
    }
}

int main()
{
    Pilha p;
    inicializar(&p);

    push(&p, 34);
    push(&p, 3);
    push(&p, 31);
    push(&p, 98);
    push(&p, 92);
    push(&p, 23);

    imprime_pilha(&p, "Pilha original");

    ordenar_pilha(&p);

    imprime_pilha(&p, "Pilha ordenada (ordem crescente)");

    return 0;
}
