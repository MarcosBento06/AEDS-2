#include <stdio.h>
#define TAM 7

typedef struct {
    int chave;
} procuraL;


int busca_bin(procuraL L[], int num, int tam){
    int inf = 0, sup = tam - 1, retorno = -1;
    while(inf <= sup){
        int meio = (inf + sup) / 2;
        if(L[meio].chave == num){
            retorno = meio;
            inf = sup + 1;
        }
        else if(L[meio].chave < num){
            inf = meio + 1;
        }
        else{
            sup = meio - 1;
        }
    }
    return retorno;
}



int main() {
    int num;
    procuraL L[TAM] = {{10}, {20}, {30}, {40}, {45}, {47}, {65}};

    printf("\n\tDigite um número: ");
    scanf("%d", &num);

    int resultado = busca_bin(L, num, TAM);

    if (resultado != -1) {
        printf("\n\tSeu número está na posição: %d\n", resultado + 1);
    } else {
        printf("\n\tNúmero não encontrado\n");
    }

    return 0;
}
