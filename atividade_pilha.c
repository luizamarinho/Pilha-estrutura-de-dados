#include <stdio.h>
#include <stdlib.h>

#define TAM 10

struct pilha
{
    int dados[TAM];
    int topo;
};

void inicializa(struct pilha *p)
{
    p->topo = 0;
}

int cheia(struct pilha *p)
{
    return p->topo == TAM;
}

int vazia(struct pilha *p)
{
    return p->topo == 0;
}

void push(struct pilha *p, int valor)
{
    if (cheia(p))
    {
        printf("A pilha está cheia! Não é possível empilhar.\n");
    }
    else
    {
        p->dados[p->topo] = valor;
        p->topo++;
        printf("Valor %d empilhado com sucesso.\n", valor);
    }
}

void pop(struct pilha *p)
{
    if (vazia(p))
    {
        printf("A pilha está vazia! Não há o que desempilhar.\n");
    }
    else
    {
        p->topo--;
        int valor = p->dados[p->topo];
        printf("Valor %d desempilhado com sucesso.\n", valor);
    }
}

void imprimir(struct pilha *p)
{
    if (vazia(p))
    {
        printf("A pilha está vazia.\n");
    }
    else
    {
        printf("Pilha:\n");
        for (int i = p->topo - 1; i >= 0; i--)
        {
            printf("[%d] %d\n", i, p->dados[i]);
        }
    }
}

int main()
{
    struct pilha p;
    int opcao, valor;

    inicializa(&p);

    do
    {
        printf("\n=== MENU PILHA ===\n");
        printf("1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
        printf("3 - Imprimir pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a empilhar: ");
            scanf("%d", &valor);
            push(&p, valor);
            break;
        case 2:
            pop(&p);
            break;
        case 3:
            imprimir(&p);
            break;
        case 0:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
