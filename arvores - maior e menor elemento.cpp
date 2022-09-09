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
	int maior = -1;
	int menor = 9999;
	int x=0; // elemento a ser inserido
	while(x!=-1) {
		cin >> x; 
		if(x!=-1) {
		tInsere(arvore,x);
		if(x>maior) 
			maior = x;
		if(x<menor) 
			menor = x;
		}
	}	
	
		cout << menor << " e " << maior << endl;
		
		return 0;
}
