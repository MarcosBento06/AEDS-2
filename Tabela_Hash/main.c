#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

#include "tabela_hash.h"

/*
 * 
 */
int main() {
	hash * ha = cria_hash(1000);

	estudante * e = cria_estudante("Flavio Barbieri\0", 125);
	insere_hash_end_aberto(ha, e);

	e = cria_estudante("Joao das Couves\0", 1125);
	insere_hash_end_aberto(ha, e);

	char * a = busca_hash_end_aberto(ha, 125);
	if (a != NULL)
		printf("Estudante: %s\n", a);
	else
		printf("\n\tAluno nao encontrado.");

	a = busca_hash_end_aberto(ha, 1125);
	if (a != NULL)
		printf("Estudante: %s\n", a);
	else
		printf("Aluno nao encontrado.");

	printf("\n------------------ Encadeamento separado-----------------\n");

	e = cria_estudante("Marcos Bento\0", 6987);
	insere_hash_enc_separado(ha, e);

	char *b = busca_hash_enc_separado(ha, 6987);
	if (b != NULL)
		printf("Estudante: %s\n", b);
	else
		printf("\nAluno nao encontrado.\n");


	libera_hash(ha);
	return 0;
}

