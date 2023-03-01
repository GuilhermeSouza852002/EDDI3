#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

typedef struct Noh{
	int numero;
	Noh *proximo;
}Noh;

typedef struct Lista{
	Noh *inicio, *fim;
	int tamanho;
}Lista;

int menu()
{
	int opcao;
	
	do{
		cout << endl << "Menu De Opcoes\n" << endl;
		
		cout << "1-Inserir numero na Pilha" << endl;
		cout << "2-Inserir numero na Fila" << endl;
		cout << "3-Imprimir relatorio" << endl;
		cout << "4-Sair" << endl;
		
		
		cout << "\nDigite sua escolha: ";
		cin >> opcao;
		
		if(opcao < 1 || opcao > 4)
			cout << "\tEscolha invalida" << endl;
	}while(opcao < 1 || opcao > 4);
	
	return opcao;
}


bool eVazia(Lista *lst) // função para verificar se a lista esta vazia
{
	if(lst->inicio == NULL) //se inicio da lista estiver vazia retorna true, caso contrario false
	
		return true;
		
		return false;
}


void cadastrarPilha(Lista *lst, int numero)
{
	Noh *novo = new Noh();
	novo->numero = numero;
	novo->proximo = NULL;
	
		if(eVazia(lst))		//Se a lista estiver vazia
		{
			lst->inicio = novo;
			lst->fim = novo;
			
		}
		else
		{
			novo->proximo = lst->inicio; //Se a lista já possuir um número
			lst->inicio = novo;
			
		}	
		lst->tamanho++;
		
}

void cadastrarFila(Lista *lst, int numero)
{
	Noh *novo = new Noh();
	novo->numero = numero;
	novo->proximo = NULL;
	
		if(eVazia(lst))		//Se a lista estiver vazia
		{
			lst->inicio = novo;
			lst->fim = novo;
			
		}
		else
		{
			lst->fim->proximo = novo; //Se a lista já possuir um número
			lst->fim = novo;
			
		}	
		lst->tamanho++;
}

void Imprimir(Lista *lst)
{
	if(eVazia(lst))
	cout << "Lista Vazia!" << endl;
	
	else
	{
		Noh* pAux = lst->inicio;
		
		while(pAux != NULL)
		{
			cout << pAux->numero << " ";
			pAux = pAux->proximo;
		}
	}
	cout << endl << "Numero de itens: " << lst->tamanho << endl;
	
}

bool procurar(Lista *lst, int num)
{
	if(eVazia(lst))
	cout << "Lista Vazia!" << endl;
	
	else
	{
		Noh* pAux = lst->inicio;
		
		while(pAux != NULL)
		{
			if(pAux->numero == num)
			
				return true;
				
				pAux = pAux->proximo;
		}
	
	}
return false;
}
void relatorios(Lista *fila, Lista *pilha)
{
	Lista soFila, soPilha, ambas;
	
	soFila.inicio = NULL; //Inicio nulo
	soFila.fim = NULL; 	//fim nulo
	soFila.tamanho = 0;
	
	soPilha.inicio = NULL; //Inicio nulo
	soPilha.fim = NULL; 	//fim nulo
	soPilha.tamanho = 0;
	
	ambas.inicio = NULL; //Inicio nulo
	ambas.fim = NULL; 	//fim nulo
	ambas.tamanho = 0;
	
	if(eVazia(fila) || eVazia(pilha))
		cout << "Uma das duas estruturas esta vazia" << endl;
		else
		{
			Noh* filaAux = fila->inicio;
			Noh* pilhaAux = pilha->inicio;
			
			while(filaAux != NULL)
			{
				if(procurar(pilha, filaAux->numero))
					cadastrarFila(&ambas, filaAux->numero);
					
					else
					
					cadastrarFila(&soFila, filaAux->numero);
					
				filaAux = filaAux->proximo;	
					
			}
			filaAux = fila->inicio;
			pilhaAux = pilha->inicio;
			
			while(pilhaAux != NULL)
			{
				if(!procurar(fila, pilhaAux->numero))
					cadastrarFila(&soPilha, pilhaAux->numero);
					
				pilhaAux = pilhaAux->proximo;	
					
			}
			
			cout << "# Numero em ambas estruturas: " << endl;
			Imprimir(&ambas);
			cout << endl;
			
			cout << "# Numero Fila: " << endl;
			Imprimir(&soFila);
			cout << endl;
			
			cout << "# Numero Pilha: " << endl;
			Imprimir(&soPilha);
			cout << endl << endl;
		}
}







int main()
{
	Lista fila, pilha;
	
	//Inicialização da fila
	fila.inicio = NULL; //Inicio nulo
	fila.fim = NULL; 	//fim nulo
	fila.tamanho = 0;
	
	//Inicialização da pilha
	pilha.inicio = NULL;	//Inicio nulo
	pilha.fim = NULL; 		//fim nulo
	pilha.tamanho = 0;
	
	
	int escolha;
	int numero;
	
	do{
		escolha = menu();
		
		switch(escolha)
		{
			case 1 :
				cout << "\nDigite o numero\n";
				cin >> numero;
				
				cadastrarPilha(&pilha, numero);
				
				cout << "\tPilha: ";
				
				Imprimir(&pilha);
				
			break;
			
			case 2 :
				cout << "\nDigite o numero\n";
				cin >> numero;
				
				cadastrarFila(&fila, numero);
				
				cout << "\tFila: ";
				
				Imprimir(&fila);
				
				
			break;
			
			case 3 :
				cout << "Imprimindo relatorio: " << endl;
				relatorios(&fila, &pilha);
				
			break;
			
			case 4 :
				cout << "\nSair\n";
				
			break;
			
			default:
				cout << "Saindo";
				 
		}
	}while(escolha !=4);
}
