#include <stdio.h>

#define TAM 8

typedef struct
{
    int chave;
} procuraL;

int buscaord(procuraL L[], int num, int tam)
{
    L[tam].chave = num; // Sentinela
    int i = 0;

    while (L[i].chave < num)
    {
        i++;
    }

    if (i == tam || L[i].chave != num)
    {
        return -1; // Não encontrado
    }
    else
    {
        return i; // Índice onde foi encontrado
    }
}

int insere(procuraL L[], int num, int qtd)
{

    if (qtd < TAM)
    {
        if (buscaord(L, num, qtd) == -1)
        {
            L[qtd].chave = num;
            return qtd + 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

int remover(procuraL L[], int num, int qtd)
{

    if (qtd == 0)
    {
        return -1;
    }
    if (qtd != 0)
    {
        int indice = buscaord(L, num, qtd);
        if (indice != -1)
        {
            return L[indice].chave;

            for (int i = indice; i < qtd - 1; i++)
            {
                L[i] = L[i + 1];
            }
        }
        qtd--;
    }
}

int main()
{
    int num, num2, num3;
    int qtd = 5;
    procuraL L[TAM + 1] = {{23}, {34}, {65}, {69}, {123}};

    printf("\n\tDigite um número: ");
    scanf("%d", &num);

    int resultado = buscaord(L, num, TAM);

    if (resultado != -1)
    {
        printf("\n\tSeu número está na posição: %d\n", resultado + 1);
    }
    else
    {
        printf("\n\tNúmero não encontrado\n");
    }

    while (qtd < TAM)
    {

        printf("\n\tDigite um número para adicionar ao vetor: ");
        scanf("%d", &num2);

        int resultado2 = insere(L, num2, qtd);

        if (resultado2 == -1)
        {
            printf("\n\tA lista está cheia");
        }
        else if (resultado2 == 0)
        {
            printf("O elemento já esta na lista");
        }
        else
        {
            qtd = resultado2;
            printf("\n\tAgora a lista tem %d\n elementos", qtd);
        }
    }

    for (int i = 0; i < qtd; i++)
    {
        printf("\t%d\n", L[i].chave);
    }

    printf("\n\tDigite o número que vc deseja remover: ");
    scanf("%d", &num3);

    int resultado3 = remove(L, num3, qtd);

    if (resultado3 == NULL)
    {
        printf("\n\tA lista está vazia ou o elemento que vc deseja remover não existe");
    }
    else
    {
        printf("\n\tO número que vc removeu foi: ", num3);
    }

    for (int i = 0; i < qtd; i++)
    {
        printf("\t%d\n", L[i].chave);
    }

    return 0;
}
