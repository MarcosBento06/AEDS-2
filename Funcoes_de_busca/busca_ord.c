#include <stdio.h>
#define TAM 7

typedef struct {
    int chave;
} procuraL;


int busca_ord(procuraL L[], int num, int tam){
    L[tam].chave = num;
    int i = 0;
    while(L[i].chave < num){
        i++;
    }
    if(i == tam || L[i].chave != num){
        return -1;
    }
    return i;
}



int main() {
    int num;
    procuraL L[TAM] = {{10}, {20}, {30}, {40}, {45}, {47}, {65}};

    printf("\n\tDigite um número: ");
    scanf("%d", &num);

    int resultado = busca_ord(L, num, TAM);

    if (resultado != -1) {
        printf("\n\tSeu número está na posição: %d\n", resultado + 1);
    } else {
        printf("\n\tNúmero não encontrado\n");
    }

    return 0;
}
