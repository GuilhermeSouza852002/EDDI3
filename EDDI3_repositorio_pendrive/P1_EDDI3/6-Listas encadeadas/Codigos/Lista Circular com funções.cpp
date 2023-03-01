#include <iostream>

using namespace std;

typedef struct Noh{
    int numero;
    Noh *proximo; // ponteiro que aponta pra proximo estrutura
} Noh;

typedef struct Lista{
    Noh *inicio, *fim; //ponteiro que aponta para estrutura  de inicio e de final
    int tamanho; // saber o tamanho da lista
} Lista;

int menu()
{
    int opcao;
    do{
        cout<< endl << "Menu de opcoes" << endl;
        cout<< "1 Inserir no inicio da lista" << endl;
        cout<< "2 Inserir no fim da lista" << endl;
        cout<< "3 imprimir toda lista" << endl;
        cout<< "4 remover da lista" << endl;
        cout<< "5 Esvaziar lista" << endl;
        cout<< "6 Sair" << endl;

        cout<<"Digite sua escolha: ";
        cin>> opcao;
        
        if( opcao < 1 || opcao > 6) 
            cout<<"\tEscolha Invalida!"<<endl;
    }while ( opcao < 1 || opcao > 6);

    return opcao;
}

bool eVazia(Lista *lst)
{
    if(lst->inicio == NULL)
        return true;
    return false;
}

void inserirInicio(Lista *lst, int numero)
{
    Noh *novo = new Noh();
    novo->numero = numero;
    
    if(eVazia(lst))
    {
        
        lst->inicio = novo; 
        lst->fim = novo; 
        lst->fim->proximo = lst->inicio;
    }
    else
    {
        novo->proximo = lst->inicio; //novo aponta pro iniicio
        lst->inicio = novo; //inicio aponta pra novo
        lst->fim->proximo = lst->inicio;
    }
    lst->tamanho++;
}


void inserirFim(Lista *lst, int numero)
{
    Noh *novo = new Noh(); //alocacao dinamica
    novo->numero = numero;
        
    if(eVazia(lst))
    {
        lst->inicio = novo; 
        lst->fim = novo; 
        lst->fim->proximo = lst->inicio;
    }
    else
    {
         lst->fim->proximo = novo;
         lst->fim = novo;
         lst->fim->proximo = lst->inicio;
    }
    lst->tamanho++;
}
void imprime(Lista *lst)
{
    cout<< endl << "Tamanho da lista: " << lst->tamanho << endl;
    if(eVazia(lst))
        cout<<"lista vazia!" << endl;
    else
    {
        Noh *pAux = lst->inicio;
        
        do{
            cout<< pAux->numero<< " ";
            pAux = pAux->proximo; //pAux aponta para pAux->proximo
        }while(pAux != lst->inicio);
        cout<< endl << endl;
    }
}
void removerDaLista(Lista *lst, int numero)
{
	int achou;
		
	if(eVazia(lst))
        cout<<"lista vazia!" << endl;
    else
    {
    	
		Noh *pAux = lst->inicio;
		Noh *pAnterior = NULL;
		achou = 0;
		int quantidade = 0;
		while (pAux!=lst->inicio)
		{
			quantidade = quantidade+1;
			pAux = pAux->proximo;
		}
		int elemento = 1;
		
		do
		{
			if(lst->inicio == lst->fim && lst->inicio->numero == numero)
			{
				delete(lst->inicio);
				lst->inicio = NULL;
				achou = achou+1;
			}
			else
			{
				if(pAux->numero == numero)
				{
					achou = achou+1;
					if(pAux == lst->inicio)
					{
						lst->inicio = pAux->proximo;
						lst->fim->proximo = lst->inicio;
						delete(pAux);
						pAux = lst->inicio;
					}
					else if (pAux == lst->fim)
					{
						lst->fim = pAnterior;
						lst->fim->proximo = lst->inicio;
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
			elemento = elemento+1;
		}while(elemento <= quantidade);
		
		if(achou == 0)
			cout<<"Numero nao encontrado";
		else if (achou == 1)
			cout<< "Numero removido 1 vez";
		else
			cout<<"Numero removido" << achou <<"vezes";
	}
}
void esvaziaLista(Lista *lst)
{
	if(eVazia(lst))
        cout<<"lista vazia!" << endl;
    else
    {
    	Noh *pAux = lst->inicio;
    	while(pAux != NULL)
    	{
    		lst->inicio = lst->inicio->proximo;
    		delete(pAux);
    		pAux = lst->inicio;
		}
		delete(lst->fim);
		lst->inicio = NULL;
		cout<<"Lista esvaziada";
	}
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
                cout<< "Digite o numero a ser inserido no inicio da Lista: ";
                cin>> numero;
                inserirInicio(&lista, numero);
            break;

            case 2:
                cout<< "Digite o numero a ser inserido no fim da Lista: ";
                cin>> numero;
                inserirFim(&lista, numero);
            break;

            case 3:
                cout<< "Imprimindo a lista...";
                imprime(&lista);
            break;

            case 4:
                cout<< "Digite o numero a ser removido da Lista: ";
                cin>> numero;
                removerDaLista(&lista, numero);
            break;

            case 5:
                cout<< "Esvaziando a lista...";
                esvaziaLista(&lista);
            break;

            default:
                cout << "Saindo..." << endl;            
        }

    }while(escolha != 6);
}
