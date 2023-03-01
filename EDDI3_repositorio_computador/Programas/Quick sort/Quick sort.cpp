#include <iostream>

using namespace std;

void troca(int X[], int i, int j)
{
	int aux;
	
	aux = X[i];
	X[i] = X[j];
	X[j] = aux;
}

int particao(int X[], int p, int r)
{
	int pivo, i, j;
	pivo = X[(p+r)/2];
	i = p-1;
	j = r+1;
	
	while (i < j)
	{
		do{
			j = j-1;
		}while(X[j] > pivo);
		
		do{
			i = i+1;
		}while(X[i] < pivo);
		
		if(i<j)
			troca(X,i,j);
	}
	return j;
}

void quicksort(int X[], int p, int r)
{
	int q;
	
	if(p < r)
	{
		q = particao(X,p,r);
		quicksort(X,p,q);
		quicksort(X,q+1,r);
	}
}

int main()
{
	int X[10], i;
	
	for(i=0; i<=9; i++)
	{
		cout << "Digite " << i+1 << "numero: ";
		cin >> X[i];
	}
	
	quicksort(X, 0, 9);
	
	cout << endl << "#numeros ordenados: " << endl;
	for(i=0; i<=9; i++)
		cout << i+1 << "numero: " << X[i] << endl;
		
	return 0;
}

