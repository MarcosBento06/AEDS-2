#include <stdio.h>
#define TAM 5

// Váriaveis Globais
int f = -1; // Inicio da fila
int r = -1; // Retaguarda da fila

typedef struct{
   int chave;
   int valor;
}no;


int insere(no F[], int *f, int *r, no inserir){
    int retorno = -1;

    int prov = ((*r) + 1)  % TAM;
    if(prov != *f){
        *r = prov;
        F[*r] = inserir;
        retorno = *r;     
        if(*f == -1){
            *f = 0;
        }
    }
    return retorno;
}

no* remover(no F[], int *f, int *r){
    if(*f != -1){
        no *removido = &F[*f];
        if(*f == *r){
            *f = -1;
            *r = -1;
        }else{
            *f = ((*f) + 1) % TAM;
        }
        return removido;
    }
    return NULL;
}


int main(){

    no F[TAM];
    int num;
    no inserir;

  
    printf("Digite o número para inserir: ");
    scanf("%d", &num);

    inserir.valor = num;
    int retorno = insere(F, &f, &r, inserir);

    if(retorno == -1){
        printf("Fila cheia");
    }
    else{
        printf("Elemento adiconado a fila");
    }

    no *resultado = remover(F, &f, &r);

    if(resultado == NULL){
         printf("Vazia");
    }else{
         printf("Elemento removido da fila");
    }

    return 0;
}