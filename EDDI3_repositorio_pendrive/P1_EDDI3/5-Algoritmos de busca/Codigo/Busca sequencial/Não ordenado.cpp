#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int X[10], n, i, achou;
	
	for(i=0; i<=9; i++)
	{
		cout << "Digite o"<< i+1 <<"� N�mero: ";
		cin >> X[i];
		
	}
	cout << "Digite o n�mero a ser procurado: ";
	cin >> n;
	
	achou = 0;
	i = 0;
	
	while(i <= 9 && achou == 0)
	{
		if(X[i] == n)
			achou = 1;
		
		else 
		 	i++; 
		 	
	}
	if(achou == 0)
		cout << "N�mero n�o encontrado no vetor" ;	
		else
		cout << "N�mero encontrado na posi��o: " << i+1;
}
