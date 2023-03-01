#include <iostream>

using namespace std;

const int TAM = 3;

	typedef struct{
		
		string codigo;
		string descricao;
		string preco;
	
}Produto;


void cabecalho()
{
	cout << "-----------------------------";
	cout << "exercicio";
	cout << "-----------------------------";
}

void entrada_de_dados(Produto *vproduto) //Produto vproduto;
                                        // entrada_de_dados(&vproduto)
{
	int i;
	Produto *pAux = vproduto;
	
	for(i=0; i<TAM; i++)
	{
			cout << "Digite o codigo do produto" << i+1 << ": ";
			_flushall();
			getline(cin, pAux->codigo);
			
			cout << "Digite a descricao do produto" << i+1 << ": ";
			_flushall();
			getline(cin, pAux->descricao);
			
			cout << "Digite a descricao do produto" << i+1 << ": ";
			_flushall();
			getline(cin, pAux->preco);
			
		/*	cout << "\tPreco: ";
			cin >> pAux->preco;
			pAux = pAux + 1;
			cout << endl;*/
	}

void troca(Produto *vproduto, int i, int j)
{
	Produto aux;
	
	aux = *(vproduto + i);
	*(vproduto +i) = *(vproduto + j);
	*(vproduto + j) = aux;
}

	int particao(Produto *vproduto, int p, int r)
		{
	
		}

	void quicksort(Produto *vproduto, int p, int r)
		{
	
		}

	void imprime(Produto *vproduto)
	{
	int i;
	Produto pAux = vproduto;
	
	cout << "Produto codigo/\descricao/\preco" << endl;
	
	forr(i=0; i<TAM; i++)
	{
		cout << pAux->codigo << "" << pAux->descricao << "" << pAux->preco << endl;
		pAux = pAux + 1;
	}
	
}
	

	void ordena_lista_produto(Produto *vproduto, int i, int j)
	{
	aux = (vproduto + 1);
	*(vproduto + i) = *(vproduto + 1);
	*(vproduto + )
	
	}
	
	int particao(Produto *vproduto)
	

int pesquisaBR(int *vetor, int inicio, int fim, int busca)
{
	int meio = (inicio + fim)/2;
	
	if(inicio > fim)
		return -1;
		
	if(vetor[meio] == busca)
		return meio;
		
	if(vetor[meio] < busca)
		return pesquisaBR(vetor, meio + 1, fim, busca);
	else
		return pesquisaBR(vetor, inicio, meio - 1, busca);
}

int main()
{
	

	
}
