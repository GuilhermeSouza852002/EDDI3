#include <iostream.h>
#include <conio.h>

void main()
{
	int X[5];
	int i, j, eleito, menor, pos;
	clrscr();
	
	for(i=0; i<=4; i++)
	{
		cout<<"Digite o "<<i+1<<"numero: ";
		cin>>X[i];
	}
	
	for(i=0; i<=3; i++)
	{
		eleito = X[i];
		menor = X[i+1];
		pos = i + 1;
		
		for(j=i+1; j<=4; j++)
		{
			if(X[j] < menor)
			{
				menor = X[j];
				pos = j;
			}
		}
		if(menor < eleito)
		{
			X[i] = X[pos];
			X[pos] = eleito;
		}
	}
	for(i=0; i<=4; i++)
	{
		cout<<"\n"<<i+1<<"numero: "<<X[i];
	}
	getch();
}
