#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct noDaArvore{
	int valor;
	
	struct noDaArvore* esquerda;
	struct noDaArvore* direita;
};

typedef struct noDaArvore no;

void imprimirEmOrdem(no* n);
no* inserir(no* n, int valor);
no* retirar(no* r, int valor);

void imprimirEmOrdem(no* n){
	if(n != NULL){
		imprimirEmOrdem(n-> esquerda);
		printf("%d ", n-> valor);
		imprimirEmOrdem(n-> direita);
	}
}

no* inserir(no* n, int valor){
	if(n == NULL){
		n = (no*)malloc(sizeof(no));
		n-> valor = valor;
		n-> esquerda = NULL;
		n-> direita = NULL;
	}else if(valor < n-> valor){
		n-> esquerda = inserir(n-> esquerda, valor);
	}else if(valor > n-> valor){
		n-> direita = inserir(n-> direita, valor);
	}
	
	return n;
}

no* retirar(no* r, int valor){
	if(r == NULL){
		return NULL;
	}else if(r-> valor > valor){
		r-> esquerda = retirar(r-> esquerda, valor);
	}else if(r-> valor < valor){
		r-> direita = retirar(r-> direita, valor);
	}else{
		if(r-> esquerda == NULL && r-> direita == NULL){
			free(r);
			r = NULL;
		}else if(r-> esquerda == NULL){
			no* aux = r;
			r = r-> direita;
			free(aux);
		}else if(r-> direita == NULL){
			no* aux = r;
			r = r-> esquerda;
			free(aux);
		}
	}
}

void criar(){
	int val = 1;
	no* n = NULL;
	
	while(val != 0){
		printf("Digite os valores p/ Árvore: ");
		scanf("%d", &val);
			
		if(val != 0){
			n = inserir(n, val);
		}
	}	
		
	if(val == 0){
		printf("\nSaída: ");
		imprimirEmOrdem(n);
		printf("\n\n");
	}
}

void remover(){
	int val2 = 0;
	no* n = NULL;

	printf("Digite um valor p/ remover da Árvore: ");
	scanf("%d", &val2);
		
	n = retirar(n, val2);
		
	printf("\nElemento %d removido!!!", val2);
	printf("\n\nNova Saída: ");
	imprimirEmOrdem(n);
	printf("\n\n");
}

void menu(){
	int opc, fim = 1;
	
	while(fim == 1){
		printf("\t\t----------------------------------");
		printf("\n\t\tPARA PARAR O PROGRAMA, DIGITE 0!!!\n");
		printf("\t\t----------------------------------\n\n");
		
		printf("1. Criar Árvore\t\t2. Remover Elemento\nOpção: ");
		scanf("%d", &opc);
		printf("\n");
		
			
		switch(opc){
			case 1:
				criar();
			break;
			
			case 2:
				remover();
			break;
		}
	}
}

int main(void){
	
	setlocale(LC_ALL, "");
	
	menu();
}
