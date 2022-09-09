#include<iostream>
#include<list>
using namespace std;

int main () {
	list<int> fila; // ponteiro para pilha;
	int x; 
	int i;
	
	// ler dados e inserir na pilha 
	for(i=0;i<4;i++) {
		cin >>x;
		fila.push_back(x);
		// na pilha, cada novo numero é colocado na frente do anterior
		//na fila, cada novo numero é colocado depois do anterior
	}
	
	// remover os dados da pilha e ir mostrando
	while(!fila.empty()) {
	x=*fila.begin();
	cout << x << " ";
	fila.pop_front();
	}
	return 0;
}
