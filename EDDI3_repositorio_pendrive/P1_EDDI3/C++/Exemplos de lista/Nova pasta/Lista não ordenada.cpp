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
		
		
		cout << "\nMenu de op��es\n";
		
			cout << "\n1 - Inserir no in�cio da lista";
			cout << "\n2 - Inserir no fim da lista";
			cout << "\n3 - Consultar toda a lista";
			cout << "\n4 - Remover da lista";
			cout << "\n5 - Esvaziar a lista";
			cout << "\n6 - Sair";
			
			
		cout << "\n\nDigite sua op��o: ";
		cin >> op;
		
			if (op < 1 || op > 6)
				cout << "Op��o inv�lida!!";
				
			if (op == 1){
				cout << "Digite o n�mero a ser inserido no in�cio da lista: ";
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
				
			cout << "N�mero inserido no in�cio da lista!!";
			
			system("cls");
			}
			
			if (op == 2){
				cout << "Digite o n�mero a ser inserido no fim da lista: ";
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
			
			cout << "N�mero inserido no fim da lista!!";
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
					cout << "N�mero n�o encontrado";
					
				}else if (achou == 1){
					cout << "N�mero removido 1 vez";
					
				}else{
					cout << "N�mero removido " << achou << "vezes";
					
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

