#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

const int TAM = 5;

typedef struct{
	
	int Num;
	
}Valores;

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
			if(ptValores[i].Num < ptValores[i+1].Num)
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






int main()
{

	Valores ptValores[TAM];
	
	
	capturaDados(ptValores);
	
	cout << "\n====================================================\n";
	mostraValores(ptValores);
	
	cout << "\n====================================================\n";
	bubbleSort(ptValores);
	
	mostraValores(ptValores);
	
	
}
