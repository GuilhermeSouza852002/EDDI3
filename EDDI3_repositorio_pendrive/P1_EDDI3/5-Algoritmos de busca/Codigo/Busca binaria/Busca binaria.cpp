#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int X[10], np, i, inicio, fim, meio, achou;
	
	for(i=0; i<=9; i++)
	{
		cout << "Digite o "<< i+1 << "� N�mero: ";
		cin >> X[i];
		
	}
	cout << "Digite o n�mero a ser buscado: ";
	cin >> np;
	
	achou = 0;
	inicio = 0;
	fim = 9;
	meio = (inicio+fim)/2;
	
	while(inicio <= fim && achou == 0)
	{
		if(X[meio] == np)
			achou = 1;
		else {
			if(np < X[meio])
				fim = meio-1;
			else
				inicio = meio+1;
				meio = (inicio+fim)/2;
					
		}	
	}
	if(achou == 0)
		cout << "N�mero n�o encontrado no vetor";
		else
		cout << "N�mero encontrado na posi��o "<< meio+1;
}

	
