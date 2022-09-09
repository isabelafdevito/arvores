#include<iostream>
#include<list>
using namespace std;

bool encontrar(list<int> lista, int a) {
	int find=0;
	list<int>::iterator p;
	for(p=lista.begin();p!=lista.end();p++) {
		if(*p==a) {
            find=1;	}
	}
	if (find==1) 
		return true;
	else 
		return false;
}

int main () {
	list<int> lista; 
	list<int>::iterator p; // ponteiro para lista;
	int x;

	
	// ler dados e inserir na pilha 
		cin >>x;
	while(x!=0) {
		lista.push_back(x);
		cin >>x;
		// na pilha, cada novo numero é colocado na frente do anterior
		//na lista, cada novo numero é colocado depois do anterior
	}
	int N;
	cin >> N;
	// remover os dados da pilha e ir mostrando
	int res; 
	res=encontrar(lista, N);
	if (res==true)
		cout << "Encontrado" << endl; 
	else 
		cout << "Nao encontrado" << endl;

	return 0;
}
