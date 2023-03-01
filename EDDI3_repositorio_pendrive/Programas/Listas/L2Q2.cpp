#include <iostream>

using namespace std;

const int TAM = 10;

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
	//declaracao de variaveis
	int vetor[TAM];
	int i, busca, resposta;
	
	//preenchimento do vetor
	for(i=0; i<TAM; i++)
	{
		cout << "Digite o elemento" << i+1 << ": ";
		cin >> vetor[i];
	}
	
	//solicita um nº a ser buscado no vetor
	cout << "Digite um numero a ser buscado: ";
	cin >> busca;
	
	resposta = pesquisaBR(vetor, 0, TAM, busca);
	
	//preenche a saída
	if(resposta == -1)
		cout << "Esse numero nao consta no vetor" << endl << endl;
	else
		cout << "Indice do numero: " << resposta << endl << endl;
		
	return 0;
}
