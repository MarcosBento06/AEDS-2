#include <stdio.h>
#define TAM 7

typedef struct {
    int chave;
} procuraL;


int busca(procuraL L[], int num, int tam){
    L[tam].chave = num;
    int i = 0;
    while(L[i].chave != num){
        i++;
    }
    if(i != tam){
        return i;
    }
    return -1;
}



int main() {
    int num;
    procuraL L[TAM] = {{15}, {43}, {12}, {4}, {87}, {9}, {65}};

    printf("\n\tDigite um número: ");
    scanf("%d", &num);

    int resultado = busca(L, num, TAM);

    if (resultado != -1) {
        printf("\n\tSeu número está na posição: %d\n", resultado + 1);
    } else {
        printf("\n\tNúmero não encontrado\n");
    }

    return 0;
}
