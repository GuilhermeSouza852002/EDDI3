#include <iostream>

using namespace std;

typedef struct Noh{
    int numero;
    Noh *proximo; // ponteiro que aponta pra proximo estrutura
    Noh *anterior;
} Noh;

typedef struct Lista{
    Noh *inicio, *fim; //ponteiro que aponta para estrutura  de inicio e de final
    int tamanho; // saber o tamanho da lista
} Lista;

int menu()
{
    int opcao;
    do{
        cout<< "\nMenu de opcoes" << endl;
	        cout<< "1 Inserir na lista" << endl;
	        cout<< "2 Consulta lista do inicio ao fim" << endl;
	        cout<< "3 Consulta lista do fim ao inicio" << endl;
	        cout<< "4 Remover da lista" << endl;
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
void inserirNaLista(Lista *lst, int numero)
{
    Noh *novo = new Noh(); //alocacao dinamica
    novo->numero = numero;
   
    if(eVazia(lst))
    {
    	novo->proximo = NULL;
        novo->anterior = NULL;
		lst->inicio = novo;
    	lst->fim = novo;
    }
    
    else
    {
        Noh *pAux = lst->inicio;
         
        
        do{
           	pAux = pAux->proximo;
        }while(pAux!=NULL && novo->numero > pAux->numero);
        
     	if(pAux == lst->inicio)
     	{
     		novo->proximo = lst->inicio;
            novo->anterior = NULL;
     		lst->inicio->anterior = novo;
     		lst->inicio = novo;
		}
		else if(pAux == NULL)
		{
			lst->fim->proximo = novo;
            novo->anterior = lst->fim;
			lst->fim = novo;
			lst->fim->proximo = NULL;
		}
		else
		{
			novo->proximo = pAux;
            pAux->anterior->proximo = novo;
            novo->anterior = pAux->anterior;
            pAux->anterior = novo;
		}
		 
    }
    
    lst->tamanho++;
}
void consultaInicio(Lista *lst)
{
    cout<< endl << "Tamanho da lista: " << lst->tamanho << endl;
    if(eVazia(lst))
        cout<<"lista vazia!" << endl;
    else
    {
        Noh *pAux = lst->inicio;
        
        while (pAux != NULL)
        {
            cout<< pAux->numero<< " ";
            pAux = pAux->proximo; //pAux aponta para pAux->proximo
        }
        cout<< endl << endl;
    }
}
void consultaFim(Lista *lst)
{
 cout<< endl << "Tamanho da lista: " << lst->tamanho << endl;
    if(eVazia(lst))
        cout<<"lista vazia!" << endl;
    else
    {
        Noh *pAux = lst->fim;
        
        while (pAux != NULL)
        {
            cout<< pAux->numero<< " ";
            pAux = pAux->anterior; //pAux aponta para pAux->proximo
        }
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
		while (pAux!=NULL)
		{
			if(pAux->numero == numero)
			{
				achou = achou+1;
				if(pAux == lst->inicio)
				{
					lst->inicio = pAux->proximo;
                    if(lst->inicio != NULL)
                        { lst->inicio->anterior = NULL;}
					delete(pAux);
					pAux = lst->inicio;
				}
				else if (pAux == lst->fim)
				{
					lst->fim = lst->fim->anterior;
                    lst->fim->proximo = NULL;
					delete(pAux);
					pAux = NULL;
				}
				else
				{
					pAux->anterior->proximo = pAux->proximo;
					pAux->proximo->anterior = pAux->anterior;
                    Noh *pAux2;
                    pAux2 = pAux->proximo;
                    delete(pAux);
					pAux = pAux2;
				}
			}
			else
			{
				pAux = pAux->proximo;
			}
			
		}
		if(achou == 0)
			cout<<"Numero nao encontrado"<< endl;
		else if (achou == 1)
			cout<< "Numero removido 1 vez" << endl;
		else
			cout<<"Numero removido" << achou <<"vezes"<< endl;
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
		cout<<"\nLista esvaziada";
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
                cout<< "Digite o numero a ser inserido na Lista: ";
                _flushall();
				cin>>numero;
                inserirNaLista(&lista, numero);
            break;

            case 2:
                cout<< "Consultando a lista do inicio ao fim";
                consultaInicio(&lista);
            break;

            case 3:
                cout<< "Consultando a lista do fim ao inicio";
                consultaFim(&lista);
            break;

            case 4:
                 cout<< "Digite o numero a ser removido da Lista: ";
                cin>>numero;
                removerDaLista(&lista, numero);
            break;
            
            case 5:
                cout<< "Esvaziando a lista...";
                esvaziaLista(&lista);
            break;

            default:
                cout << "Saindo..." << endl;            
        }

    }while(escolha != 5);
}

