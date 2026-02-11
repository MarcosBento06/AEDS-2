#include <stdio.h>
#define TAM 10


int retorna_pai(int i){    
    return (i - 1) / 2 ;
}

int filho_esq(int i){
    return (2 * i) + 1;
}

int filho_dir(int i){   
    return (2 * i) + 2;
}

void trocar(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;    
}

void min_heapify(int vetor[], int i, int qtd){
    int esq = filho_esq(i);
    int dir = filho_dir(i);
    int menor = i;

    //Verifica se o filho esquerdo existe
    //e se ele é menor que o valor atual considerado menor
    if(esq < qtd && vetor[esq] < vetor[menor]){
        menor = esq;
    }
    //Verifica se o filho direito existe
    //e se ele é menor que o menor atual
    if(dir < qtd && vetor[dir] < vetor[menor]){
        menor = dir;
    }
    //Se o menor não for mais o próprio i, significa que
    //um dos filhos violou a propriedade da min-heap: pai > filho
    //Portanto, troca o pai com o menor filho
    if(menor != i){
        trocar(&vetor[i], &vetor[menor]);
        min_heapify(vetor, menor, qtd); // Chamamos de novo porque o valor que desceu pode estar
                                        // violando a heap com os filhos dele (continua ajustando para baixo)
    }
}


int minHeapRemocao(int vetor[], int i, int *qtd){
    if(*qtd <= 0){
        printf("\n\tArvore está vazia para remover");
        return -1;
    }
    if(*qtd == 1){
        (*qtd)--;
        return vetor[0];
    }

    int raiz = vetor[0];
    vetor[0] = vetor[*qtd - 1];
    (*qtd)--;
    min_heapify(vetor, i, *qtd);

    return raiz;
}



void minheap_insercao(int vetor[], int k, int *qtd){
    if(*qtd == TAM){ //se a qtd for igual ao tamanho máximo não é possível inserir mais
        printf("Não é possível inserir mais");
        return;
    }

    (*qtd)++; // como vai inserir, a qtd aumenta
    int i = *qtd - 1; //coloca o indice i na última posição, pois na heap, é sempre inserido no final
    vetor[i] = k; //última posição do vetor recebe o valor k

    while(i != 0 && vetor[retorna_pai(i)] > vetor[i]){
        //enquanto o elemento não for a raiz e for menor que o pai,
        //troca o elemento com o pai e manter a prorpiedade de min-heap
        trocar(&vetor[retorna_pai(i)], &vetor[i]);
        i = retorna_pai(i); //atualiza o i para o indice do pai e continua subindo
    }
}

void imprimir(int vetor[], int qtd){
    for(int i = 0; i < qtd; i++){
        printf("%d ", vetor[i]);
    }
}

int main(){

    int qtd = 0;
    int vetor[TAM];
    int val;

    minheap_insercao(vetor, 5, &qtd);
    minheap_insercao(vetor, 2, &qtd);
    minheap_insercao(vetor, 4, &qtd);
    minheap_insercao(vetor, 15, &qtd);
    minheap_insercao(vetor, 7, &qtd);
    minheap_insercao(vetor, 3, &qtd);
    minheap_insercao(vetor, 1, &qtd);


    printf("\n\tVetor inicial: ");
    imprimir(vetor, qtd);
    printf("\n");

    //minheap_insercao(vetor, 1, &qtd);
    //minheap_insercao(vetor, 10, &qtd);
    

    //printf("\n\tVetor depois das inserções: ");
    //imprimir(vetor, qtd);
    //printf("\n");

    minHeapRemocao(vetor, 0, &qtd);
    minHeapRemocao(vetor, 0, &qtd);

    printf("\n\tVetor depois das remoções: ");
    imprimir(vetor, qtd);
    printf("\n");


    return 0;
}