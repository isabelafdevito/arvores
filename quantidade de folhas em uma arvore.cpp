#include<iostream>
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

// funcao para pesquisar se um elemento esta na arvore
treenodeptr tPesq(treenodeptr p, int x) {
	if(p==NULL) // arvore vazia = elemento n encontrado
		return NULL;
	else 
		if(x==p->info) // elemento encontrado na raiz
			return p;
		else 
			if(x<p->info) // procura na esquerda
				return tPesq(p->esq,x); 
			else // procura na direita
				return tPesq(p->dir,x);
}

// quantidade de folhas em uma arvore
int qnt_folhas(treenodeptr p) {
	if(p==NULL)  // arvore vazia 
		return 0;
	else if(p->esq == NULL && p->dir == NULL) // só tem uma folha {
		return 1;
	else 
		return qnt_folhas(p->esq) + qnt_folhas(p->dir);
}
int main() {
	treenodeptr arvore = NULL; // começa com NULL
	
	int x=0; // elemento a ser inserido
	while(x!=-1) {
		cin >> x; 
		if(x!=-1) {
		tInsere(arvore,x);
		}
	}
		cout << qnt_folhas(arvore) << endl;
		
		
		return 0;
}