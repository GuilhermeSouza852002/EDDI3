/*
1. Faça um programa que cadastre o nome e o salário de 5 funcionários. Usando um 
método de ordenação diferente para cada item a seguir, liste todos os dados dos 
funcionários das seguintes formas:
a. Em ordem crescente de salário;
b. Em ordem decrescente de salário;
c. Em ordem alfabética.
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
