#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore_{
    int valor;
    struct noArvore_ *esq;
    struct noArvore_ *dir;
} noArvore;

noArvore *alocaNo(int valor){
    noArvore *no = (noArvore*) malloc(sizeof(noArvore));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}


noArvore *insere(noArvore *raiz, noArvore *n){
    if(raiz == NULL){
        return n;
    }
    if(raiz->valor > n->valor){
        raiz->esq = insere(raiz->esq, n); 
    }else{
        raiz->dir = insere(raiz->dir, n);
    }
    return raiz;
}

noArvore *busca(noArvore *raiz, int valor){
    if(raiz == NULL || raiz->valor == valor){
        return raiz;
    }
    if(raiz->valor > valor){
        return busca(raiz->esq, valor);
    }else{
        return busca(raiz->dir, valor);
    }
}


noArvore *buscaPai(noArvore *raiz, noArvore *n){
    if(raiz == NULL){
        return NULL;
    }
    if((raiz->esq != NULL && raiz->esq == n) || (raiz->dir != NULL && raiz->dir == n)){
        return raiz;
    }
    if(raiz->valor > n->valor){
        return buscaPai(raiz->esq, n);
    }else{
        return buscaPai(raiz->dir, n);
    }
}

noArvore *removeRaiz(noArvore *r){
    noArvore *p = r;
    noArvore *q = r->esq;
    while(q->dir != NULL){
        p = q;
        q = q->dir;
    }
    p->dir = q->esq;
    q->esq = r->esq;
    q->dir = r->dir;

    return q;
}

noArvore *remove_no(noArvore *raiz, int valor){
    noArvore *n = busca(raiz, valor); //checa se o nó existe
    if(n){
        noArvore *pai = buscaPai(raiz, n); //descobre quem é o nó pai
        if(pai){ //caso tenha o nó pai
            if(pai->dir == n){ //nó a ser removido é o filho a direita
                pai->dir = removeRaiz(n); 
            }else{ //nó a ser removido é o filho a esquerda
                pai->esq = removeRaiz(n);
            }
        }else{ //não possui pai, logo, é o própio nó raiz
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}

void pre_ordem(noArvore *raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d\n", raiz->valor);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);    
}

void em_ordem(noArvore *raiz){
    if(raiz == NULL){
        return;
    }
    em_ordem(raiz->esq);
    printf("%d\n", raiz->valor);
    em_ordem(raiz->dir);
}

void pos_ordem(noArvore *raiz){
    if(raiz == NULL){
        return;
    }
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d\n", raiz->valor);
}


int main(){

    int valor = -1;
    noArvore *raiz = NULL;

    while(valor != 0){
        printf("\n\tDigite um valor para inserir: ");
        scanf("%d", &valor);

        noArvore *no_inserir = alocaNo(valor); 
        raiz = insere(raiz, no_inserir);
    }

    printf("\n\t-----Imprimindo em pré ordem------\n");
    pre_ordem(raiz);


    printf("\n\t-----Imprimindo em-ordem------\n");
    em_ordem(raiz);


    printf("\n\t-----Imprimindo em pós-ordem------\n");
    pos_ordem(raiz);

    printf("\n\tDigite um valor para remover: ");
    scanf("%d", &valor);

    remove_no(raiz, valor);


    return 0;
}


   
