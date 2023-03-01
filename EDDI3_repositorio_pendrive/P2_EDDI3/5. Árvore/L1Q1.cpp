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
		cout << "2 - Mostrar todos os numeros" << endl;
		cout << "3 - Mostrar o numero maior" << endl;
		cout << "4 - Mostrar o numero menor" << endl;
		cout << "5 - Mostrar quanto numeros tem na arvore" << endl;
		cout << "6 - Sair" << endl;
		
		cout << endl << "\tCOMANDO: ";
		cin >> opcao;
		
		if(opcao < 1 || opcao > 6)
			cout << "Opção Inválida." << endl;
	}while(opcao < 1 || opcao > 6);
	
	return opcao;
}

bool eVazia(Arvore *pArvore)
{
	if(pArvore == NULL)
		return true;
	return false;
}

Arvore *inserir(Arvore *pArvore, int numero)
{
	if(pArvore == NULL)
	{
		pArvore = new Arvore();
		pArvore->numero = numero;	
		pArvore->esquerda = NULL;
		pArvore->direita = NULL;
	}
	
	else if(numero < pArvore->numero)
		pArvore->esquerda = inserir(pArvore->esquerda, numero);

	else 
		pArvore->direita = inserir(pArvore->direita, numero);

	return pArvore;
}

void MostrarTodos(Arvore *pArvore)
{
	if(pArvore != NULL)
	{
		MostrarTodos(pArvore->esquerda);
		cout << pArvore->numero << " ";
		MostrarTodos(pArvore->direita);
	}
}

void MaiorValor(Arvore *arvore, int *maior)
{
	if(arvore != NULL)
	{
		if(arvore->numero > *maior)
			*maior = arvore->numero;
		MaiorValor(arvore->esquerda, maior);
		MaiorValor(arvore->direita, maior);
	}
}

void MenorValor(Arvore *arvore, int *menor)
{
	if(arvore != NULL)
	{
		if(arvore->numero < *menor)
			*menor = arvore->numero;
		MenorValor(arvore->esquerda, menor);
		MenorValor(arvore->direita, menor);
	}
}

void Contador(Arvore *arvore, int *total)
{
	if(arvore != NULL)
	{
		
		*total = *total + 1;
		Contador(arvore->esquerda, total);
		Contador(arvore->direita, total);
	}
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

	Arvore *raiz = NULL, *aux;
	
	int comando, numero, achou, maior, menor, total;
	
	do
	{
		comando = menu();
		
		switch(comando)
		{
			case 1:
		
			cout << "Digite o numero: ";
			cin >> numero;
			
			maior = menor = numero;
			
			raiz = inserir(raiz, numero);
			cout << "Numero inserido na arvore" << endl;
			
			break;
			
			case 2:
		
			if(eVazia(raiz))
				cout << "Arvore vazia" << endl;
				
				else
				{
					cout << "Listando os elementos da arvore " << endl;
					MostrarTodos(raiz);
					cout << endl;
				}
			break;

			case 3:
			
			if(eVazia(raiz))
				cout << "Arvore vazia" << endl;
				
				else
				{
				 	cout << "Verifica o maior numero " << endl;
				 	MaiorValor(raiz, &maior);
				 	
				 	cout << "Maior valor: " << maior;
				 	cout << endl;
				}
			break;

			case 4:
			
			if(eVazia(raiz))
				cout << "Arvore vazia" << endl;
				
				else
				{
				 	cout << "Verifica o menor numero " << endl;
				 	MenorValor(raiz, &menor);
				 	
				 	cout << "Maior valor: " << menor;
				 	cout << endl;
				 }
			break;
					
			case 5:
			
			if(eVazia(raiz))
				cout << "Arvore vazia" << endl;
				
				else
				{
					cout << "Contando numero " << endl;
					total = 0;
				 	Contador(raiz, &total);
				 	
				 	cout << "Valor total: " << total;
				 	cout << endl;
				}
			break;

			

			default:
				cout << endl << "Saindo..." << endl;
		}
		
	}while(comando != 6);
	
	raiz = Desalocar(raiz);
	
	return 0;
}
