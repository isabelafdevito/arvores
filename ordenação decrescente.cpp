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

treenodeptr tMenor(treenodeptr &raiz) {
	treenodeptr t; 
	
	t = raiz; 
	if(t->esq == NULL) {
		raiz = raiz ->dir; 
		return t;
	}
	else 
		return tMenor(raiz->esq);
}

void tRemove (treenodeptr &raiz, int x) {
	treenodeptr p; 
	
	if(raiz == NULL) {
	}
		
    if(x==raiz->info) {
		p=raiz; 
		if(raiz->esq==NULL) 
			raiz = raiz ->esq; 
		else 
			if(raiz->dir==NULL) 
				raiz = raiz->esq; 
			else {
				p=tMenor(raiz->dir); 
				raiz->info=p->info;
			}
			delete p; 
			tRemove(raiz->dir,x); 	
	}
	else 
		if (x<raiz->info) {
			tRemove (raiz->esq,x); 
		}
		else tRemove(raiz->dir,x);
		
}

void emOrdem(treenodeptr arvore) {
	if(arvore!=NULL) {
		emOrdem(arvore->esq); 
		cout << arvore->info << endl; 
		emOrdem(arvore->dir);
	}
}

int main() {
	treenodeptr arvore = NULL; // começa com NULL
	int x=1; // elemento a ser inserido
	while(x!=0) {
		cin >> x; 
		if(x!=0)
		tInsere(arvore,x);
	}	
	int y;
	cin >> y;
	tRemove(arvore,y);
	emOrdem(arvore); 
		
		
		return 0;
}