#include<iostream> 
#include<cmath> 
using namespace std; 


// função para o primeiro cálculo 

int calc_a(int x) {
	return pow(x,2)*2 + 3*x - 1; 
}

// função para o segundo calculo 

int calc_b(int x) {
	return pow(x,3);
}

// função para o terceiro calculo 

int calc_c(int y) {
	return pow(y,3);
}

int main () {
	int a, b; // variaveis para os calculos nas funções
	cin >> a >> b; 
	
	cout << "a = " << calc_a(a) << endl;
	cout << "b = " << calc_b(a) << endl;
	cout << "c = " << calc_c(b) << endl;
	return 0;
}
