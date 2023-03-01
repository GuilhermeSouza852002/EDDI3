#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;


int main(){
	
	struct Lista
	{
		int num;
		Lista *prox;
	};
	
	Lista *inicio = NULL;
	
	Lista *fim = NULL;
	
	Lista *aux;
	
	Lista *anterior;
	
	int op, numero, achou;
	
	do{
		setlocale(LC_ALL, "Portuguese");
		
		
		cout << "\nMenu de opções\n";
		
			cout << "\n1 - Inserir no início da lista";
			cout << "\n2 - Inserir no fim da lista";
			cout << "\n3 - Consultar toda a lista";
			cout << "\n4 - Remover da lista";
			cout << "\n5 - Esvaziar a lista";
			cout << "\n6 - Sair";
			
			
		cout << "\n\nDigite sua opção: ";
		cin >> op;
		
			if (op < 1 || op > 6)
				cout << "Opção inválida!!";
				
			if (op == 1){
				cout << "Digite o número a ser inserido no início da lista: ";
				Lista *novo = new Lista();
				cin >> novo->num;
				
			if (inicio == NULL){
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
				
			}else{
				novo->prox = inicio;
				inicio = novo;
				
			}
				
			cout << "Número inserido no início da lista!!";
			
			system("cls");
			}
			
			if (op == 2){
				cout << "Digite o número a ser inserido no fim da lista: ";
				Lista *novo = new Lista();
				cin >> novo->num;
				
			if (inicio == NULL){
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
				
			}else{
				fim->prox = novo;
				fim = novo;
				fim->prox = NULL;
				
			}	
			
			cout << "Número inserido no fim da lista!!";
			system("cls");
			}	
			
			if (op == 3){
				if (inicio == NULL){
					cout << "Lista vazia!!";
					
				}else{
					cout << "\nConsultando toda a lista\n";
					aux = inicio;
					
					while (aux != NULL){
						cout << aux->num << "	";
						aux = aux->prox;
						
					}
				}
			}
		
			if (op == 4){
				if (inicio == NULL){
					cout << "Lista vazia!!";
					
				}else{
					cout << "\nDigite o elemento a ser removido: ";
					cin >> numero;
					
					aux = inicio;
					anterior = NULL;
					achou = 0;
					
					while (aux != NULL){
						if (aux->num == numero){
							achou = achou + 1;
							
						if (aux == inicio){
							inicio = aux->prox;
							delete(aux);
							aux = inicio;
							
						}else if (aux == fim){
							anterior->prox = NULL;
							fim = anterior;
							delete(aux);
							aux = NULL;
							
						}else{
							anterior->prox = aux->prox;
							delete(aux);
							aux = anterior->prox;
							
						}	
					}else{
						anterior = aux;
						aux = aux->prox;
					}
					
					
				}
				
				if (achou == 0){
					cout << "Número não encontrado";
					
				}else if (achou == 1){
					cout << "Número removido 1 vez";
					
				}else{
					cout << "Número removido " << achou << "vezes";
					
				}
				system("cls");	
					
			}
			
			if (op == 5){
				if (inicio == NULL){
					cout << "Lista esta vazia!!";
					
				}else{
					aux = inicio;
					
					while (aux != NULL){
						inicio = inicio->prox;
						delete(aux);
						aux = inicio;
						
					}
					cout << "Lista esvaziada";
					
				}
		}		
		getch();
			
	}
		
		
		
}while (op != 6);
	
	
	
	
	
}

