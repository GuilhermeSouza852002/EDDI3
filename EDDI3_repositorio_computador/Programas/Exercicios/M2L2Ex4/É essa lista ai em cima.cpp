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

int main(){

	entrada_de_dados;	
	imprime;
	
}
