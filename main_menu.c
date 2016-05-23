#include <stdlib.h>
#include <stdio.h>

typedef struct _contato{
	char nome[40];
	char fone[30];
	struct _contato *ant;
	struct _contato *prox;
} TpContato;

int main() {
	int opcao = 0;

	while (opcao != 5) {
		printf("Menu:\n1 - Criar lista\n2 - Criar vetor\n3 - Radix sort\n4 - Quick sort\n5 - Sair\n");
		scanf("%d", &opcao);
		getchar();

		switch (opcao) {
			case 1:
				printf("Criar lista\n");
				break;
			case 2:
				printf("Criar vetor\n");
				break;
			case 3:
				printf("Radix sort\n");
				break;
			case 4:
				printf("Quick sort\n");
				break;
			case 5:
				printf("Saindo...\n");
				break;
			default:
				printf("Opção inválida!\n");
		}
	}

	return 0;
}