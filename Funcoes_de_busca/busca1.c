#include <stdio.h>
#define TAM 7

typedef struct {
    int chave;
} procuraL;


int busca1(procuraL L[], int num, int tam){
    int i = 0,  retorno = -1;
    while(i <= tam){
        if(L[i].chave == num){
            retorno = i;
            i = tam + 1;
        }
        else{
            i++;
        }
    }
    return retorno;

}



int main() {
    int num;
    procuraL L[TAM + 1] = {{15}, {43}, {12}, {4}, {87}, {9}, {65}};

    printf("\n\tDigite um número: ");
    scanf("%d", &num);

    int resultado = busca1(L, num, TAM);

    if (resultado != -1) {
        printf("\n\tSeu número está na posição: %d\n", resultado + 1);
    } else {
        printf("\n\tNúmero não encontrado\n");
    }

    return 0;
}
