#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

const int TAM = 5;
typedef struct{
	
	int Num;
	
}Valores;

void capturaDados(Valores *ptValores)
{
	int i;
	
	Valores *ptAux = ptValores;	
	
	for(i=0; i<TAM; i++)
	{
		cout << "Digite o "<< i+1 << " Numero: "<< "\n";
		cin >> ptAux->Num;
		
		ptAux = ptAux + 1;
		cout << "\n";
	}
}

void mostraValores(Valores *ptValores)
{
	int i;
	
	Valores *ptAux = ptValores;
	
	for(i=0; i<(TAM); i++)
	{
		cout << i+1 << "° Valores inseridos: "<< ptAux->Num << "\n" << endl;
		ptAux =  ptAux + 1;
	}
}

void BuscaOrdenada(Valores *ptValores)
{
	int i = 0;
	int achou = 0;
	int n;
	
	cout << "Digite o número a se buscado"<< endl;
	cin >> n;
	
	while(i <= (TAM-1) && achou == 0 && n >= ptValores[i].Num)
	{
		if(ptValores[i].Num == n)
			achou = 1;
		
		else
			i++;
	}
	if(achou == 0)
		cout << "Número não encontrado";
	else 
		cout << "Número encontrado na posição: " << i+1 << endl;
		
}

int main()
{
	Valores ptValores[TAM];
	
	capturaDados(ptValores);
	
	mostraValores(ptValores);
	
	BuscaOrdenada(ptValores);
	
}
