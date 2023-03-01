#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int X[5];
	int i, j, eleito;
	
	for(i=0; i<=4; i++)
	{
		
	cout << "Digite o "<< i+1 << "° Número: ";
	cin >> X[i];
		
	}	
	
	for(i=1; i<=4; i++)
	{
		eleito = X[i];
		j = i - 1;
		
		while(j >= 0 && X[j] > eleito) //Para crescente > , para decrescente <
		{
			
			X[j+1] = X[j];
			j = j - 1;
			
		}
		
		X[j+1] = eleito;
	}
	
	for(i=0; i<=4; i++)
	{
		cout << "\n"<< i+1 << "°Número: "<< X[i];
	}
}
