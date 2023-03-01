#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int X[5], n, i, aux, troca;
	
	for(i=0; i<=4; i++)
	{
		cout << "Digite o "<<i+1<< "° Número: ";
		cin >> X[i];	
	}	
	
	n = 1;
	troca = 1;
	
	while(n <= 5 && troca == 1)
	{
		troca = 0;
		
		for(i=0; i<=3; i++)
		{
			if(X[i] < X[i+1]) // para decrescente < , para crescente >
			{
				troca = 1;
				aux = X[i];
				X[i] = X[i+1];
				X[i+1] = aux;
			}
		}
		n = n + 1;
	}
	
	for(i=0; i<=4; i++)
	{
		cout << i+1 << "° número: "<< X[i] << "\n";
	}
	
}
