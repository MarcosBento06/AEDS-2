#include <stdio.h>
#define TAM 12

typedef struct {
    int chave;
}no;


int busca_bin(no L[], int num, int tam){
    int inf = 0, sup = tam - 1, retorno = -1; // retorna -1 se o número já existir
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

int insere(no L[], int *qtd, int tam, int num){
    if(*qtd < tam){
        if(busca_bin(L, num, *qtd) == -1){
            L[*qtd].chave = num;
            *qtd = *qtd + 1;
            return *qtd;
        }
        return -1; // no caso do número já exitir
    }
    return -2; // no caso da lista cheia
}

no *remover(no L[], int num, int tam ){
    if(tam != 0){
        int indice = busca_bin(L, num, tam);
        if(indice != -1){
            return L[indice].chave;
            
            for(int i = indice; i < tam -1; i++){
                L[i].chave = L[i + 1].chave;
            }
            tam--;
        }
    }
   return NULL;
}



int main() {
    int num;
    no L[TAM] = {{10}, {20}, {30}, {40}, {45}, {47}, {65}};
    int qtd = 7;

    int opcao = -1;

    while(opcao != 0){

        printf("\n\t-------------MENU------------");
        printf("\n\t0. Digite 0 para sair");
        printf("\n\t1. Buscar número");
        printf("\n\t2. Colocar novo número");
        printf("\n\t3. Remover número");
        printf("\n\t4. Imprimir lista");       
        printf("\n\tDigite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao){
        
            case 1: {
        
                printf("\n\tDigite um número: ");
                scanf("%d", &num);

                int resultado = busca_bin(L, num, TAM);

                if (resultado != -1) {
                    printf("\n\tSeu número está na posição: %d\n", resultado + 1);
                } else {
                    printf("\n\tNúmero não encontrado\n");
                }

                break;
            }

           case 2:{

                printf("\n\tDigite um número para inserir: ");
                scanf("%d", &num);

                int resultado = insere(L, &qtd, TAM, num);

                if (resultado == -1) {
                printf("\n\tNúmero já existe na lista.\n");
                } else if (resultado == -2) {
                printf("\n\tLista cheia. Não foi possível inserir.\n");
                } else {
                printf("\n\tNúmero inserido com sucesso.\n");
                }

                break;
            }

            case 3:{

                 printf("\n\tDigite um número para remover: ");
                scanf("%d", &num);

                no *resultado = remover(L, num, TAM);

                if (resultado == NULL) {
                printf("\n\tA lista não possui elementos.\n");
                } else {
                printf("\n\tNúmero %d removido com sucesso.", resultado);
                }
                
                break;
            }

            case 4:{
                printf("\n\tLista atual:\n\t");
                for (int i = 0; i < qtd; i++) {
                    printf("%d ", L[i].chave);
                }
                printf("\n");
                break;
            }

             case 0: {
                printf("\n\tSaindo...\n");
                break;
        }


            default:
               printf("\n\tOpção inválida.\n");
            
        }
    }


    return 0;
}
