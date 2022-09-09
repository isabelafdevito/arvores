#include<iostream>
#include<list>
using namespace std;

int main () {
	list<int> pilha; // ponteiro para pilha;
	int x; 
	int i;
	
	// ler dados e inserir na pilha 
	for(i=0;i<4;i++) {
		cin >>x;
		pilha.push_front(x);
	}
	
	// remover os dados da pilha e ir mostrando
	while(!pilha.empty()) {
	x=*pilha.begin();
	cout << x << " ";
	pilha.pop_front();
	}
	return 0;
}
