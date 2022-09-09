#include<iostream>
#include<iomanip>
using namespace std;

struct treenode {
	int info; // raiz 
	treenode *esq; // sub-arvore esquerda
	treenode *dir; //sub - arvore direita
}; 

typedef treenode *treenodeptr; // definindo uma variavel tipo treenode

void tInsere(treenodeptr &p, int x) {
	if(p==NULL) { // insere na raiz pq vai estar vazio
	p = new treenode; 
	p->info = x;
	p->esq = NULL; 
	p->dir = NULL;
}
	else 
		if(x <p->info) // insere a esquerda
			tInsere(p->esq,x);
		else // insere a direita
			tInsere(p->dir,x); 
}

int main() {
	treenodeptr arvore = NULL; // começa com NULL
	int primo = 0;
	int x=0; // elemento a ser inserido
	while(x!=-1) {
		cin >> x; 
		if(x!=-1) {
		tInsere(arvore,x);
		if(x==2 || x==3 || x==5 || x==7) 
			primo++;
		else if(x>8 && x%3!=0 && x%5!=0 && x%7!=0)
			primo++;
		}
	}
	
		cout << primo << " numeros primos" << endl;
		
		return 0;
}
