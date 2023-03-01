#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

typedef struct Arvore{
	
	int numero;
	Arvore *esquerda, *direita;
	
}Arvore;

int menu()
{
	int opcao;
	
	do
	{
		cout << endl << endl << "-----------MENU-----------" << endl << endl;
		
		cout << "1 - Inserir número na Árvore" << endl;
		cout << "2 - Mostrar nohs folha" << endl;
		cout << "3 - Mostrar nohs ancestrais de um noh" << endl;
		cout << "4 - Mostrar nohs descendentes de um noh" << endl;
		cout << "5 - Mostrar noh pai e nohs filhos de um noh" << endl;
		cout << "6 - Sair" << endl;
		
		cout << endl << "Digite a opcao: ";
		cin >> opcao;
		
			if(opcao < 1 || opcao > 6)
			cout << "Opção Inválida." << endl;
	}while(opcao < 1 || opcao > 6);
	
	return opcao;
	
}


bool eVazia(Arvore *arvore)
{
	if(arvore == NULL)
		return true;
		return false;
}

bool nohVazio(Arvore *noh)
{
	if(noh == NULL)
		return true;
		return false;
}

Arvore *inserir(Arvore *arvore, int numero)
{
	if(arvore == NULL)
	{
		arvore = new Arvore();
		arvore->numero = numero;	
		arvore->esquerda = NULL;
		arvore->direita = NULL;
	}
	
	else if(numero < arvore->numero)
		arvore->esquerda = inserir(arvore->esquerda, numero);

	else 
		arvore->direita = inserir(arvore->direita, numero);

	return arvore;
}

void MostrarFolhas(Arvore *arvore)
{
	if(arvore != NULL)
	{
		MostrarFolhas(arvore->esquerda);
			if(arvore->esquerda == NULL && arvore->direita == NULL)
			
		cout << arvore->numero << " ";
		MostrarFolhas(arvore->direita);
	}
}

bool ancestrais(Arvore *arvore, int alvo)
{
	if(arvore == NULL)
		return false;
	
	if(arvore->numero == alvo)
		return true;
	
	if(ancestrais(arvore->esquerda, alvo) || ancestrais(arvore->direita, alvo))
	{
		cout << arvore->numero << " ";
			return true;
		
	}
	
	return false;
	
}

Arvore *procurar(Arvore *arvore, int numero)
{
	Arvore *pAux = NULL;
	
	if(arvore != NULL)
	{
		if(arvore->numero == numero)
			pAux = arvore;
			
		else if(numero < arvore->numero)
			pAux = procurar(arvore->esquerda, numero);
			
		else
			pAux = procurar(arvore->direita, numero);		
	}
	
	return pAux;
	
}

void descendentes(Arvore *arvore, int alvo)
{
	if(arvore != NULL)
	{
		descendentes(arvore->esquerda, alvo);
			if(arvore->numero != alvo)
			
		cout << arvore->numero << " ";
		descendentes(arvore->direita, alvo);
	}
}

Arvore *procurarPai(Arvore *arvore, int numero, Arvore *pai)
{
	Arvore *pAux;
	
	if(arvore != NULL)
	{
		if(arvore->numero == numero)
			return pai;
			
		else if(arvore->numero < numero)
			pAux = procurarPai(arvore->direita, numero, arvore);
			
		else
			pAux = procurarPai(arvore->esquerda, numero, arvore);		
	}
	
	return pAux;
	
}

Arvore *Desalocar(Arvore *arvore)
{
	if(arvore != NULL)
	{
		
		arvore->esquerda = Desalocar(arvore->esquerda);
		arvore->direita = Desalocar(arvore->direita);
		delete arvore;
	}
	return NULL;
}


int main()
{
	setlocale(LC_ALL, "portuguese");

	Arvore *raiz = NULL;
	
	int escolha, numero, achou;
	
	do
	{
		escolha = menu();
		
		switch(escolha)
		{
			case 1:
		
			cout << "Digite o numero: ";
			cin >> numero;
			
			raiz = inserir(raiz, numero);
			cout << "Numero inserido na arvore" << endl;
		
			
			break;
			
			case 2:
		
			if(eVazia(raiz))
				cout << "Arvore vazia" << endl;
				
				else
				{
					cout << "Listando Nohs da folha: " << endl;
					MostrarFolhas(raiz);
					cout << endl;
				}
			
		
			break;

			case 3:
			if(eVazia(raiz))
				cout << "Arvore vazia" << endl;
				
				else
				{
					cout << "Imprimindo asncestrais do noh: " << endl;
					cout << "Digite o noh" << endl;;
					cin >> numero;
					
					ancestrais(raiz, numero);
					cout << endl;
  				}
			break;

			case 4:
				
			if(eVazia(raiz))
				cout << "Arvore vazia" << endl;
				
				else
				{
					cout << "Imprimindo descendentes do noh: " << endl;
					cout << "Digite o noh" << endl;;
					cin >> numero;
					
					Arvore *noh = procurar(raiz, numero);
					
					descendentes(noh, numero);
					cout << endl;
  				}
		
			break;
					
			case 5:
			
			if(eVazia(raiz))
				cout << "Arvore vazia" << endl;
				
				else
				{
					cout << "Imprimindo Pai e seus filhos: " << endl;
					cout << "Digite o noh alvo" << endl;;
					cin >> numero;
					
					Arvore *noh = procurar(raiz, numero);
					
					Arvore *nohPai = procurarPai(raiz, numero, NULL);
					
					cout << "Pai: ";
					if(nohPai != NULL)
						cout << nohPai->numero;
						
					cout << endl;
					
					cout << "Filhos: ";
					//if(noh != NULL)
					{
						
					
					if(noh->esquerda != NULL)
						cout << noh->esquerda->numero << " ";
						
					if(noh->direita != NULL)
						cout << noh->direita->numero << " ";	
						
					cout << endl;
					}
					
					cout << endl;	
					
				}
		
			break;

			

			default:
				cout << endl << "Saindo..." << endl;
		}
		
	}while(escolha != 6);
	
	raiz = Desalocar(raiz);
	
	return 0;
	
	
	
	
}

