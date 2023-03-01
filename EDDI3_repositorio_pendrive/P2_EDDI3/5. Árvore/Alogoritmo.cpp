#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

typedef struct Arvore{
	
	int numero;
	Arvore *esquerda;
	Arvore *direita;
	
}Arvore;


int menu()
{
	int opcao;
	
	do
	{
		cout << endl << endl << "\tMENU" << endl << endl;
		cout << "1 - Inserir número na Árvore" << endl;
		cout << "2 - Consultar Noh na Árvore" << endl;
		cout << "3 - Consultar toda Árvore: ORDEM" << endl;
		cout << "4 - Consultar toda Árvore: PRÉ-ORDEM" << endl;
		cout << "5 - Consultar toda Árvore: PÓS-ORDEM" << endl;
		cout << "6 - Excluir Noh da Árvore" << endl;
		cout << "7 - Esvaziar Árvore" << endl;
		cout << "8 - Sair" << endl;
		
		cout << endl << "\tCOMANDO: ";
		cin >> opcao;
		
		if(opcao < 1 || opcao > 8)
			cout << "Opção Inválida." << endl;
	}while(opcao < 1 || opcao > 8);
	
	return opcao;
}

//Função eVazia para verificar se a Árvore é vazia ou não
bool eVazia(Arvore *pArvore)
{
	if(pArvore == NULL)
		return true;
	return false;
}


//Função Inserir Número na Arvore
Arvore *Inserir(Arvore *pArvore, int numero)
{
	if(pArvore == NULL)
	{
		pArvore = new Arvore();
		pArvore->numero = numero;	
		pArvore->esquerda = NULL;
		pArvore->direita = NULL;
	}
	
	else if(numero < pArvore->numero)
		pArvore->esquerda = Inserir(pArvore->esquerda, numero);

	else 
		pArvore->direita = Inserir(pArvore->direita, numero);

	return pArvore;
}

Arvore *remover(Arvore *arvore, int numero)
{
	Arvore *pAux1, *pAux2;
	
	if(arvore->numero == numero)
	{
		if(arvore->esquerda == arvore->direita)
		{
			delete arvore;
			return NULL;
		}
		
		else if(arvore->esquerda == NULL)
		{
			pAux1 = arvore->direita;
			delete arvore;
			return pAux1;
			
		}
		
		else if(arvore->direita == NULL)
		{
			pAux1 = arvore->esquerda;
			delete arvore;
			return pAux1;
		}
		
		else
		{
			pAux2 = arvore->direita;
			pAux1 = arvore->direita;
			
			while(pAux1->esquerda != NULL)
				pAux1 = pAux1->esquerda;
				
				pAux1->esquerda = arvore->esquerda;
				delete arvore;
				return pAux2;
		}
	}
	
	else if(arvore->numero < numero)
		arvore->direita = remover(arvore->direita, numero);
		
	else
		arvore->esquerda = remover(arvore->esquerda, numero);
		
	return arvore;	
		
}


int Consultar(Arvore *pArvore, int numero, int achou)
{
	if(pArvore != NULL && achou == 0)
	{
		if(pArvore->numero == numero)
			achou = 1;
			
		else if(numero < pArvore->numero)
			achou = Consultar(pArvore->esquerda, numero, achou);
			
		else
			achou = Consultar(pArvore->direita, numero, achou);
	}
	
	return achou;
}

void ImprimirORDEM(Arvore *pArvore)
{
	if(pArvore != NULL)
	{
		ImprimirORDEM(pArvore->esquerda);
		cout << pArvore->numero << " ";
		ImprimirORDEM(pArvore->direita);
	}
}

void ImprimirPREORDEM(Arvore *pArvore)
{
	if(pArvore != NULL)
	{
		cout << pArvore->numero << " ";
		ImprimirPREORDEM(pArvore->esquerda);
		ImprimirPREORDEM(pArvore->direita);
	}
}

void ImprimirPOSORDEM(Arvore *pArvore)
{
	if(pArvore != NULL)
	{
		ImprimirPOSORDEM(pArvore->esquerda);
		ImprimirPOSORDEM(pArvore->direita);
		cout << pArvore->numero << " ";
	}
}


int main()
{
	setlocale(LC_ALL, "portuguese");

	Arvore *raiz = NULL, *pAux;
	
	int comando, numero, achou;
	
	do
	{
		comando = menu();
		
		switch(comando)
		{
			case 1:
				cout << endl << "\t1 - Inserir número na Árvore" << endl;
				cout << endl << "\tNúmero: ";
				cin >> numero;
				
				raiz = Inserir(raiz, numero);
				
				cout << endl << "\tNúmero inserido na Árvore" << endl;
			break;
			
			case 2:
				cout << endl << "\t2 - Consultar Noh na Árvore" << endl;

				if(eVazia(raiz))
					cout << endl << "Árvore vazia.";
					
				else
				{
					cout << endl << "\tNoh: ";
					cin >> numero;
					
					achou = 0;
					
					achou = Consultar(raiz, numero, achou);
					
					if(achou == 0)
						cout << endl << "\tNúmero não encontrado na Árvore.";
					
					else 
						cout << endl << "\tNúmero encontrado na arvore.";	
				}
			break;

			case 3:
				cout << endl << "\t3 - Consultar toda Árvore: ORDEM" << endl;
				
				if(eVazia(raiz))
					cout << endl << "Árvore vazia.";
				
				else
				{
					cout << "\t";
					ImprimirORDEM(raiz);
					cout << endl << endl;
				}
			break;

			case 4:
				cout << endl << "\t4 - Consultar toda Árvore: PRÉ-ORDEM" << endl;
		
				if(eVazia(raiz))
					cout << endl << "Árvore vazia.";
				
				else
				{
					cout << "\t";
					ImprimirPREORDEM(raiz);
					cout << endl << endl;
				}
			break;
					
			case 5:
				cout << endl << "\t5 - Consultar toda Árvore: PÓS-ORDEM" << endl;

				if(eVazia(raiz))
					cout << endl << "Árvore vazia.";
				
				else
				{
					cout << "\t";
					ImprimirPOSORDEM(raiz);
					cout << endl << endl;
				}
			break;

			case 6:
				if(eVazia(raiz))
					cout << "Arvore vazia" << endl;
					
				else
				{
				cout << "Digite o numero que deseja excluir: ";
				cin >> numero;
				
				achou = 0;
				achou = Consultar(raiz, numero, achou);
				
				if(achou == 0)
					cout << "numero nao encontrado na arvore" << endl;
					
				else
				{
					raiz = remover(raiz, numero);
					cout << "numero excluido da arvore" << endl;	
				}		
			}	
			break;

			case 7:
				cout << endl << "\t7 - Esvaziar Árvore" << endl;
			break;

			default:
				cout << endl << "Saindo...";
		}
		
	}while(comando != 8);
	
	return 0;
}
