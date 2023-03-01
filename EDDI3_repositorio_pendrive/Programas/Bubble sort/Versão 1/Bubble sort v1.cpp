#include <iostream.h>
#include <conio.h>

void main()
{
	int X[5], j, i, aux;
	clrcscr();
	
		for(i=0; i<=4; i++)
		{
			cout<<"Digite o "<<i+1<<" numero: ";
			cin>>X[i];
		}
		
		for(j=1; j<=4; j++)
		{
			for(i=4; i>=j; i--)
			{
				if(X[i] > X[i-1])
				{
					aux = X[i];
					X[i] = X[i-1];
					X[i-1] = aux;
				}
			}
		}
		
		for(i=0; i<=4; i++)
		{
			cout<<i+1<<" numero: "<<X[i]<<"\n";
		}
		getch();
}

