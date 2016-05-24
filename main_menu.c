#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define TAM_VETOR 40
#define MIN_FONE 10000000
#define MAX_FONE 99999999

typedef struct _contato{
	char nome[40];
	char fone[30];
	struct _contato *ant;
	struct _contato *prox;
} TpContato;

void criarVetor(TpContato v[], int tam);
void copiarVetor(TpContato vo[], TpContato vd[], int tam);
void imprimirVetor(TpContato v[], int tam);
void criarLista(TpContato **lista, int tam);
void copiarLista(TpContato **lista_o, TpContato **lista_d);
void imprimirLista(TpContato *lista);

int main() {
	int qtde, opcao = 0;
	TpContato *lista, *lista_op, vetor[TAM_VETOR], vetor_op[TAM_VETOR];

	lista = lista_op = NULL;

	while (opcao != 5) {
		printf("Menu:\n1 - Criar lista\n2 - Criar vetor\n3 - Radix sort\n4 - Quick sort\n5 - Sair\n");
		scanf("%d", &opcao);
		getchar();

		switch (opcao) {
			case 1:
				printf("Criar lista\n");
				printf("Quantos itens a lista terá?\n");
				if (scanf("%d", &qtde)) {
					getchar();
					criarLista(&lista, qtde);
					imprimirLista(lista);
				} else {
					printf("Falha ao obter a quantidade de itens.\n");
				}
				break;
			case 2:
				printf("Criar vetor\n");
				criarVetor(vetor, TAM_VETOR);
				imprimirVetor(vetor, TAM_VETOR);
				break;
			case 3:
				printf("Radix sort\n");
				copiarVetor(vetor, vetor_op, TAM_VETOR);
				copiarLista(&lista, &lista_op);
				// usar lista_op e vetor_op nas operações para manter os originais intactos
				break;
			case 4:
				printf("Quick sort\n");
				copiarVetor(vetor, vetor_op, TAM_VETOR);
				copiarLista(&lista, &lista_op);
				// usar lista_op e vetor_op nas operações para manter os originais intactos
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

void criarVetor(TpContato v[], int tam) {
	int i, num;

	srand(time(NULL));

	for (i = 0; i < tam; i++) {
		num = rand() % tam;
		snprintf(v[i].nome, sizeof v[i].nome, "Fulano %d", num);
		num = rand() % (MAX_FONE - MIN_FONE + 1) + MIN_FONE;
		snprintf(v[i].fone, sizeof v[i].fone, "%d", num);
	}
}

void copiarVetor(TpContato vo[], TpContato vd[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		vd[i] = vo[i];
	}
}

void imprimirVetor(TpContato v[], int tam) {
	int i;

	printf("Vetor:\n\n");

	for (i = 0; i < tam; i++) {
		printf("--------------------\n");
		printf("Nome: %s\n", v[i].nome);
		printf("Fone: %s\n", v[i].fone);
	}

	printf("--------------------\n\n");
}

void criarLista(TpContato **lista, int tam) {
	int i, num, tam_max_fone = MAX_FONE;
	TpContato *temp, *ult = NULL;

	srand(time(NULL));

	// exceção caso seja um numero muito grande de elementos, aumenta o tamanho do telefone
	if (tam > (MAX_FONE - MIN_FONE))
		tam_max_fone = MIN_FONE + tam;

	for (i = 0; i < tam; i++) {
		temp = (TpContato *) malloc(sizeof(TpContato));

		if (temp != NULL) {
			num = rand() % tam;
			snprintf(temp->nome, sizeof temp->nome, "Fulano %d", num);
			
			num = rand() % (tam_max_fone - MIN_FONE + 1) + MIN_FONE;
			snprintf(temp->fone, sizeof temp->fone, "%d", num);

			temp->ant = NULL;
			temp->prox = NULL;

			if (ult == NULL) {
				*lista = ult = temp;
			} else {
				ult->prox = temp;
				temp->ant = ult;
				ult = temp;
			}

		} else {
			// erro de alocação
			return;
		}
	}
}

void copiarLista(TpContato **lista_o, TpContato **lista_d) {
	TpContato *temp, *ult = NULL, *temp_o = *lista_o, *temp_d = *lista_d;

	while (temp_o != NULL) {
		// se a lista destino já está alocada
		if (temp_d != NULL) {
			strcpy(temp_d->nome, temp_o->nome);
			strcpy(temp_d->fone, temp_o->fone);
			temp_o = temp_o->prox;
			temp_d = temp_d->prox;
		} else {
			temp = (TpContato *) malloc(sizeof(TpContato));

			if (temp != NULL) {
				strcpy(temp->nome, temp_o->nome);
				strcpy(temp->fone, temp_o->fone);

				temp->ant = NULL;
				temp->prox = NULL;

				if (ult == NULL) {
					*lista_d = ult = temp;
				} else {
					ult->prox = temp;
					temp->ant = ult;
					ult = temp;
				}

				temp_o = temp_o->prox;
			} else {
				// erro de alocação
				return;
			}
		}
	}
}

void imprimirLista(TpContato *lista) {
	TpContato *teste = lista;

	printf("Lista:\n\n");

	while (teste != NULL) {
		printf("--------------------\n");
		printf("Nome: %s\n", teste->nome);
		printf("Fone: %s\n", teste->fone);
		teste = teste->prox;
	}

	printf("--------------------\n\n");
}