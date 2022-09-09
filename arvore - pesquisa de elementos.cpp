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

treenodeptr tMenor(treenodeptr &raiz) {
	treenodeptr t; 
	
	t=raiz;
	if(t->esq==NULL) {
		raiz=raiz->dir;
		return t;
	}
	else 
		return tMenor(raiz->esq);
}

int tRemove(treenodeptr &raiz, int x) {
	treenodeptr p; 
	
	if(raiz==NULL) {
		return 1;
	}
	if(x==raiz->info) {
		p=raiz;
		if(raiz->esq==NULL) 
			raiz = raiz->dir;
		else 
			if(raiz->dir == NULL) 
				raiz = raiz->esq;
			else{
				p=tMenor(raiz->dir);
				raiz->info = p->info;
			}
			delete p;
			return 0;
	}
	else 
		if(x<raiz->info)
			return tRemove(raiz->esq,x); 
		else 
			return tRemove(raiz->dir,x);
}

void emOrdem (treenodeptr arvore) {
	if(arvore!=NULL) {
		emOrdem(arvore->esq); 
		cout << arvore->info << endl;
		emOrdem(arvore->dir);
	}
}

void tDestruir(treenodeptr &arvore) {
	if(arvore!=NULL) {
		tDestruir(arvore->esq); 
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore=NULL;
}

treenodeptr tPesq(treenodeptr p, int x){
	
	if (p == NULL) // elemento não encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else 
		// procura na sub ´arvore esquerda
		if (x < p->info) 
			return tPesq(p->esq,x);
		// procura na sub ´arvore direita
		else  
			return tPesq(p->dir,x);
}
int main() {
	treenodeptr arvore = NULL; // começa com NULL
	
 
	int x=-1; // elemento a ser inserido
	while(x!=0) {
		cin >> x;
		if(x!=0)  {
		tInsere(arvore,x);
		}
	}
	int y;
	cin >> y; 
	while(tPesq(arvore,y)!=NULL) {
		tRemove(arvore,y);
	}
	emOrdem(arvore);
	tDestruir(arvore);
		
		
		return 0;
}
