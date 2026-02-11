#include <stdio.h>
#define TAM 5

typedef struct {
    int chave;
}no;

int topo = -1; //variável global topo começa com -1, pq a pilha está vazia

int insere(no P[], no inserir, int *topo){
    if(*topo < TAM -1){
        (*topo)++;
        P[*topo] = inserir;
        return *topo;
    }
    return -1;
}

no* remover(no P[], int *topo){
    if(*topo >= 0){
        no *removido = &P[*topo];
        (*topo)--;
        return removido;
    }
    return NULL;

}

int main() {
    int num;
    no P[TAM];
    no inserir;

    while(topo < TAM -1){

        printf("\n\tDigite um número: ");
        scanf("%d", &num);
        inserir.chave = num;

        int resultado = insere(P, inserir, &topo);

        if (resultado == -1) {
            printf("\n\tA pilha está cheia\n");
        } else {
            printf("\n\tNúmero inserido\n");
        }
    }

    no *retorno = remover(P, &topo);

    if(retorno == NULL){
        printf("\n\tA pilha não possui elementos ou o seu número não está nela");
    }else{
        printf("\n\tNúmero %d removido com sucesso", retorno->chave);
    }

    for(int i = topo; i >= 0; i--){
        printf("%d", P[i].chave);
    }

    return 0;
}
