#include<iostream> 
#include<iomanip> 
#include<cmath>
using namespace std; 

int multiplicar(int &x, int y) {
	
	x=2; // a variavel valor esta sendo alterada dentro da função
	return x*y;
	
}

int main () {
	
	int valor=3;
	multiplicar(valor,3); // a variavel valor esta sendo alterada dentro da função
	cout << valor << endl; 
	return 0;
	
}

// sem o uso do &x a saida seria 3, porque na passagem por valor 
// o valor da variavel é copiado para a função, então seu valor 
// nao sofre modificações quando alterado dentro da função 
// multiplicar (valor,3)

// com o uso do &x, a variavel nao é copiada, e sim referenciada
// caso esta sofra alteração dentro da função, seu valor original
// também é alterado
