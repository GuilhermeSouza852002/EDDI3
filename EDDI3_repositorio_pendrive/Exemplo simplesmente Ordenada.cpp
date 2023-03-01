#include <iostream>

using namespace std;

typedef struct Noh{
	int numero;
	Noh *proximo; // estutura de ponteiros Noh que aponta para o proximo;
}Noh;

typedef struct Lista{
	Noh *inicio, *fim;
	int tamanho;
}Lista;

int menu()
{
	int opcao;
	
	do{	
	
		cout<< endl <<" MENU DE OPCOES" << endl;
		cout<< "1 - Inserir na lista " << endl;
		cout<< "2 - Imprimir toda lista" << endl;
	    cout<< "3 - Remover da lista" << endl;
	    cout<< "4 - Esvaziar lista" << endl;
	    cout<< "5 - Sair" << endl;
	    
	    cout<< "Digite sua escolha: ";
	    cin>> opcao;
	    
	    if(opcao < 1 || opcao > 5)
	    	cout<< "\nEscolha invalida !!! " << endl;
	}while(opcao < 1 || opcao > 5);
	
	return opcao;
}

bool eVazia(Lista *lst) // função para verificar se a lista esta vazia
{
	if(lst->inicio == NULL) //se inicio da lista estiver vazia
		return true;
	return false;
}

void inserir(Lista *lst, int numero)
{
	Noh *novo = new Noh();
	novo->numero = numero;
	
	if(eVazia(lst))
	{
		novo->proximo = NULL; //proximo paonta para nulo
		lst->inicio = novo; //inicio aponta para o novo numero inserido
		lst->fim = novo; //fim aponta para novo
	}
	else
	{
		Noh *pAnterior = NULL; //ponteiro anteirior aponta para nulo 
		Noh *pAux = lst->inicio;//ponteiro auxiliar aponta para o inicio da lista
		                        
		while(pAux!= NULL && novo->numero < pAux->numero) //laço que move os ponteiros para caminhar na lista 
		{
			pAnterior = pAux; //ponteiro anteirior aponta para auxiliar
			pAux = pAux->proximo; //auxiliar aponta para o proximo
		}
		if(pAnterior == NULL) // se ponteiro anterior aponta para nulo, insere no inicio da lista
		{
			novo->proximo = lst->inicio; //proximo aponta para o numero que esta no inicio da lista
			lst->inicio = novo; //inicio aponta para o novo numero
		}
		else if(pAux == NULL) // se auxiliar aponta para nulo, insere no final da lista
		{
			lst->fim->proximo = novo; //numero no final da lista aponta para novo
			lst->fim = novo; //ponteiro final aponta para novo
		}
		else //insere no meio da lista 
		{
			pAnterior->proximo = novo; //ponteiro anteior aponta para o novo numero
			novo->proximo = pAux; //novo proximo aponta para 
		}
	}
	lst->tamanho++;
}

void imprime(Lista *lst)
{
	if(!eVazia(lst))
	{
		Noh *pAux = lst->inicio;
		
		while( pAux!= NULL)
		{
			cout<< pAux->numero << " "; //impressão do nó atual
			pAux = pAux->proximo;
		}
		cout<< endl <<"Tamanho da lista: " << lst->tamanho <<endl;
		cout<< endl<< endl;
	}
	else
		cout<< endl <<"Lista Vazia....." << endl << endl;
}

void remover(Lista *lst, int numero)
{
	int achou;
		
	if(!eVazia(lst))
	{
			Noh *pAux = lst->inicio;
			Noh *pAnterior = NULL;
			achou = 0;
			while(pAux != NULL)
			{
				if(pAux->numero == numero)
				{
					achou = achou+1;
					if(pAux == lst->inicio)
					{
						lst->inicio = pAux->proximo;
						delete(pAux);
						pAux = lst->inicio;
					}
					else if (pAux == lst->fim)
					{
						lst->fim = pAnterior;
						delete(pAux);
						pAux = NULL;
					}
					else
					{
						pAnterior->proximo = pAux->proximo;
						delete(pAux);
						pAux = pAnterior->proximo;
					}
				}
				else
				{
					pAnterior = pAux;
					pAux = pAux->proximo;
				}
				
			}
			if(achou == 0)
				cout<<"Numero nao encontrado";
			else if (achou == 1)
				cout<< "Numero removido 1 vez";
			else
				cout<<"Numero removido" << achou <<"vezes";
    }
    else
    {
    	cout<<"lista vazia!" << endl;		
	}
}

void esvaziar(Lista *lst)
{
	if(!eVazia(lst))
	{
		Noh *pAux;
		
		while(lst->inicio!=NULL)
		{
			pAux= lst->inicio;
			lst->inicio = lst->inicio->proximo;
			delete(pAux);
		}
	}
	else
		cout << endl << "Lista vazia... " << endl << endl;
}

int main()
{
	Lista lista;
	
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tamanho = 0;
	
	int escolha, numero;
	
	do{
		escolha = menu();
		
		switch(escolha)
		{
			case 1:
				cout<<"Digite o numero a ser inserido na Lista: ";
				cin>> numero;
				inserir(&lista, numero);
			break;
			
			case 2:
				cout<<"Imprimindo Lista..... ";
				imprime(&lista);
			break;
			
			case 3:
				cout<<"Digite o numero a ser removido da Lista: ";
				cin>> numero;
				remover(&lista, numero);
			break;
			
			case 4:
				cout<<"Esvaziando Lista..... ";
				esvaziar(&lista);
			break;
			
			default:
				cout<<"Saindo.....";			
		}
	}while(escolha !=5);
	
}
