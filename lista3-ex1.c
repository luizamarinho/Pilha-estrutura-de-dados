#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 5

typedef struct
{
    int dados[TAMANHO];
    int topo;
} Pilha;

bool isEmpty(Pilha *p)
{
    return p->topo == -1;
}

void inicializar(Pilha *p)
{
    p->topo = -1;
}

void push(Pilha *p, int dado)
{
    if (p->topo == TAMANHO - 1)
    {
        printf("Pilha Cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = dado;
}

int pop(Pilha *p)
{
    if (isEmpty(p))
    {
        printf("Pilha Vazia!\n");
        exit(1);
    }
    int temp = p->dados[p->topo];
    p->topo--;
    return temp;
}

void imprime_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main()
{
    int vetor[TAMANHO] = {10, 20, 30, 40, 50};
    Pilha p;

    inicializar(&p);

    for (int i = 0; i < TAMANHO; i++)
    {
        push(&p, vetor[i]);
    }
    for (int i = 0; i < TAMANHO; i++)
    {
        vetor[i] = pop(&p);
    }

    printf("Vetor invertido:\n");
    imprime_vetor(vetor, TAMANHO);

    return 0;
}
