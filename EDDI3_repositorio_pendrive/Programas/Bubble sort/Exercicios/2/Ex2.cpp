#include <iostream>

using namespace std;

int main(){
	
	int vet[10], aux=0, i, num, j;
	
		for	(i=0; i<10; i++)
		{
			cout<<"Digite o"<< i+1 << "numero: ";
			cin>>vet[i];
		}
	
		for (j=0; j<=10; j++)
			for(i=0; i<=8; i++)
				if(vet[i]>aux)
				{
					aux=vet[i];
					vet[i]=vet[i+1];
					vet[i+1]=aux;
				}
	
		for (i=0; i<10; i++)
			cout<<vet[i]<< endl;
	
	
	
	
}
