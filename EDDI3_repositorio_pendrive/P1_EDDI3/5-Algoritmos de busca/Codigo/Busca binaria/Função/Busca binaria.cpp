#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

typedef struct{
	int Num;
	
}Valores;

const int TAM = 5;

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

void bubbleSort(Valores *ptValores ) //vet que ta no exemplo e o vetor principal
{
	int i, aux;
	
	int troca = 1;
	int n = 1;
			
	while(n <= (TAM) && troca == 1)
	{
		troca = 0;
		
		for(i=0; i<=(TAM-2); i++)
		{
			if(ptValores[i].Num > ptValores[i+1].Num)
			{
				troca =  1;
				aux = ptValores[i].Num; //alterei para que o valor seja passado pro vetor que esta na função main
				ptValores[i].Num = ptValores[i+1].Num;
				ptValores[i+1].Num = aux;
				
			}
		}
		n = n + 1;
		
	}

}

void buscaBinaria(Valores *ptValores)
{
	
	int np, i, inicio, fim, meio, achou;
	
	cout << "Digite o número a ser buscado";
	cin >> np;
		
	achou = 0;
	inicio = 0;
	fim = (TAM-1);
	
	meio = (inicio+fim)/2;
	
	while(inicio <= fim && achou == 0)
	{
		if(ptValores[meio].Num == np)
			achou = 1;
		else {
			if(np < ptValores[meio].Num)
			fim = meio-1;
		else
			inicio = meio+1;
			meio = (inicio+fim)/2;
				
		}
	}
	
	if(achou == 0)
		cout << "Número não encontrado";
		else
		cout << "Número encontrado na posição: "<< meio+1;
}


int main()
{
	Valores ptValores[TAM];
	
	capturaDados(ptValores);
	
	bubbleSort(ptValores);
	
	mostraValores(ptValores);
	
	buscaBinaria(ptValores);
		
}

