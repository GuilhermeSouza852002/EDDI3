#include <iostream.h>
#include <conio.h>

void main()
{
	int X[5];
	int i, j, eleito;
	clrscr();
	
	for(i=0; i<=4; i++)
	{
		cout<<"Digite o"<<i+1<<"numero:";
		cin>>X[i];
	}
	
	for(i=1; i<=4; i++)
	{
		eleito = X[i];
		j = i - 1;
		while(j >= 0 && X[j] > eleito)
		{
			X[j+1] = X[j];
			j = j - 1;
		}
		X[j+1] = eleito;
	}
	for(i=0; i<=4; i++)
	{
		cout<<"\n"<<i+1<<"numero:"<<X[i];
	}
	getch();
}
