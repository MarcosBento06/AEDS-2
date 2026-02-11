
#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int chave;
    int valor;

    struct no_*prox;
}no;

no *ptlista;

void busca_encadeada(int num, no **ant, no **pont){
    *ant = ptlista;
    *pont = NULL;
    no *ptr = ptlista->prox;
    while (ptr != NULL){
        if(ptr->chave < num){
            *ant = ptr;
            ptr = ptr->prox;
        }else{
            if((*ptr).chave == num){
                *pont = ptr;
            }
            ptr = NULL;
        }
    }
}

int insere_encadeada(no *no_inserir){
    int valor_retorno = -1;
    no *ant;
    no *pont;
    busca_encadeada(no_inserir->chave, &ant, &pont);
    if(pont == NULL){
        no_inserir->prox = ant->prox;
        ant->prox = no_inserir;
        valor_retorno = 0;
    }
    return valor_retorno;
}

no* remove_encadeada(int num){
    no *ant, *pont;

    busca_encadeada(num, &ant, &pont);
    if(pont != NULL){
        ant->prox = pont->prox; //Desvincula o nó removido da lista, ou seja o ant vai apontar para onde o pont estava apontando.
        pont->prox = NULL; //Desvincula o nó removido da lista
        return pont;
    }
    return NULL;

    
}

void Imprime(no *lista){
    no *atual = lista->prox; // começa a imprimir após o nó cabeça
   
    while(atual != NULL){
        printf("[chave: %d, valor: %d]", atual->chave, atual->valor);        

        atual = atual->prox; // o ponteiro atual vai andando para frente, enquanto for diferente de nulo.
    } 
     printf("\n");
    
}


int main(){
    int num, valor, num2;

    ptlista = (no*)malloc(sizeof(no));
    ptlista->prox = NULL;
    // ou (*ptlista).prox = NULL, pode fazer isso quando for uma struct
    

    no *no_inserir = (no*)malloc(sizeof(no));
    no_inserir->chave = 2;
    no_inserir->valor = 2;
    no_inserir->prox = NULL;
    ptlista->prox = no_inserir;
            //ou
    /*(*no_inserir).chave = 2;
    (*no_inserir).valor = 2;
    (*no_inserir).prox = NULL;
    (*ptlista).prox = no_inserir;
    */

    no_inserir = (no*)malloc(sizeof(no));
    no_inserir->chave = 7;
    no_inserir->valor = 7;
    no_inserir->prox = NULL;
    ptlista->prox->prox = no_inserir; 
            //ou
    /*(*no_inserir).chave = 7;
    (*no_inserir).valor = 7;
    (*no_inserir).prox = NULL;
    */

    no *ant, *pont;

    printf("\n\tDigite um número: ");
    scanf("%d", &num);

    busca_encadeada(num, &ant, &pont);

    if(pont != NULL){
        printf("\n\tElemento encontrado");
    }
    else{
        printf("\n\tElemento não encontrado");
    }

    printf("\n\tDigite o valor que você deseja inserir: ");
    scanf("%d", & valor);

    no_inserir = (no*)malloc(sizeof(no));
    no_inserir->chave = valor;
    no_inserir->valor = valor;
    no_inserir->prox = NULL;

    int retorno = insere_encadeada(no_inserir);

    if(retorno == 0){
        printf("\n\tElemento inserido");
    }
    else{
        printf("\n\tElemento já existente");
    }

    printf("\n\tDigite o valor que você deseja remover: ");
    scanf("%d", & num2);

    no* retorno2 = remove_encadeada(num2);

    if(retorno2 != NULL){
        printf("\n\tElemento removido");
        free(retorno2); // Libera a memória do nó removido
    }
    else{
        printf("\n\tElemento não encontrado ou lista vazia\n");
    }
    

    printf("\n\tNova lista:");
    Imprime(ptlista);





    
    free(ptlista->prox->prox);  // Libera o segundo nó
    free(ptlista->prox);         // Libera o primeiro nó
    free(ptlista);               // Libera o nó de cabeça (ptlista)






    return 0;
}



