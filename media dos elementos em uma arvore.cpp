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
	int mediana=0;
	int total=0;
	int x=0; // elemento a ser inserido
	while(x!=-1) {
		cin >> x; 
		tInsere(arvore,x);
		if(x!=-1) {
		mediana+=x;
		total++;
		}
	}
	cout << fixed << setprecision(2);
	cout << "Media: " << 1.0*mediana/total << endl;
	
		
		
		
		return 0;
}