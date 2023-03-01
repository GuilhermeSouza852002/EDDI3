/*
4. Faça um programa que cadastre 12 produtos. Para cada produto devem ser cadastrados os seguintes dados: código, descrição e preço. 
Use um método de ordenação e em seguida calcule e mostre quantas comparações devem ser feitas para encontrar um funcionário pelo código:
a. Usando busca sequencial.
b. Usando busca binária.
 */

#include <iostream>


using namespace std;

const int TAM = 3;

	typedef struct{
		
		string codigo;
		string descricao;
		string preco;
	
}Produto;

void entrada_de_dados(Produto *vproduto)
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
		
		cout << "\tPreco: ";
		cin >> pAux->preco;
		pAux = pAux + 1;
		cout << endl;
	}
};

void imprime(Produto *vproduto)
	{
	int i;
	Produto *pAux = vproduto;
	
	cout << "Produto codigo/\descricao/\preco" << endl;
	
	for(i=0; i<TAM; i++)
	{
		cout << pAux->codigo << "" << pAux->descricao << "" << pAux->preco << endl;
		pAux = pAux + 1;
	}
};

/*void troca(Produto *vprodutos, int i, int j)
{
	Produto aux;
	
	aux = *(vproduto + i);
	*(vproduto +i) = *(vproduto + j);
	*(vproduto + j) = aux;*/

//metodo que localiza o nº no vetor de forma Recursiva
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
	
	Cout << "Codigo: ";

	return 0;
}
