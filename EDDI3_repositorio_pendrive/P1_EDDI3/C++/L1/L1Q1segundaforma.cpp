/*
1. Fa�a um programa que cadastre o nome e o sal�rio de 5 funcion�rios. Usando um 
m�todo de ordena��o diferente para cada item a seguir, liste todos os dados dos 
funcion�rios das seguintes formas:
a. Em ordem crescente de sal�rio;
b. Em ordem decrescente de sal�rio;
c. Em ordem alfab�tica.
*/

#include <iostream>
#include <string>

using namespace std;

const int Tam = 3;

typedef struct{
	string nome;
	string salario;
}Funcionario;



int main(){
	int i;
	
	Funcionario *ptAux = ptFuncionario;
	
	for(i=0; i<Tam; i++){
		cout << "Digite o nome do funcionario " << i+1 << ": ";
			_flushall();
		cin >> ptAux->nome;
		
		cout << "Qual o salario do funcionario " << i+1 << ": ";
			_flushall();
		cin >> ptAux->salario;
		
		ptAux = ptAux + 1;
		cout << "\n" << endl;
	
	}
	cout << "\n" << endl;
}
}
